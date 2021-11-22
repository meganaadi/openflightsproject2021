#pragma once

#include "Airport.h"

#include <string>



using std::string;


namespace route_util {
    int getDistance(Airport* from, Airport* to);
    string getRouteCode(string fromCode, string toCode);
}  

class Route {
    public:
        Route();
        Route(string _fromCode, Airport* _from, 
        string _toCode, Airport* _to);

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