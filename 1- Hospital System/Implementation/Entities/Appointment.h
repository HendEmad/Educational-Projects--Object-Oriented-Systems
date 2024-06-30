#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <iostream>
#include <string>
#include "Patient.h"
#include "Doctor.h"

class Appoitment {
public:
    std::string appointmentId;
    std::string date;
    std::string time;
    Patient patient;
    Doctor doctor;
};

#endif // APPOINTMENT_H