#include "GPS.h"

// Constructors/Destructors
//  

GPS::GPS (double lat, double lon) {

	if ((lat > 90) || (lat < -90))
		throw GPSInvalidLat(lat);

	if ((lon > 180) || (lat < -180))
		throw GPSInvalidLon(lon);


	this->latitude = lat;
	this->longitude = lon;
}

GPS::~GPS () { }

//  
// Methods
//  


// Accessor methods
//  


// Other methods
//  

void GPS::initAttributes () {
}

double calculateDistanceBetween2GPS(const GPS gps1, const GPS gps2) {
	const double earth_radius = 6371000;

	double p1_lat = auxDegreesToRadians(gps1.getLatitude());
	double p2_lat = auxDegreesToRadians(gps2.getLatitude());

	double delta_lat = auxDegreesToRadians(gps2.getLatitude() - gps1.getLatitude());
	double delta_lon = auxDegreesToRadians(gps2.getLongitude() - gps1.getLongitude());

	double a = sin(delta_lat/2) * sin(delta_lat/2) + cos(p1_lat) * cos(p2_lat) * sin(delta_lon/2) * sin(delta_lon/2);

	return 2 * earth_radius * atan2(sqrt(a), sqrt(1-a));

}


double auxDegreesToRadians(const double degree){
	const double pi = 3.141592653589793;

	return degree*pi/180.0;
}

std::ostream& operator<< (std::ostream& o, const GPS& c)
{
	o << "Latitude: " << c.getLatitude() << "   Longitude: " << c.getLongitude() << std::endl;
	return o;
}


bool operator== (const GPS & c1, const GPS & c2) {

	if ((c1.getLatitude() == c2.getLatitude()) && (c1.getLongitude() == c2.getLongitude()))
		return true;
	else
		return false;
}

bool operator!= (const GPS & c1, const GPS & c2) {

	if (c1 == c2)
		return false;
	else
		return true;

}
