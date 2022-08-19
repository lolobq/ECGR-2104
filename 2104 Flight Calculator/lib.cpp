#include <cmath>
#include "lib.h"

//Uses the haversine formula to return the distance in miles between 2 latitude/longitude points
double haversine(double lat1, double long1, double lat2, double long2, double radius){
    double sinSquaredLatitude = pow(sin((lat2-lat1)/2), 2);
    double sinSquaredLongitude = pow(sin((long2-long1)/2), 2);
    return 2 * radius * asin(sqrt(sinSquaredLatitude + (cos(lat1) * cos(lat2) * sinSquaredLongitude)));
}

//Returns the flight time in hours -> calculated from the distance (miles) / speed (mph)
double getFlightTime(double distance, double speed){
    return distance / speed;
}