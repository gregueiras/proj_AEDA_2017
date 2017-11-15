#include "Services.h"
using namespace std;

static int service_no = 0;
static double min_m3 = 2;
static double min_pack = 15;
static double min_shipp = 300;
static double velocity = 100000.0/60.0;


// Constructors/Destructors
//  

Services::Services(Address origin_address, double volume, Address destination_address) : service_id(service_no++) {

	this->origin_address = origin_address;
	this->destination_address = destination_address;

	if (volume > 0)
		this->volume = volume;

	this->distance = calcDistance();

}

Services::Services::Services(Address origin_address, double volume, Address destination_address, Hour initial_hour, Date initial_date, unsigned int days_in_storage)
: service_id(service_no++) {

	this->origin_address = origin_address;
	this->destination_address = destination_address;

	if (volume > 0)
		this->volume = volume;

	this->distance = calcDistance();

	Hour pack_time = auxCalcTimePackaging();
	Hour shipp_time = auxCalcTimeShipping();


	Hour hour_end_pack = initial_hour + pack_time;
	Date date_end_pack = initial_date + pack_time
			+ ((pack_time.getHour() + initial_hour.getHour() + (pack_time.getMinute() + initial_hour.getMinute())/60) / 24);


	Packaging pack(initial_date, initial_hour, date_end_pack, hour_end_pack);
	this->packaging = pack;

	Hour hour_end_shipp = hour_end_pack + shipp_time;
	Date date_end_shipp = date_end_pack + shipp_time
			+ ((shipp_time.getHour() + hour_end_pack.getHour() + (shipp_time.getMinute() + hour_end_pack.getMinute())/60) / 24);


	Shipping shipp(date_end_pack, hour_end_pack, date_end_shipp, hour_end_shipp);
	this->shipping = shipp;

	Hour hour_end_deliv = hour_end_shipp + pack_time;
	Date date_end_deliv = date_end_shipp + days_in_storage + pack_time
			+ ((+ hour_end_shipp.getHour() + (shipp_time.getMinute() + hour_end_shipp.getMinute())/60) / 24);

	Delivery deliv(date_end_shipp + days_in_storage, hour_end_shipp, date_end_deliv, hour_end_deliv);
	this->delivery = deliv;


	this->price = calcPrice(days_in_storage);
}



Services::Services(Address origin_address, double volume, Address destination_address, Packaging packaging, Shipping shipping, Delivery delivery) : service_id(service_no++) {

	this->origin_address = origin_address;
	this->destination_address = destination_address;

	if (volume > 0)
		this->volume = volume;

	this->packaging = packaging;
	this->shipping = shipping;
	this->delivery = delivery;

	this->distance = calcDistance();
	this->price = calcPrice(delivery.getStart_date() - shipping.getDispatch_date());


}

Services::~Services () { }

//  
// Methods
//  
double Services::calcDistance ()   {

	return calculateDistanceBetween2GPS(origin_address.getCoordinates(), destination_address.getCoordinates());

}

double Services::calcPrice (unsigned int days_in_storage)   {

	if (distance > 2000000)
		return (volume*distance/1000*cost_km_m + days_in_storage*cost_day_in_storage*volume)*1.1;
	else
		return volume*distance/1000*cost_km_m + days_in_storage*cost_day_in_storage*volume;

}





// Accessor methods
//  


// Other methods
//  

ostream& operator<< (ostream& o,const Services& c)
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

Hour Services::auxCalcTimePackaging() {
	unsigned int minutes = volume*min_m3 + min_pack;
	unsigned int hours = minutes/60;
	minutes = minutes % 60;

	return Hour(hours, minutes, false);
}

Hour Services::auxCalcTimeShipping() {
	unsigned int minutes = min_shipp + distance/velocity;
	unsigned int hours = minutes/60;
	minutes = minutes % 60;

	return Hour(hours, minutes, false);

}

string Services::toStrComplete() {
	stringstream s1;
	s1 << *this;
	return s1.str();
}

string Services::toStrShort() {
	string s1 = this->getOrigin_address().toStr() + '\n';
	s1 += this->getDestination_address().toStr() + '\n';

	return s1;

}
