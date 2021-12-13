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

       bool IDDFS(Graph& G, string _fromCode, string _toCode, int maxdepth);
        bool DLS(string source, int limitdepth);
    private:
        Graph* gp;
        string fromCode;
        string toCode;
        vector<string> answer;
        void init();
        
    
};
