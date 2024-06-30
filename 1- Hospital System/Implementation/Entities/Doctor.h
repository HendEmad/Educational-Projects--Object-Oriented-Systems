# ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include <string>
#include <vector>

class Appointment;
class MedicalOperation;
class Prescription;
class Treatment;

class Doctor {
public:
    std::string doctorId;
    std::string name;
    std::string specialization;

    std::vector<Appointment> appointments;
    std::vector<MedicalOperation> medicalOperations;
    std::vector<Prescription> prescriptions;
    std::vector<Treatment> treatments;
};

#endif // DOCTOR_H