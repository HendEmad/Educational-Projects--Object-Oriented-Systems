#ifndef TREATMENT_H
#define TREATMENT_H

#include <iostream>
#include <string>
#include "Patient.h"
#include "Doctor.h"

class Treatment {
public:
    std::string treartmentId;
    std::string desctiption;
    Patient patient;
    Doctor doctor;
    std::string date;
};

#endif // TREATMENT_H