#pragma once

#include "../Graph.h"

#include <vector>
#include <unordered_map>
#include <string>

using std::string;
using std::vector;
using std::unordered_map;


class UserCommand {

    public:
        UserCommand();

        const string USER_HINT = 
            "menu     - prints this menu \n"
            "exit     - exit the program \n"
            "load     - load data \n"
            "search   - search for flights \n"
            "BFS      - run BFS \n"
            "IDS      - Iterative deepening depth-first search \n";

        const string LOAD_AIRPORT_QUESTION =
            "Loading Airport data set!!  Enter 1 for small set, Enter 2 for USA Airport set, OR enter 3 for YOUR OWN SET  << ";

        const string LOAD_AIRPORT_FILE =
            "OK, input airport data set File Name << ";

        const string RE_LOAD_AIRPORT_FILE =
            "You entered an invalid airport file! Input airport data set File Name << ";

        const string LOAD_ROUTE_FILE =
            "OK, input Route data set File Name << ";

        const string RE_LOAD_ROUTE_FILE =
            "You entered an invalid Route file! Input Route data set File Name << ";

        const string LOAD_DATA_HINT = 
            "Load airport data first!!!";

        const string ENTER_DEPARTURE_AIRPORT_CODE =
            "Enter departure airport code: <<";

        const string ENTER_ARRIVAL_AIRPORT_CODE =
            "Enter arrival airport code: <<";

        const string AIRPORT_NOT_IN_GRAPH = 
            "Graph doesn't contain airport code: ";

        string executeInstruction(const string userInput);

    private:
        vector<string> commands;
        Graph graph = Graph(true,true);

        string executeLoad();

        string executeSearch();

        string executeBFS();

        string executeIDS();

};
