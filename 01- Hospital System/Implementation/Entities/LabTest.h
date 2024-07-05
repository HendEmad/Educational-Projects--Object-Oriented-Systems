#ifndef LABTEST_H
#define LABTEST_H

#include <string>
#include "Patient.h"

class LabTest {
public:
    std::string labTestID;
    std::string type;
    std::string result;
    std::string date;
    Patient patient;
};

#endif // LABTEST_H
