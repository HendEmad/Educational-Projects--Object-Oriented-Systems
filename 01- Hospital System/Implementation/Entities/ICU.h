#ifndef ICU_H
#define ICU_H

#include <string>
#include "Patient.h"

class ICU {
public:
    std::string icuID;
    std::string admissionDate;
    std::string dischargeDate;
    Patient patient;
};

#endif // ICU_H
