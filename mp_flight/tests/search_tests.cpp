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
    graph.addRoute("5", "3", 7);
    //run djkstras + verify 1
    Search_Dijkstra sd;
    std::vector<const Route*> v = sd.searchMyFlight(graph, "1", "5");
    std::cout << "this is a test" << std::endl;
    REQUIRE(v.size() == 1); 
    //run djkstras + verify 2
    v = sd.searchMyFlight(graph, "1", "4");
    std::cout << "this is a test 2" << std::endl;
    REQUIRE(v.size() == 2); 
    //run djkstras + verify 3
    v = sd.searchMyFlight(graph, "2", "3");
    std::cout << "this is a test 3" << std::endl;
    REQUIRE(v.size() == 3); 
}


TEST_CASE("Testing_Dijkstra_But_No_Route", "[weight=15]") {
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
    //run djkstras + verify
    Search_Dijkstra sd;
    std::vector<const Route*> v = sd.searchMyFlight(graph, "2", "3");
    std::cout << "this is a test 4" << std::endl;
    REQUIRE(v.size() == 0); 
}