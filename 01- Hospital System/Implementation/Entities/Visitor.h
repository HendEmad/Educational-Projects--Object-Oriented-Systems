#ifndef VISITOR_H
#define VISITOR_H

#include <string>
#include "Patient.h"

class Visitor {
public:
    std::string visitorID;
    std::string name;
    std::string relation;
    Patient patient;
    std::string visitDate;
};

#endif // VISITOR_H
