#include "search_IDDFS.h"
#include <iostream>
#include <unordered_map>
#include <stack>
#include <map>
#include <string>

using namespace std;

void Search_IDDFS::init() {
    answer.clear();
    
    // Mark all airports not visited
    for (auto& pair: gp->getAirports()){
        Airport& airport = pair.second;
        airport.setLabel(graph_util::UNEXPLORED);
    }
}

bool Search_IDDFS::IDDFS(Graph& G, string _fromCode, string _toCode, int maxdepth) {
    gp = &G;
    fromCode = _fromCode;
    toCode = _toCode;
    for (int i = 0; i < maxdepth; i++){
        init();
        std::cout << "Current Depth Limit: " << i << std::endl;
        bool found = DLS(_fromCode, i);
        if(found) return true;
    }
    return false;
}

bool Search_IDDFS::DLS(string source, int limitdepth) {
    if (source == toCode) return true;
    if (limitdepth <= 0) return false;

    Airport& currentAirport = gp->getAirport(source);
    if (currentAirport.getLabel() == graph_util::UNEXPLORED){
        currentAirport.setLabel(graph_util::VISITED);
        for(string adjacentAirportCode : gp->getAdjacent(source)) {
            bool found = DLS(adjacentAirportCode,limitdepth-1);
            if(found) return true;
        }
    }

    return false;
}
