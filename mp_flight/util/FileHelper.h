#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>


#include "../Airport.h"
#include "../Route.h"


using std::string;
using std::vector;
using std::unordered_map;


class FileHelper {
    public:
        static unordered_map<string,Airport> getAirportMapByCode(const string fileName, char delim, bool skipMissingIataCode);

        
        static unordered_map<string,Route> getRouteMapByCode(const string fileName, char delim, unordered_map<string,Airport>& airportByCode);

        static vector<vector<string>> getAttributesByLine(const string fileName, char delim);
        static string removeDoubleQuotes(string input);

};


