#include "Services.h"
using namespace std;


double Services::min_m3 = 2;
double Services::min_pack = 15;
double Services::min_shipp = 300;
double Services::velocity = 100000.0/60.0;
unsigned int Services::service_no = 1;
double Services::cost_km_m3 = 0.5;
double Services::cost_day_in_storage = 2;

// Constructors/Destructors
//  

Services::Services(Address origin_address, double volume, Address destination_address) : service_id(service_no++) {

	this->origin_address = origin_address;
	this->destination_address = destination_address;

	if (volume > 0)
		this->volume = volume;

	this->distance = calcDistance();
	this->visibility = true;

}

Services::Services(Address origin_address, double volume, Address destination_address, Hour initial_hour, Date initial_date, unsigned int days_in_storage)
: service_id(service_no++) {

	this->origin_address = origin_address;
	this->destination_address = destination_address;

	if (volume > 0)
		this->volume = volume;

	this->distance = calcDistance();
	this->visibility = true;

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

	this->visibility = true;

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
		return (volume*distance/1000*cost_km_m3 + days_in_storage*cost_day_in_storage*volume)*1.1;
	else
		return volume*distance/1000*cost_km_m3 + days_in_storage*cost_day_in_storage*volume;

}





// Accessor methods
//  


// Other methods
//  

ostream& operator<< (ostream& o,const Services& c)
{


	o << "Endereco de Origem: " << endl << c.getOrigin_address() << "Recolha: entre " << c.getPackaging().getStart_date() << " " << c.getPackaging().getStart_hour() <<
			" e " << c.getPackaging().getEnd_date() << "  " << c.getPackaging().getEnd_hour() << std::endl;
	o << "Expedicao: " << c.getShipping().getDispatch_date() << "  " << c.getShipping().getDispatch_hour() << " ate " << c.getShipping().getArrival_date() << "  "
			<< c.getShipping().getArrival_hour() << std::endl << std::endl;
	o << "Endereco de Destino: " << endl << c.getDestination_address();
	o << "Entrega entre " << c.getDelivery().getStart_date() << "  " << c.getDelivery().getStart_hour() << " e " << c.getDelivery().getEnd_date() << "  "
			<< c.getDelivery().getEnd_hour() << std::endl;
	o << "Detalhes: " << endl << "Volume: " << c.getVolume() << "m^3   Distancia: " << c.getDistance()/1000 << "km   Preco: " << c.getPrice() << "€" << std::endl << std::endl;

	o << endl;


	return o;
}



Hour Services::auxCalcTimePackaging() {
	unsigned int minutes = (int)volume*(int)min_m3 + (int)min_pack;
	unsigned int hours = minutes/60;
	minutes = minutes % 60;

	return Hour(hours, minutes, false);
}

Hour Services::auxCalcTimeShipping() {
	unsigned int minutes = (int)min_shipp + (int)distance/ (int)velocity;
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
	string s1 = this->getPackaging().getStart_date().toStr();
	s1 += "to";
	s1 += this->getDelivery().getEnd_date().toStr();

	return s1;

}

bool Services::isBetweenDates(const Date& d1, const Date& d2) {

	Date d3 = d1, d4 = d2;
	if (d1 > d2)
	{
		d4 = d1;
		d3 = d2;
	}
	if ( (this->packaging.getStart_date() > d3) && (this->delivery.getEnd_date() < d4) )
		return true;
	else
		return false;
}

bool Services::isBetweenVolume(const double& d1, const double& d2) {

	double d3 = d1, d4 = d2;
	if (d1 > d2)
	{
		d4 = d1;
		d3 = d2;
	}

	if (this->getVolume() > d3 && this->getVolume() < d4)
		return true;
	else
		return false;
}

bool Services::isBetweenDistance(const double& d1, const double& d2) {

	double d3 = d1, d4 = d2;
	if (d1 > d2)
	{
		d4 = d1;
		d3 = d2;
	}

	if (this->getDistance() > d3 && this->getDistance() < d4)
		return true;
	else
		return false;
}

bool Services::isBetweenPrice(const double& d1, const double& d2) {

	double d3 = d1, d4 = d2;
	if (d1 > d2)
	{
		d4 = d1;
		d3 = d2;
	}

	if (this->getPrice() > d3 && this->getPrice() < d4)
		return true;
	else
		return false;
}

bool Services::isBetweenID(const unsigned int& d1, const unsigned int& d2) {

	unsigned int d3 = d1, d4 = d2;
	if (d1 > d2)
	{
		d4 = d1;
		d3 = d2;
	}

	if (this->getId() > d3 && this->getId() < d4)
		return true;
	else
		return false;
}

