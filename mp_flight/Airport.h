#pragma once


# include <cmath>
#include <unordered_map>
#include <string>

using std::string;
using std::unordered_map;

namespace airport_util {
    bool isValidAirport(string ttype);
}  

class Route;

class Airport {
    public:
        Airport();

        Airport(string _city, string _country, string _iataCode, double _latitude, double _longitude);
        
        void addRoute(Route* route);

        string getCity() const;
        string getCountry() const;
        string getIataCode() const;
        double getLatitude() const;
        double getLongitude() const;

        unordered_map<string,Route*> getRoutes();

    private:
        string city;                   //3rd element
        string country;                //4th element
        string iataCode;               //5th element
        double latitude;               //7th
        double longitude;              //8th
        string transportationType;     //13th  must be "airport"

        unordered_map<string,Route*> routes;
        
};

