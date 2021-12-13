#pragma once

#include "Airport.h"
#include "Route.h"

#include <vector>
#include <unordered_map>
#include <string>

using std::string;
using std::vector;
using std::unordered_map;


namespace graph_util {
    const string UNEXPLORED = "Unexplored";
    const string VISITED = "Visited";
    const string DISCOVERY = "Discovery";
    const string LABEL_CROSS = "Cross";
    static Route INVALID_ROUTE = Route();
    static Airport INVALID_AIRPORT = Airport();
}

class Graph {
    public:
        Graph(bool weighted, bool directed);

        Graph(const Graph & other);

        Graph& operator= (const Graph& other);

        void addAirport(Airport airport);

        /**
         * @brief Set the Airports
         * Creates a copy of the map calling Airport copy constructur
         * 
         * @param airportsByCode 
         */
        void setAirports(const unordered_map<string,Airport>& airportsByCode);

        unordered_map<string,Airport>& getAirports();

        vector<string> getVertices() const;

        vector<string> getAdjacent(string iataCode) ;

        bool routeExists(string fromCode, string toCode) ;

        Route* getRoute(string fromCode, string toCode) ;

        int getEdgeWeight(string fromCode, string toCode) ;

        /**
         * @brief Get the Airport object identified by iata code
         * 
         * @param iataCode 
         * @return Airport& 
         */
        Airport& getAirport(string iataCode);



        /**
         * @brief Checks if airport exists as identified by the code
         * 
         * @param iataCode 
         * @return true 
         * @return false 
         */
        bool airportExists(string iataCode) const;


        
        /**
         * @brief 
         * 
         * @param fromCode 
         * @param toCode 
         */
        void addRoute(string fromCode, string toCode);

        void addRoute(string fromCode, string toCode, int distance);

        size_t getNumberOfAirports();

        const unordered_map<string,Route>& getRoutes() const;


    private:
        bool _weighted;
        bool _directed;
        unordered_map<string,Airport> airportMapByCode;
        unordered_map<string,Route> routes;

        void copy(const Graph& other);

        void addRoute(string fromCode, string toCode, bool distanceProvided, int distance);
};
