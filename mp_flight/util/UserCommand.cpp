#include "UserCommand.h"
#include "FileHelper.h"
#include "../search/search_dijkstra.h"


#include <vector>
#include <unordered_map>
#include <string>

using std::string;
using std::vector;
using std::unordered_map;

UserCommand::UserCommand() {}

string UserCommand::executeInstruction(const string userInput) {
    if(userInput != "menu") {
       commands.push_back(userInput);  //useful for multi step command
        string command = commands[0];   

        if(command == "load") {
            return executeLoad();
        }  
        //any other command requires data set loaded!
        if(graph.getNumberOfAirports() == 0) {
            commands.clear();
            return LOAD_DATA_HINT + "\n" + USER_HINT;
        } 

        if(command == "search") {
            return executeSearch();
        }

        if(command == "BFS") {
            return executeBFS();
        }

        if(command == "IDS") {
            return executeIDS();
        }
    }
    commands.clear();   //clear all command input
    
    if(userInput == "menu") return USER_HINT;
    return "Unknown command: " + userInput + "\n" + USER_HINT;
}


string UserCommand::executeLoad() {
    std::cout << "Entering executeLoad()"  << std::endl;
    size_t count = commands.size();
    switch (count) {
        case 1: 
            return LOAD_AIRPORT_QUESTION;
        default:
            FileHelper helper;
            string fileName = (commands[1] == "1") ? "data/airports_small.dat" : "data/airports.dat";
            const std::unordered_map<string,Airport>& airports = helper.getAirportMapByCode(fileName, ',',true);
            graph = Graph(true,true);
            graph.setAirports(airports);
            std::cout << "Loading route data at data/routes.dat"  << std::endl;
            helper.readRoutesAndAddtoGraph("data/routes.dat",',',graph);
    }
    commands.clear();
    return "Data Loaded successfully!! \n" + USER_HINT;
}

string UserCommand::executeSearch() {
    std::cout << "Entering executeSearch()"  << std::endl;
    size_t count = commands.size();
    string iataCode = "";
    switch (count) {
        case 1: //search ?
            return "Searh Flight: \n        " + ENTER_DEPARTURE_AIRPORT_CODE;
        case 2: //search START ?
            iataCode = commands[1];
            if(!graph.airportExists(iataCode)) {    //airport NOT found!
                commands.pop_back();
                return AIRPORT_NOT_IN_GRAPH + iataCode + " >>\n    " + "Searh Flight: \n        " + 
                    ENTER_DEPARTURE_AIRPORT_CODE;
            }
            //airport found
            return "Searh Flight: \n        " + ENTER_ARRIVAL_AIRPORT_CODE;
            
        case 3: //search START END
            iataCode = commands[2];
            if(!graph.airportExists(iataCode)) {
                commands.pop_back();
                return AIRPORT_NOT_IN_GRAPH + iataCode + " >>\n    " + "Searh Flight: \n        " + 
                    ENTER_ARRIVAL_AIRPORT_CODE;
            }
            //everything looks good for airport search
            Search_Dijkstra sd;
            vector<Route*> routes = sd.searchMyFlight(graph,commands[1],iataCode);
            string s = search_sp_util::displayMyFlight(routes);
            return s;
    }
    return USER_HINT;
}

string UserCommand::executeBFS() {
    std::cout << "Entering executeBFS()"  << std::endl;

    return "Implement BFS!";
}

string UserCommand::executeIDS() {
    std::cout << "Entering executeIDS()"  << std::endl;

    return "Implement IDDFS!";
}
