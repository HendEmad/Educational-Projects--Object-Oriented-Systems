#ifndef LABORATORY_H
#define LABORATORY_H

#include <string>
#include <vector>
#include "LabTest.h"

class Laboratory {
public:
    std::string labID;
    std::string name;
    std::vector<LabTest> tests;
};

#endif // LABORATORY_H
