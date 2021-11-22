#include "FileHelper.h"
#include "../Airport.h"
#include "../Route.h"
#include "../Graph.h"


#include <fstream>
#include <iostream>
#include <sstream>


using std::string;
using std::vector;
using std::ifstream;



string FileHelper::removeDoubleQuotes(string input) {
    unsigned int len = input.length();
    if(len == 0) return "";
    int start = input[0] == '"' ? 1 : 0;
    int end = input[len-1] == '"' ? len-1-start : len-start;
    return input.substr(start,end);
}


vector<vector<string>> FileHelper::getAttributesByLine(const string fileName, char delim) {
    vector<vector<string>> attributesByLine = vector<vector<string>>();
    ifstream inputFile(fileName);
    string line;
    if(inputFile.is_open()) {
        //get line
        while(getline(inputFile, line)) {
            vector<string> attributes;
            std::stringstream sstream(line);
            //get comma separated values
            while (sstream.good()) {
                string s;
                std::getline(sstream, s, delim);
                attributes.push_back(removeDoubleQuotes(s));    //remove doule quotes
            }
            attributesByLine.push_back(attributes);
        }
    }
    std::cout << "Total Number of Input lines: " << attributesByLine.size()  << std::endl;
    return attributesByLine;
}

std::unordered_map<string,Airport> FileHelper::getAirportMapByCode(const string fileName, char delim, bool skipMissingIataCode) {
    std::cout << "Entering: getAirportMapByCode(...)" << std::endl;
    vector<vector<string>> attributesByLine = getAttributesByLine(fileName,delim);

    unordered_map<string,Airport> airportMapByCode = unordered_map<string,Airport>();
    airportMapByCode.reserve(1.4 * attributesByLine.size());
    for(vector<string> attributes : attributesByLine) {
        //std::cout << "Size of attributes: " << attributes.size() << std::endl;
        if(attributes.size() < 13) continue;
        string ttype = attributes[12];
        //std::cout << "Type of Terminal: " << attributes[12] << std::endl;
        //int c = ttype.compare("airport");
        //std::cout << "Compare result: " << c << std::endl;
        if(airport_util::isValidAirport(ttype)) {
            string iataCode =  attributes[4];
            if(iataCode.length() <3) {
                if(!skipMissingIataCode) iataCode = attributes[5];
            }
            if(iataCode.length() >= 3) {
                airportMapByCode[iataCode]  = Airport(attributes[2],attributes[3],iataCode,
                    std::stod(attributes[6]), 
                    std::stod(attributes[7]) );
            }
        }
    }
    std::cout << "Total Number of Airports: " << airportMapByCode.size()  << std::endl;
    return airportMapByCode;
}


std::unordered_map<string,Route> FileHelper::getRouteMapByCode(const string fileName, char delim, unordered_map<string,Airport>& airportByCode) {
    std::cout << "Entering: getRouteMapByCode(...)" << std::endl;
    //read csv
    vector<vector<string>> attributesByLine = getAttributesByLine(fileName,delim);

     unordered_map<string,Route> routes = unordered_map<string,Route>();
     routes.reserve(1.4 * attributesByLine.size());
    for(vector<string> attributes : attributesByLine) {
        if(attributes.size() < 5) continue;
        //get source and destination
        string fromCode = attributes[2];
        string toCode  = attributes[4];
        //if this is already in there - nothig to do
        string routeCode = route_util::getRouteCode(fromCode,toCode);
        unordered_map<string,Route>::iterator routeLookup = routes.find(routeCode);
        if(routeLookup != routes.end()) continue;

        unordered_map<string,Airport>::iterator lookup = airportByCode.find(fromCode);
        if(lookup != airportByCode.end()) {
            Airport* from = &(lookup->second);
            lookup = airportByCode.find(toCode);
            if(lookup != airportByCode.end()) {
                Airport* to = &(lookup->second);
                string routeCodeName = route_util::getRouteCode(fromCode,toCode);
                routes[routeCodeName] = Route(fromCode,from,toCode,to);
                from->addRoute(&routes.at(routeCodeName));
            }
        }
        
    }
    std::cout << "Total Number of Routes: " << routes.size()  << std::endl;
    return routes;
}