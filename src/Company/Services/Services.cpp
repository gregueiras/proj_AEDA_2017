#include "Services.h"
using namespace std;

// Constructors/Destructors
//  
static int service_no = 0;

Services::Services(Address origin_address, double volume, Address destination_address, const unsigned int client)
: client_id(client) , service_id(service_no++) {

	this->origin_address = origin_address;
	this->destination_address = destination_address;

	if (volume > 0)
		this->volume = volume;

	this->distance = calcDistance();

}

Services::Services(Address origin_address, double volume, Address destination_address, Packaging packaging, Shipping shipping, Delivery delivery, const unsigned int client)
: client_id(client) , service_id(service_no++) {


	this->origin_address = origin_address;
	this->destination_address = destination_address;

	if (volume > 0)
		this->volume = volume;

	this->packaging = packaging;
	this->shipping = shipping;
	this->delivery = delivery;

	this->distance = calcDistance();
	this->price = calcPrice();


}

Services::~Services () { }

//  
// Methods
//  
double Services::calcDistance ()   {

	return calculateDistanceBetween2GPS(origin_address.getCoordinates(), destination_address.getCoordinates());

}

double Services::calcPrice ()   {

	unsigned int days_in_storage = shipping.getArrival_date().getDay() - delivery.getStart_date().getDay();

	if (distance > 2000000)
		return (volume*distance/1000*cost_km_m + days_in_storage*cost_day_in_storage*volume)*1.1;
	else
		return volume*distance/1000*cost_km_m + days_in_storage*cost_day_in_storage*volume;

}





// Accessor methods
//  


// Other methods
//  

ostream& operator<< (ostream& o,const Services& c) //TODO
{


	  o << "Pickup address: " << endl << c.getOrigin_address() << "Pickup time: between " << c.getPackaging().getStart_date() << "  " << c.getPackaging().getStart_hour() <<
			   " and " << c.getPackaging().getEnd_date() << "  " << c.getPackaging().getEnd_hour() << std::endl;
	  o << "Shipping: " << c.getShipping().getDispatch_date() << "  " << c.getShipping().getDispatch_hour() << " to " << c.getShipping().getArrival_date() << "  "
			  << c.getShipping().getArrival_hour() << std::endl << std::endl;
	  o << "Destination address: " << endl << c.getDestination_address();
	  o << "Delivery between " << c.getDelivery().getStart_date() << "  " << c.getDelivery().getStart_hour() << " and " << c.getDelivery().getEnd_date() << "  "
			  << c.getDelivery().getEnd_hour() << std::endl;
	  o << "Details: " << endl << "Volume: " << c.getVolume() << "m^3   Distance: " << c.getDistance()/1000 << "km   Price: " << c.getPrice() << "€" << std::endl << std::endl;

	  o << endl;


	return o;
}



