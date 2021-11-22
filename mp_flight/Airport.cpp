#include "Airport.h"
#include "Route.h"

# include <cmath>
#include <string>

using std::string;


bool airport_util::isValidAirport(string ttype) {
    if(ttype == "airport") return true;
    return false;
}

Airport::Airport() {}

Airport::Airport(string _city, string _country, string _iataCode, double _latitude, double _longitude) :
    city(_city), country(_country), iataCode(_iataCode),
    latitude(_latitude), longitude(_longitude)
{
    routes = unordered_map<string,Route*>();
}

void Airport::addRoute(Route* route) {
    //see if it's present
    string codeName = route->getCodeName();
    unordered_map<string,Route*>::iterator lookup = routes.find(codeName);
    if(lookup == routes.end()) {
        //not there so add it
        routes[codeName] = route;
    }
}

unordered_map<string,Route*> Airport::getRoutes() {
    return routes;
}

string Airport::getCity() const {
    return city;
}

string Airport::getCountry() const {
    return country;
}

string Airport::getIataCode() const {
    return iataCode;
}

double Airport::getLatitude() const {
    return latitude;
}

double Airport::getLongitude() const {
    return longitude;
}


