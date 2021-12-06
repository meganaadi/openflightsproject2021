
#include "Route.h"

# include <cmath>
#include <string>

using std::string;

int route_util::getDistance(Airport* from, Airport* to) {
    // Reference for this code is taken from https://www.movable-type.co.uk/scripts/latlong.html

    //constants
    double const radiusEarth = 6371 ; // radius in km
    double const PI = atan(1)*4;

    //decomposing first pair
    double lat1 = from->getLatitude();
    double long1 = from->getLongitude();

    //decompoinsing second pair
    double lat2 = to->getLongitude();
    double long2 = to->getLongitude();   
    

    double lat1Rad = lat1 * PI/180;
    double lat2Rad = lat2 * PI/180;
    double deltaLatRad = (lat2 - lat1) * PI/180;
    double deltaLongRad = (long2 - long1) * PI/180;


    double a = (sin(deltaLatRad/2) *sin(deltaLatRad/2))  + cos(lat1Rad) * cos(lat2Rad) * sin(deltaLongRad/2) * sin(deltaLongRad/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return (radiusEarth * c);
}  

string route_util::getRouteCode(string fromCode, string toCode) {
    return fromCode + "_" + toCode;
}


void Route::initValues() {
    codeName = route_util::getRouteCode(fromCode,toCode);
    distance = route_util::getDistance(from,to);
}

Route::Route() {
    fromCode = route_util::INVALID_AIRPORT_CODE;
}

Route::Route(string _fromCode, Airport* _from, 
        string _toCode, Airport* _to) : fromCode(_fromCode), from(_from),
        toCode(_toCode), to(_to) {
    initValues();
}

Route::Route(string _fromCode, Airport* _from, 
        string _toCode, Airport* _to, int _distance) : fromCode(_fromCode), from(_from),
        toCode(_toCode), to(_to), distance(_distance) {
    codeName = route_util::getRouteCode(fromCode,toCode);
}

bool Route::isDomestic() {
    if(from->getCountry() == to->getCountry()) return true;
    return false;
}

string Route::getCodeName() const {
    return codeName;
}

string Route::getFromCode() const {
    return fromCode;
}

Airport* Route::getFrom() const {
    return from;
}

string Route::getToCode() const {
    return toCode;
}

Airport* Route::getTo() const {
    return to;
}

string Route::getLabel() const {
    return label;
}

void Route::setLabel(string _label) {
    label = _label;
}

int Route::getDistance() const {
    return distance;
}

