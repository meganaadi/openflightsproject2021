#pragma once


# include <cmath>
#include <vector>
#include <unordered_map>
#include <string>

using std::string;
using std::vector;
using std::unordered_map;

namespace airport_util {
    bool isValidAirport(string ttype);

}  

class Route;

class Airport {
    public:
        Airport();

        Airport(string _city, string _country, string _iataCode, double _latitude, double _longitude);
        
        Airport(const Airport & other);

        Airport& operator= (const Airport& other);

        //================================
        /**
         * @brief Add an outbound flight route to this airport
         * This allows for effient traversal
         * @param route 
         */
        void addRoute(Route* route);

        /**
         * @brief Get Map of pointers to outbound routes from this airport
         * 
         * @return unordered_map<string,Route*> 
         */
        unordered_map<string,Route*> getRoutes() const;

        /**
         * @brief Get list of airports with directly connected routes to this airport
         * 
         * @return vector<Airport*> 
         */
        vector<Airport*> getAdjacent() const;

        //==============================

        string getCity() const;
        string getCountry() const;
        string getIataCode() const;
        double getLatitude() const;
        double getLongitude() const;

        void setLabel(string _label);
        string getLabel() const;


    private:
        string city;                   //3rd element
        string country;                //4th element
        string iataCode;               //5th element
        double latitude;               //7th
        double longitude;              //8th
        string transportationType;     //13th  must be "airport"

        string label;

        //to store outbound flight route
        unordered_map<string,Route*> routes;
        
        void copy(const Airport& other);
};
