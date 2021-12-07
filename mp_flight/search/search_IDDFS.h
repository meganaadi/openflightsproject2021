#pragma once

#include "../Airport.h"
#include "../Route.h"
#include "../Graph.h"

#include <iostream>
#include <unordered_map>
#include <stack>
#include <map>
#include <string>

using namespace std;

class Search_IDDFS {
    public:

        vector<Airport> IDDFS(Graph G, Airport& fromCode, Airport& toCode, int maxdepth);
        vector<Airport> DLS(Graph G, Airport& fromCode, Airport& toCode, int limitdepth);
    private:
        bool FoundAnswer = false;
        vector<Airport> answer;
        
    
};