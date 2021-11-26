#pragma once

#include "../Airport.h"
#include "../Route.h"
#include "../Graph.h"

#include <vector>
#include <unordered_map>
#include <string>

using std::string;
using std::vector;
using std::unordered_map;



namespace search_sp_util {
    string displayMyFlight(vector<Route*>);
    //unordered_map<string,int> distance;
    
}


class Search_Dijkstra {
    public:
        Search_Dijkstra();
        vector<Route*> searchMyFlight(Graph graph, string fromCode, string toCode);
        void findShortestPath(Graph& G, string fromCode);

    private:
        unordered_map<string,string> predecessor;
        void init();
};