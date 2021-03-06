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


class Search_BFS {
        public:

            void BFS(Graph& G);
            void BFS(Graph& G, Airport& airport);

        private:
            //unordered_map<string,string> predecessor;

            bool initComplete = false;
            void init(Graph& G);

};
