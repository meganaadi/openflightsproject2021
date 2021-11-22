#include "../cs225/catch/catch.hpp"

#include "../Airport.h"
#include "../util/FileHelper.h"

#include <sstream>
#include <algorithm>
#include <utility>
#include <string>
#include <set>
#include <map>

using namespace std;

                               

static vector< string > words = 
{ "dog", "god", "good", "super", "cow", "powers", "skin", "kins" };

static std::map< string, vector< string > > pronunciations = 
                            { { "SCENT", { "DUMMY" } }, 
                              { "CENT", { "DUMMY" } },
                              { "SENT", { "DUMMY" } },
                              { "DOG", { "DOGE" } }
                            };

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//////////////////////// Start of Tests ////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

TEST_CASE("test_ord_map", "[weight=15]")
{
    vector<string> & v = pronunciations.at("DOG");
    std::map< string, vector< string >>::iterator lookup = pronunciations.find("DOG");
    vector<string> * p1 = &v;
    vector<string>* p2 = &(lookup->second);
    REQUIRE(p1 == p2);
}
TEST_CASE("test_remove_Quotes", "[weight=15]")
{
    FileHelper helper;
    string s = "\"test123\"";
    REQUIRE(9 == s.length());
    s = helper.removeDoubleQuotes(s);
    REQUIRE(s == "test123");

    s= "\"test123";
    REQUIRE(8 == s.length());
    s = helper.removeDoubleQuotes(s);
    REQUIRE(s == "test123");

    s= "test123\"";
    REQUIRE(8 == s.length());
    s = helper.removeDoubleQuotes(s);
    REQUIRE(s == "test123");

    s= "test\"123";
    REQUIRE(8 == s.length());
    s = helper.removeDoubleQuotes(s);
    REQUIRE(s == "test\"123");

    s= "test123";
    REQUIRE(7 == s.length());
    s = helper.removeDoubleQuotes(s);
    REQUIRE(s == "test123");

}

TEST_CASE("test_read_airport_data_small", "[weight=15]")
{
    FileHelper helper;
    vector<vector<string>> attributesByLine = helper.getAttributesByLine("data/airports_small.dat", ',');
    REQUIRE(14 == attributesByLine.size());
}

TEST_CASE("test_read_airport_small", "[weight=15]")
{
    FileHelper helper;

    std::unordered_map<string,Airport> airports = helper.getAirportMapByCode("data/airports_small.dat", ',', true);
    REQUIRE(12 == airports.size());

    unordered_map<string,Route> routes = helper.getRouteMapByCode("data/routes.dat",',',airports);
}

TEST_CASE("test_read_airport_large", "[weight=15]")
{
    FileHelper helper;

    std::unordered_map<string,Airport> airports = helper.getAirportMapByCode("data/airports.dat", ',',true);
    REQUIRE(airports.size() > 6000);

    Airport& ord = airports.at("ORD");
    Airport* p1 = &ord;

    unordered_map<string,Route> routes = helper.getRouteMapByCode("data/routes.dat",',',airports);

    Airport& ord2 = airports.at("ORD");
    Airport* p2 = &ord2;

    REQUIRE (p1 == p2);

    for(std::pair<const std::string, Route *> rp : ord2.getRoutes()) {
        Route* r = rp.second;
        //std::cout << "Source: " << r->getFrom()->getIataCode();
        //std::cout << ";  Dest: " << r->getTo()->getIataCode();
        //std::cout << ";  Is Domestic: " << r->isDomestic() << std::endl;
        Airport* p3 = r->getFrom();
        REQUIRE (p1 == p3);
        Route& r2 = routes.at(r->getCodeName());
        REQUIRE( r == &r2);
    }


}



