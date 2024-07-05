#ifndef SCAN_H
#define SCAN_H

#include <string>
#include "Patient.h"

class Scan {
public:
    std::string scanID;
    std::string type;
    std::string result;
    std::string date;
    Patient patient;
};

#endif // SCAN_H
