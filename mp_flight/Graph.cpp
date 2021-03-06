#include "Airport.h"
#include "Route.h"
#include "Graph.h"

#include "Airport.h"
#include "Route.h"
#include "Graph.h"

#include <limits>
#include <iostream>
#include <stdexcept>




Graph::Graph(bool weighted, bool directed) {
    _weighted = weighted;
    _directed = directed;
}

Graph::Graph(const Graph & other) {
    std::cout << "Graph:: copy constructor called!" << std::endl;
    copy(other);
}

Graph& Graph::operator= (const Graph& other) {
    std::cout << "Graph:: Assignment  operator called!" << std::endl;
    copy(other);
    return *this;
}

void Graph::copy(const Graph& other) {
    _weighted = other._weighted;
    _directed = other._directed;
    setAirports(other.airportMapByCode);
    unordered_map<string,Route>::const_iterator iter = other.routes.begin();
    for(; iter !=other.routes.end(); iter++) {
        addRoute(iter->second.getFromCode(),iter->second.getToCode(),iter->second.getDistance());
    }
}

vector<string> Graph::getVertices() const {
    vector<string> vertices;
    unordered_map<string,Airport>::const_iterator iter = airportMapByCode.begin();
    for(; iter != airportMapByCode.end(); iter++) 
        vertices.push_back(iter->first);
    return vertices;
}

vector<string> Graph::getAdjacent(string iataCode) {
    vector<string> adjacent;
    if(airportExists(iataCode)) {
        for(Airport* ap : getAirport(iataCode).getAdjacent(_directed)) {
            adjacent.push_back(ap->getIataCode());
        }
    }
    return adjacent;
}

bool Graph::routeExists(string fromCode, string toCode) {
    //string routeCode = route_util::getRouteCode(fromCode,toCode);
    //unordered_map<string,Route>::const_iterator iter = routes.find(routeCode);
    //if(iter == routes.end()) return false;
    //return true;

    Route* rp = getRoute(fromCode,toCode);
    if(rp->getFromCode() == route_util::INVALID_AIRPORT_CODE) return false;
    return true;

}

const unordered_map<string,Route>& Graph::getRoutes() const {
    return routes;
}

Route* Graph::getRoute(string fromCode, string toCode) {
    string routeCode = route_util::getRouteCode(fromCode,toCode);
    unordered_map<string,Route>::const_iterator iter = routes.find(routeCode);
    if(iter != routes.end()) return &(routes[routeCode]);
    if(!_directed) {    //if not directed reverse the route
        routeCode = route_util::getRouteCode(toCode,fromCode);
        unordered_map<string,Route>::const_iterator iter = routes.find(routeCode);
        if(iter != routes.end()) return &(routes[routeCode]);
    }

    //not found
    return &(graph_util::INVALID_ROUTE);
    
}

int Graph::getEdgeWeight(string fromCode, string toCode)  {
    if(!_weighted) 
        std::invalid_argument("Illegal state! getEdgeWeight called on a Graph with no weight!");
    const Route* rp = getRoute(fromCode,toCode);
    if(rp->getFromCode() == route_util::INVALID_AIRPORT_CODE)
        return route_util::INVALID_WEIGHT;
    return rp->getDistance();
}

unordered_map<string,Airport>& Graph::getAirports() {
    return airportMapByCode;
}

void Graph::setAirports(const unordered_map<string,Airport>& airportsByCode) {
    airportMapByCode = airportsByCode;      //copy construction
}

void Graph::addAirport(Airport airport) {
    airportMapByCode[airport.getIataCode()] = airport;      //copy construction
}

void Graph::addRoute(string fromCode, string toCode, int distance) {
   addRoute(fromCode,toCode,true,distance);
}

void Graph::addRoute(string fromCode, string toCode) {
    if(!_weighted) addRoute(fromCode,toCode,true,0);
    else addRoute(fromCode,toCode,false,0);
}

void Graph::addRoute(string fromCode, string toCode, bool distanceProvided, int distance) {
    //identifier for this route
    if(routeExists(fromCode,toCode)) return;

    string routeCodeName = route_util::getRouteCode(fromCode,toCode);
    unordered_map<string,Airport>::iterator lookup = airportMapByCode.find(fromCode);
    if(lookup != airportMapByCode.end()) {  //if departure airport exists
        Airport* from = &(lookup->second);
        lookup = airportMapByCode.find(toCode);
        if(lookup != airportMapByCode.end()) {  //if arrival airport exists
            Airport* to = &(lookup->second);
            if(distanceProvided) {
                routes[routeCodeName] = Route(fromCode,from,toCode,to,distance);
            } else {
                routes[routeCodeName] = Route(fromCode,from,toCode,to);
            }
            //add this as an outbound flight to departure airport
            Route* rp = &routes.at(routeCodeName);
            from->addRoute(rp);
            if(!_directed) to->addRoute(rp);    //if not directed add the same to reverse
        }
    }
}

Airport& Graph::getAirport(string iataCode)  {
    unordered_map<string,Airport>::const_iterator iter = airportMapByCode.find(iataCode);
    if(iter == airportMapByCode.end()) return graph_util::INVALID_AIRPORT;
    return airportMapByCode[iataCode];
}

bool Graph::airportExists(string iataCode) const {
    //find via find;  use of [] will create one if not found!
    unordered_map<string,Airport>::const_iterator iter = airportMapByCode.find(iataCode);
    if(iter == airportMapByCode.end()) return false;
    return true;
}

size_t Graph::getNumberOfAirports() {
    return airportMapByCode.size();
}
