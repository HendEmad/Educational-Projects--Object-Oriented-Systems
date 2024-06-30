#ifndef MEDICALOPERATION_H
#define MEDICALOPERATION_H

#include <string>
#include "Patient.h"
#include "Doctor.h"

class MedicalOperation {
public:
    std::string operationID;
    std::string type;
    std::string date;
    Patient patient;
    Doctor doctor;
};

#endif // MEDICALOPERATION_H
