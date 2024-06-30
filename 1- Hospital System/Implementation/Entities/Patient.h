#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <vector>
#include <string>

class Appointment;
class Treatment;
class MedicalOperation;
class Prescription;
class LabTest;
class Medication;
class ICU;
class Visitor;
class Scan;

class Patient {
public:
    std::string patientId;
    std::string name;
    std::string address;
    std::string phone;
    std::vector<Appointment> appointments;
    std::vector<Treatment> treatments;
    std::vector<MedicalOperation> medicalOperations;
    std::vector<Prescription> prescriptions;
    std::vector<LabTest> labtests;
    std::vector<Medication> medications;
    std::vector<ICU> ICUs;
    std::vector<Visitor> visitors;
    std::vector<Scan> scans;
    
};

#endif // PATIENT_H