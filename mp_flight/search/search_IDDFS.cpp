#include "search_IDDFS.h"
#include <iostream>
#include <unordered_map>
#include <stack>
#include <map>
#include <string>

using namespace std;

vector<Airport> Search_IDDFS::IDDFS(Graph G, Airport& fromCode, Airport& toCode, int maxdepth){
    for (int i = 0; i < maxdepth; i++){
        if (FoundAnswer == true){
            return answer;
        }
        else {
            DLS(G, fromCode, toCode, i);
        }
    }
    return vector<Airport>();
}

vector<Airport> Search_IDDFS::DLS(Graph G, Airport& fromCode, Airport& toCode, int limitdepth){
    // Mark all airports not visited
    for (auto& pair: G.getAirports()){
        Airport& airport = pair.second;
        airport.setLabel(graph_util::UNEXPLORED);
    }
   
    // Initialize DLS
    stack<Airport> AirportStack;
    AirportStack.push(fromCode);
    Airport current = fromCode;
    //DLS
    while (!AirportStack.empty()){
        if (limitdepth < 0){
            break;
        }
        current = AirportStack.top();
        AirportStack.pop();
        if (current.getLabel() == graph_util::UNEXPLORED){
            current.setLabel(graph_util::VISITED);
            answer.push_back(current);
        }
        if (current.getIataCode() == toCode.getIataCode()){
            FoundAnswer = true;
            break;
        }
        for(string adjacentAirportCode : G.getAdjacent(current.getIataCode())){
            Airport neighbor = G.getAirport(adjacentAirportCode);
            if (neighbor.getLabel() == graph_util::UNEXPLORED){
                AirportStack.push(neighbor);
            }
        }
        limitdepth--;
    }

    return answer;
}
