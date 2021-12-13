#include "../cs225/catch/catch.hpp"

#include "../Airport.h"
#include "../Graph.h"
#include "../util/FileHelper.h"
#include "../search/search_BFS.h"

#include <sstream>
#include <algorithm>
#include <utility>
#include <string>
#include <set>
#include <map>
#include <queue> 


using namespace std; 

static vector< std::pair<string,string> > routes_info = 
    {   { "1", "2" }, 
        { "3", "4" }, 
        { "3", "5" }, 
        { "3", "6" }, 
        { "4", "5" }, 
        { "5", "6" }, 
        { "7", "4" }, 
        { "7", "5" }, 
        { "8", "5" }, 
        { "8", "6" }, 
        { "9", "7" }, 
        { "9", "8" },
        { "10", "9" }, 
        { "10", "6" }
    };

static void addAirports(Graph& graph) {
    Airport airport = Airport("Chicago","USA","1",1.0,0.0);
    graph.addAirport(airport);
    airport = Airport("222","USA","2",2.0,0.0);
    graph.addAirport(airport);
    airport = Airport("333","USA","3",3.0,0.0);
    graph.addAirport(airport);
    airport = Airport("444","USA","4",4.0,0.0);
    graph.addAirport(airport);
    airport = Airport("555","USA","5",5.0,0.0);
    graph.addAirport(airport);
     airport = Airport("666","USA","6",6.0,0.0);
    graph.addAirport(airport);
     airport = Airport("777","USA","7",7.0,0.0);
    graph.addAirport(airport);
     airport = Airport("888","USA","8",8.0,0.0);
    graph.addAirport(airport);
     airport = Airport("999","USA","9",9.0,0.0);
    graph.addAirport(airport);
     airport = Airport("1010","USA","10",10.0,0.0);
    graph.addAirport(airport);
}

TEST_CASE("Testing_BFS_On_Graph_1", "[weight=15]") {
    //create graph (truetrue)
    Graph graph = Graph(true, false);
    //create airports + add airports
    addAirports(graph);
    //add routes with codes and distance 
    for(auto& elem : routes_info) {
        graph.addRoute(elem.first,elem.second,1);
    }


    //run djkstras + verify
    Search_BFS bfs;
    //bfs.BFS(graph);
    bfs.BFS(graph, graph.getAirport("9"));
    string label = graph.getRoute("1","2")->getLabel();
    REQUIRE(label == graph_util::UNEXPLORED);
    label = graph.getRoute("1","2")->getLabel();
    REQUIRE(label == graph_util::UNEXPLORED);

    label = graph.getRoute("7","5")->getLabel();
    string label2 = graph.getRoute("8","5")->getLabel();
    REQUIRE(label != label2);

    for(auto& elem : graph.getRoutes()) {
        Route r = elem.second;
        std::cout << r.getFromCode();

        std::cout << " " << r.getLabel() << " ";
        std::cout << r.getToCode() << std::endl;
    }



    
}
