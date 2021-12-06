#pragma once

#include "Airport.h"

#include <limits>
#include <string>



using std::string;


namespace route_util {
    const string INVALID_AIRPORT_CODE = "INVALID_CODE";
    const int INVALID_WEIGHT = INT_MIN;
    //gets the distance between two airports in km
    int getDistance(Airport* from, Airport* to);
    string getRouteCode(string fromCode, string toCode);
}  

class Route {
    public:
        Route();
        Route(string _fromCode, Airport* _from, 
        string _toCode, Airport* _to);

        Route(string _fromCode, Airport* _from, 
        string _toCode, Airport* _to, int _distance);

        bool isDomestic();

        string getCodeName() const;
        string getFromCode() const;
        Airport* getFrom() const;
        string getToCode() const;
        Airport* getTo() const;

        string getLabel() const;
        void setLabel(string _label);

        int getDistance() const;

    private:
        string codeName;
        string fromCode;
        Airport* from;
        string toCode;
        Airport* to;

        string label;
        int distance;

        void initValues();
};
