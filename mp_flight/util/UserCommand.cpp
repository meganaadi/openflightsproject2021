#include "UserCommand.h"
#include "FileHelper.h"
#include "../search/search_dijkstra.h"
#include "../search/search_BFS.h"
#include "../search/search_IDDFS.h"

#include <fstream>
#include <vector>
#include <unordered_map>
#include <string>

using std::string;
using std::vector;
using std::unordered_map;
using std::ifstream;

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
    FileHelper helper;
    switch (count) {
        case 1: {
            return LOAD_AIRPORT_FILE;
        } 
        case 2: {
            string fileName = commands[1];
            ifstream inputFile(fileName); 
            if( ! (inputFile.good()) ) {
                std::cout << "Loading Airport data:" << fileName  << std::endl;
                commands.pop_back();
                return RE_LOAD_AIRPORT_FILE;
            } else {
                inputFile.close();
                return LOAD_ROUTE_FILE;
            }
        }
        default :
            string fileName2  = commands[2];
            /*
            for(unsigned int i=0; i<commands.size(); i++) {
                std::cout << "User input " << i << "::" << commands[i] << "::" << std::endl;
            } */
            ifstream inputFile2(fileName2); 
            if( ! (inputFile2.good()) ) {
                std::cout << "Loading Route data:" << fileName2  << std::endl;
                commands.pop_back();
                return RE_LOAD_ROUTE_FILE;
            }
            inputFile2.close();
    }
    string airportfileName = commands[1];
    string routeFileName  = commands[2];

    std::cout << "Loading Airport data:" << airportfileName  << std::endl; 
    const std::unordered_map<string,Airport>& airports = helper.getAirportMapByCode(airportfileName, ',',true);
    graph = Graph(true,true);
    graph.setAirports(airports);
    std::cout << "Loading Route data:" << routeFileName  << std::endl; 
    helper.readRoutesAndAddtoGraph(routeFileName,',',graph);  
    commands.clear();
    return "Data Loaded successfully!! \n" + USER_HINT;
}

string UserCommand::executeSearch() {
    std::cout << "Entering executeSearch()"  << std::endl;
    size_t count = commands.size();
    string iataCode = "";
    switch (count) {
        case 1: //search ?
            return "Search Flight: \n        " + ENTER_DEPARTURE_AIRPORT_CODE;
        case 2: //search START ?
            iataCode = commands[1];
            if(!graph.airportExists(iataCode)) {    //airport NOT found!
                commands.pop_back();
                return AIRPORT_NOT_IN_GRAPH + iataCode + " >>\n    " + "Searh Flight: \n        " + 
                    ENTER_DEPARTURE_AIRPORT_CODE;
            }
            //airport found
            return "Search Flight: \n        " + ENTER_ARRIVAL_AIRPORT_CODE;
            
        case 3: //search START END
            iataCode = commands[2];
            if(!graph.airportExists(iataCode)) {
                commands.pop_back();
                return AIRPORT_NOT_IN_GRAPH + iataCode + " >>\n    " + "Searh Flight: \n        " + 
                    ENTER_ARRIVAL_AIRPORT_CODE;
            }
            //everything looks good for airport search
            Search_Dijkstra sd;
            Graph graph2(graph);
            vector<const Route*> routes = sd.searchMyFlight(graph2,commands[1],iataCode);
            string s = search_sp_util::displayMyFlight(routes);
            return s;
    }
    commands.clear();   //clear all command input
    return USER_HINT;
}

string UserCommand::executeBFS() {
    std::cout << "Entering executeSearch()"  << std::endl;
    size_t count = commands.size();
    string iataCode = "";
    switch (count) {
        case 1: //search ?
            return "Starting Airport(vertex): \n        " + ENTER_DEPARTURE_AIRPORT_CODE;
        case 2: //search START ?
            iataCode = commands[1];
            if(!graph.airportExists(iataCode)) {    //airport NOT found!
                commands.pop_back();
                return AIRPORT_NOT_IN_GRAPH + iataCode + " >>\n    " + "Searh Flight: \n        " + 
                    ENTER_DEPARTURE_AIRPORT_CODE;
            }
        //start of BFS
        Graph graph2(graph);
        Search_BFS bfs;
        bfs.BFS(graph2, graph2.getAirport(iataCode));
        for(auto& elem : graph2.getRoutes()) {
          Route r = elem.second;
          string label = r.getFromCode() + " " + r.getLabel() + " " + r.getToCode();
          std::cout << label << std::endl;
        }   
    }
    commands.clear();   //clear all command input
    return "finished!   >>> " + USER_HINT;
}

string UserCommand::executeIDS() {
    std::cout << "Entering executeIDS()"  << std::endl;
    size_t count = commands.size();
    string iataCode = "";
    switch (count) {
        case 1: { //search ?
            return "Starting Airport Code: \n        " + ENTER_DEPARTURE_AIRPORT_CODE;
        }
        case 2: { //search START ?
            iataCode = commands[1];
            if(!graph.airportExists(iataCode)) {    //airport NOT found!
                commands.pop_back();
                return AIRPORT_NOT_IN_GRAPH + iataCode + " >>\n    " + "Search Flight: \n        " + 
                    ENTER_DEPARTURE_AIRPORT_CODE;
            }
            //airport found
            return "Ending Airport Code: \n        " + ENTER_ARRIVAL_AIRPORT_CODE;
            
        }
        case 3: { //search START END
            iataCode = commands[2];
            if(!graph.airportExists(iataCode)) {
                commands.pop_back();
                return AIRPORT_NOT_IN_GRAPH + iataCode + " >>\n    " + "Search Flight: \n        " + 
                    ENTER_ARRIVAL_AIRPORT_CODE;
            }
            return "Enter limiting depth (INTEGER NUMBER): \n ";
        }
        case 4: {
            for(unsigned int i=0; i<commands.size(); i++) {
                std::cout << "User input " << i << "::" << commands[i] << "::" << std::endl;
            }
            string d = commands[3];
            int depth = stoi(d);
            //time to executs IDDFS
            Graph graph2(graph);
            Search_IDDFS iddfs; 
            std::cout << "IIDFS from: " << commands[1] << "; to: " << commands[2] << "; with a max depth of: " << depth << std::endl;
            bool found = iddfs.IDDFS(graph2, commands[1], commands[2], depth);
            std::cout << "IIDFS Result: " << found << std::endl;
                
        }
        
        
    }
    commands.clear();   //clear all command input
    return "IIDFS finished!   >>> " + USER_HINT;
}
