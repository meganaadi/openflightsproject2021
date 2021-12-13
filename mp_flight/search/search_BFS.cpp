#include "search_BFS.h"

#include <limits>
#include <iostream>
#include <stdexcept>
#include <queue>

void Search_BFS::init(Graph& G) {
    for (auto& pair: G.getAirports()) {
        Airport& airport = pair.second;
        airport.setLabel(graph_util::UNEXPLORED);

        for(auto& route : airport.getRoutes()) {
            route.second->setLabel(graph_util::UNEXPLORED);
        }
    }
    initComplete = true;
}

void Search_BFS::BFS(Graph& G) {
    initComplete = false;
    init(G);
    for (auto& pair: G.getAirports()) {
        Airport& airport = pair.second;
        if(airport.getLabel() == graph_util::UNEXPLORED) {
            BFS(G, airport);
        }
    }
}

void Search_BFS::BFS(Graph& G, Airport& airport) {
    if(!initComplete) init(G);
    string iataCode = airport.getIataCode();
    std::cout << "Current BFS node: " << iataCode << std::endl;
    if(!G.airportExists(iataCode)) return;
    std::queue <string> myQueue;
    airport.setLabel(graph_util::VISITED);
    myQueue.push(iataCode);

    while(!myQueue.empty()) {
        iataCode = myQueue.front();
        myQueue.pop();
        //get all adjacent airports
        const vector<string>& adjacent = G.getAdjacent(iataCode);
        for(string adjacentAirportCode : adjacent) {
            Airport& neighbor = G.getAirport(adjacentAirportCode);
            std::cout << "Current BFS neightbor: " << neighbor.getIataCode() << std::endl;
            //if this is not visited
            if(neighbor.getLabel() == graph_util::UNEXPLORED) {
                neighbor.setLabel(graph_util::VISITED);
                myQueue.push(adjacentAirportCode);
                Route* rp = G.getRoute(iataCode,adjacentAirportCode);
                rp->setLabel(graph_util::DISCOVERY);
            } else {    //airport is visited
                Route* rp = G.getRoute(iataCode,adjacentAirportCode);
                if(rp->getLabel() == graph_util::UNEXPLORED) {
                    rp->setLabel(graph_util::LABEL_CROSS);
                }
            }
        }
    }
}
