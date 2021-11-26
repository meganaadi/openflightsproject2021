# include <limits.h>
#include <iostream>

#include "Airport.h"
#include "Route.h"

# include <cmath>
#include <string>

using std::string;


bool airport_util::isValidAirport(string ttype) {
    if(ttype == "airport") return true;
    return false;
}

Airport::Airport() {
    iataCode = route_util::INVALID_AIRPORT_CODE;
}

Airport::Airport(string _city, string _country, string _iataCode, double _latitude, double _longitude) :
    city(_city), country(_country), iataCode(_iataCode),
    latitude(_latitude), longitude(_longitude)
{
    routes = unordered_map<string,Route*>();
}

Airport::Airport(const Airport & other) {
    //std::cout << "Airport:: copy constructor called!" << std::endl;
    copy(other);
}

Airport& Airport::operator= (const Airport& other) {
    //std::cout << "Airport:: Assignment  operator called!" << std::endl;
    copy(other);
    return *this;
}

void Airport::copy(const Airport& other) {
    city = other.getCity();
    country = other.getCountry();
    iataCode = other.getIataCode();
    latitude = other.getLatitude();
    longitude = other.getLongitude();

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

vector<Airport*> Airport::getAdjacent() const {
    unordered_map<string,Route*>::const_iterator iter = routes.begin();
    vector<Airport*> adjacent;
    for(; iter != routes.end(); iter++) {
        adjacent.push_back(iter->second->getTo());
    }
    return adjacent;
}

unordered_map<string,Route*> Airport::getRoutes() const {
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


