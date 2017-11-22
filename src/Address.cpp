#include "Address.h"
using namespace std;

// Constructors/Destructors
//  


Address::Address(string street, string country, string city, string county, unsigned int door_number, double lat, double lon)
{
	this->street = street;
	this->country = country;
	this->city = city;
	this->county = county;
	this->door_number = door_number;
	setCoordinates(lat, lon);
}

Address::Address () {
	this->street = "";
	this->country = "";
	this->city = "";
	this->county = "";
	this->door_number = 0;
	setCoordinates(0, 0);
}

Address::~Address () { }

Address::Address(string street, string country, string city, string county, unsigned int door_number) {
	this->street = street;
	this->country = country;
	this->city = city;
	this->county = county;
	this->door_number = door_number;
	cityToGPS();
}

//  
// Methods
//  


// Accessor methods
//  


// Other methods
//  

void Address::initAttributes () {
}


bool Address::cityToGPS()
{
	string city = this->city;

	vector <pair <string, GPS>> city_gps;
	city_gps.push_back(make_pair("Aveiro", GPS(40.63987916844782, -8.654651641845703)));
	city_gps.push_back(make_pair("Beja", GPS(38.01523440990023, -7.862091064453125)));
	city_gps.push_back(make_pair("Braga", GPS(41.54507512972933, -8.426685333251953)));
	city_gps.push_back(make_pair("Bragança", GPS(41.80580559843144, -6.756677627563477)));
	city_gps.push_back(make_pair("Castelo Branco", GPS(39.819546157310086, -7.495851516723633)));
	city_gps.push_back(make_pair("Coimbra", GPS(40.20169046802998, -8.4100341796875)));
	city_gps.push_back(make_pair("Évora", GPS(38.5705822976803, -7.912559509277344)));
	city_gps.push_back(make_pair("Faro", GPS(37.01913878493987, -7.930455207824707)));
	city_gps.push_back(make_pair("Guarda", GPS(40.53819923863684, -7.266168594360352)));
	city_gps.push_back(make_pair("Leiria", GPS(39.74943369178247, -8.807601928710938)));
	city_gps.push_back(make_pair("Lisboa", GPS(38.72127798661635, -9.13839340209961)));
	city_gps.push_back(make_pair("Portalegre", GPS(39.29664604835778, -7.428560256958008)));
	city_gps.push_back(make_pair("Porto", GPS(41.156944322795525, -8.628902435302734)));
	city_gps.push_back(make_pair("Santarém", GPS(39.23610907709813, -8.685894012451172)));
	city_gps.push_back(make_pair("Setúbal", GPS(38.525405818058374, -8.89068603515625)));
	city_gps.push_back(make_pair("Viana do Castelo", GPS(41.69166168890467, -8.834123611450195)));
	city_gps.push_back(make_pair("Vila Real", GPS(41.300507734441474, -7.742185592651367)));
	city_gps.push_back(make_pair("Viseu", GPS(40.65628988195707, -7.911872863769531)));

	//binary_search(city_gps.begin(), city_gps.end(), city, auxSearch);

	for (unsigned int i = 0; i < city_gps.size(); i++)
	{
		if (city == city_gps.at(i).first)
		{
			this->setCoordinates(city_gps.at(i).second);
			return true;
		}
	}

	return false;

}

bool operator== (const Address & c1, const Address & c2)
{

	if ((c1.getStreet() == c2.getStreet() ) && (c1.getCoordinates() == c2.getCoordinates()) && (c1.getStreet() == c2.getStreet()) && (c1.getCountry() == c2.getCountry())
			&& (c1.getCity() == c2.getCity()) && (c1.getCounty() == c2.getCounty()) && (c1.getDoor_number() == c2.getDoor_number()))
		return true;
	else
		return false;
}

bool operator !=(const Address & c1, const Address & c2) {

if (c1 == c2)
	return false;
else
	return true;
}


ostream& operator<< (ostream& o, const Address& c)
{
	o << c.getStreet() << ", " << c.getDoor_number() << endl;
	o << c.getCity() << ", " << c.getCounty() << ", " << c.getCountry() << endl;
	o << c.getCoordinates() << endl;
	return o;
}

string Address::toStr() {
	ostringstream s1;
	s1 << *this;

	return s1.str();

}

//bool auxSearch(const string city1,const pair<string, GPS> city2)
//{
//	return (city1 == city2.first);
//}
