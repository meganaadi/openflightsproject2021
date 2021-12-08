#include "../cs225/catch/catch.hpp"

#include "../Airport.h"
#include "../Graph.h"
#include "../util/FileHelper.h"
#include "../search/search_dijkstra.h"

#include <sstream>
#include <algorithm>
#include <utility>
#include <string>
#include <set>
#include <map>
#include <queue> 

using namespace std; 

TEST_CASE("Testing_Dijkstra_On_Graph", "[weight=15]") {
    //create graph (truetrue)
    Graph graph = Graph(true, true);
    //create airports + add airports
    Airport airport = Airport("Chicago","USA","1",0.0,0.0);
    graph.addAirport(airport);
    airport = Airport("Seattle","USA","2",0.0,0.0);
    graph.addAirport(airport);
    airport = Airport("megana","USA","3",0.0,0.0);
    graph.addAirport(airport);
    airport = Airport("molly","USA","4",0.0,0.0);
    graph.addAirport(airport);
    airport = Airport("swarna","USA","5",0.0,0.0);
    graph.addAirport(airport);
    //add routes with codes and distance 
    graph.addRoute("1", "5", 5);
    graph.addRoute("1", "2", 1);
    graph.addRoute("4", "5", 12);
    graph.addRoute("3", "5", 7);
    graph.addRoute("2", "4", 6);
    graph.addRoute("5", "1", 5);
    graph.addRoute("5", "3", 32);
    //run djkstras + verify
    Search_Dijkstra sd;
    std::vector<const Route*> v = sd.searchMyFlight(graph, "1", "5");
    REQUIRE(v[0]->getDistance() == 5); 
}