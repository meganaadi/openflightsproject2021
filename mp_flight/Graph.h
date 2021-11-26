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
    const Route INVALID_ROUTE = Route();
    const Airport INVALID_AIRPORT = Airport();
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

        vector<string> getAdjacent(string iataCode) const;

        bool routeExists(string fromCode, string toCode) const;

        const Route* getRoute(string fromCode, string toCode) const;

        int getEdgeWeight(string fromCode, string toCode) const;

        /**
         * @brief Get the Airport object identified by iata code
         * 
         * @param iataCode 
         * @return Airport& 
         */
        const Airport& getAirport(string iataCode) const;



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

        size_t getNumberOfAirports();


    private:
        bool _weighted;
        bool _directed;
        unordered_map<string,Airport> airportMapByCode;
        unordered_map<string,Route> routes;

        void copy(const Graph& other);
};


