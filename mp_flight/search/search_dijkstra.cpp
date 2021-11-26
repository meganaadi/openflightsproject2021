#include "search_dijkstra.h"

#include <limits>
#include <iostream>
#include <stdexcept>

string search_sp_util::displayMyFlight(vector<Route*> routes) {
    size_t size = routes.size();
    if(size <2) return "No flights found! Try a nearby airport!!!";
    string s = "";
    for(Route* rp : routes) {
        s = s + rp->getFromCode() + " >> ";
    }
    s = s + routes[size-1]->getToCode() + " :) ";
    return s;
}

unordered_map<string,int> distance;


class DistanceComparator {
    public:
        bool operator() (string airportCode1, string airportCode2) {
            //return search_sp_util::distance[airportCode1]>search_sp_util::distance[airportCode2];
            return distance[airportCode1]>distance[airportCode2];
        }
};


Search_Dijkstra::Search_Dijkstra() {
    init();
}

void Search_Dijkstra::init() {
    predecessor.clear();
    distance.clear();
}

vector<Route*> Search_Dijkstra::searchMyFlight(Graph graph, string fromCode, string toCode) {
    vector<Route*> path;
    //call findShortestPath

    return path;
}

void Search_Dijkstra::findShortestPath(Graph& G, string fromCode) {
    init();
    //ToDO
}