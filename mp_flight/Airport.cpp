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
    std::cout << "In Airport::addRoute(...); Route Code Name: " << codeName << std::endl;
    unordered_map<string,Route*>::iterator lookup = routes.find(codeName);
    if(lookup == routes.end()) {
        //not there so add it
        routes[codeName] = route;
    }
}

vector<Airport*> Airport::getAdjacent(bool directed) const {
    std::cout << "In Airport::getAdjacent(); This node: " << iataCode << std::endl;
    unordered_map<string,Route*>::const_iterator iter = routes.begin();
    vector<Airport*> adjacent;
    for(; iter != routes.end(); iter++) {
        Route * rp = iter->second;
        Airport* ap = rp->getTo();
        string airportCode = ap->getIataCode();
        std::cout << "Current BFS neightbor: " << airportCode << std::endl;
        if(!directed && getIataCode() == airportCode) {
            ap = rp->getFrom(); //handling directed graph
            std::cout << "Reversing with: " << ap->getIataCode() << std::endl;
        }
        adjacent.push_back(ap);
    }
    return adjacent;
}

vector<Airport*> Airport::getAdjacent() const {
    return getAdjacent(true);
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


void Airport::setLabel(string _label) {
    label = _label;
}

string Airport::getLabel() const {
    return label;
}
