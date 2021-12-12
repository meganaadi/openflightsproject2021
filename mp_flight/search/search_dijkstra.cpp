#include "search_dijkstra.h"

#include <queue>
#include <climits>
#include <iostream>
#include <stdexcept>

using std::priority_queue;

string search_sp_util::displayMyFlight(vector<const Route*> routes) {
    size_t size = routes.size();
    if(size < 1) return "No flights found! Try a nearby airport!!!";
    string s = "";
    for(const Route* rp : routes) {
        s = s + rp->getFromCode() + " >> ";
    }
    s = s + routes[size-1]->getToCode();
    return s;
}

unordered_map<string,int> distance;

//comparator class which will be used in pq
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

vector<const Route*> Search_Dijkstra::searchMyFlight(Graph graph, string fromCode, string toCode) {
    vector<const Route*> path;
    //call findShortestPath
    if(!graph.airportExists(fromCode) ||!graph.airportExists(toCode)) {
        return std::vector<const Route*>();
    }
    
    findShortestPath(graph, fromCode);

    unordered_map<string,string>::const_iterator iter = predecessor.find(toCode);
    if(iter == predecessor.end()) {
        return path;
    }
    string destination = toCode;  //track dest
    string previousAirport = "";           //track prev
    bool found = false;
    vector<const Route*> temp;
    while(predecessor.find(destination) != predecessor.end()) {
        previousAirport = predecessor[destination];   
        temp.push_back(graph.getRoute(previousAirport,destination));
        if(previousAirport == fromCode) {
            found = true;
            break;
        }
        destination = previousAirport;
    }
    if(!found) return path;
    path.reserve(temp.size());
    for(int i=temp.size()-1; i>=0; i--) {
        path.push_back(temp[i]);
    }
    
    return path;
}
//function code based off of in class lecture pseudocode 
void Search_Dijkstra::findShortestPath(Graph& G, string fromCode) {
    init();
    //create the pq which will contain the airports to be visited 
    std::priority_queue<string, std::vector<string>, DistanceComparator> pq; 
    //set distances to infinity, parent to null
    for(string airportCode : G.getVertices()) {
        distance[airportCode] = INT_MAX;
        predecessor[airportCode] = "";
    }
    //starting point distance is 0
    distance[fromCode] = 0;
    //push onto queue
    for(string airportCode : G.getVertices()) {
        pq.push(airportCode);
    }
    //create graph which we will perform operation on
    Graph T(true,true); 

    while(pq.size() != 0) {
        //get min distance vertex and add to graph 
        string nextAirportCode = pq.top();
        if(T.airportExists(nextAirportCode)) {
            nextAirportCode = pq.top();
            pq.pop();
        }
        Airport cur = G.getAirport(nextAirportCode);
        T.addAirport(cur); 

        //now for adjacent 
        for (string nearby : G.getAdjacent(nextAirportCode)) {
            if (!T.airportExists(nearby)) {
                int cost = G.getEdgeWeight(nextAirportCode, nearby);

                //now for the calculations of cost
                if(cost + distance[nextAirportCode] < distance[nearby]) {
                    distance[nearby] = cost + distance[nextAirportCode];
                    predecessor[nearby] = nextAirportCode;
                }
                pq.push(nearby);
            }
        }
    } 
}
