#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>


#include "../Airport.h"
#include "../Route.h"
#include "../Graph.h"


using std::string;
using std::vector;
using std::unordered_map;


class FileHelper {
    public:
        static unordered_map<string,Airport> getAirportMapByCode(const string fileName, char delim, bool skipMissingIataCode);

        static void readRoutesAndAddtoGraph(const string fileName, char delim, Graph& graph);
        

        static vector<vector<string>> getAttributesByLine(const string fileName, char delim);
        static string removeDoubleQuotes(string input);

};


