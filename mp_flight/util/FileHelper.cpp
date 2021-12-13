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
    vector<vector<string>> attributesByLine = vector<vector<string>>();     //return payload
    ifstream inputFile(fileName);                                           //open file
    string line;
    if(inputFile.is_open()) {
        //get line
        while(getline(inputFile, line)) {
            vector<string> attributes;
            std::stringstream sstream(line);        //create a string stream tp parse 
            //get comma separated values
            while (sstream.good()) {
                string s;
                std::getline(sstream, s, delim);                //read everything until delim
                attributes.push_back(removeDoubleQuotes(s));    //remove doule quotes
            }
            attributesByLine.push_back(attributes);
        }
    }
    std::cout << "Total Number of Input lines: " << attributesByLine.size()  << std::endl;
    return attributesByLine;
}

/**
 * @brief 
 * Airport ID	Unique OpenFlights identifier for this airport.
 * Name	Name of airport. May or may not contain the City name.
 * City	Main city served by airport. May be spelled differently from Name.
 * Country	Country or territory where airport is located. See Countries to cross-reference to ISO 3166-1 codes.
 * IATA	3-letter IATA code. Null if not assigned/unknown.
 * ICAO	4-letter ICAO code. Null if not assigned.
 * Latitude	Decimal degrees, usually to six significant digits. Negative is South, positive is North.
 * Longitude	Decimal degrees, usually to six significant digits. Negative is West, positive is East.
 * Altitude	In feet.
 * Timezone	Hours offset from UTC. Fractional hours are expressed as decimals, eg. India is 5.5.
 * ST	Daylight savings time. One of E (Europe), A (US/Canada), S (South America), O (Australia), Z (New Zealand), N (None) or U (Unknown). See also: Help: Time
 * Tz database time zone	Timezone in "tz" (Olson) format, eg. "America/Los_Angeles".
 * Type	Type of the airport. Value "airport" for air terminals, "station" for train stations, "port" for ferry terminals and "unknown" if not known. In airports.csv, only type=airport is included.
 * Source	Source of this data. "OurAirports" for data sourced from OurAirports, "Legacy" for old data not matched to OurAirports (mostly DAFIF), "User" for unverified user contributions. In airports.csv, only source=OurAirports is included.
 * @param fileName 
 * @param delim 
 * @param skipMissingIataCode Skip input line if the flag is true and IATA code is missing
 * @return std::unordered_map<string,Airport> 
 */
std::unordered_map<string,Airport> FileHelper::getAirportMapByCode(const string fileName, char delim, bool skipMissingIataCode) {
    std::cout << "Entering: getAirportMapByCode(...)" << std::endl;
    //parse the file
    vector<vector<string>> attributesByLine = getAttributesByLine(fileName,delim);

    unordered_map<string,Airport> airportMapByCode = unordered_map<string,Airport>();
    airportMapByCode.reserve(1.5 * attributesByLine.size());    //reserve enough space so that resize won't be called
    for(vector<string> attributes : attributesByLine) {
        //std::cout << "Size of attributes: " << attributes.size() << std::endl;
        if(attributes.size() < 13) continue;
        string ttype = attributes[12];
        //std::cout << "Type of Terminal: " << attributes[12] << std::endl;
        //int c = ttype.compare("airport");
        //std::cout << "Compare result: " << c << std::endl;
        if(airport_util::isValidAirport(ttype)) {
            string iataCode =  attributes[4];
            if(iataCode.length() <3) {      //if iatacode is missing
                if(!skipMissingIataCode) iataCode = attributes[5];      //get 4-letter ICAO code
            }
            if(iataCode.length() >= 3) {        //if valid airport code then add to the map
                airportMapByCode[iataCode]  = Airport(attributes[2],attributes[3],iataCode,
                    std::stod(attributes[6]), 
                    std::stod(attributes[7]) );
            }
        }
    }
    std::cout << "Total Number of Airports: " << airportMapByCode.size()  << std::endl;
    return airportMapByCode;
}

/**
 * @brief 
 * Airline	2-letter (IATA) or 3-letter (ICAO) code of the airline.
 * Airline ID	Unique OpenFlights identifier for airline (see Airline).
 * Source airport	3-letter (IATA) or 4-letter (ICAO) code of the source airport.
 * Source airport ID	Unique OpenFlights identifier for source airport (see Airport)
 * Destination airport	3-letter (IATA) or 4-letter (ICAO) code of the destination airport.
 * Destination airport ID	Unique OpenFlights identifier for destination airport (see Airport)
 * Codeshare	"Y" if this flight is a codeshare (that is, not operated by Airline, but another carrier), empty otherwise.
 * Stops	Number of stops on this flight ("0" for direct)
 * Equipment	3-letter codes for plane type(s) generally used on this flight, separated by spaces
 * @param fileName 
 * @param delim 
 * @param graph 
 */
void FileHelper::readRoutesAndAddtoGraph(const string fileName, char delim, Graph& graph) {
    std::cout << "Entering: readRoutesAndAddtoGraph(...)" << std::endl;
    //read csv
    vector<vector<string>> attributesByLine = getAttributesByLine(fileName,delim);
    for(vector<string> attributes : attributesByLine) {
        if(attributes.size() < 5) continue; //not enough detail to create Route
        //get source and destination
        string fromCode = attributes[2];
        string toCode  = attributes[4];
        graph.addRoute(fromCode,toCode);
    }

}

