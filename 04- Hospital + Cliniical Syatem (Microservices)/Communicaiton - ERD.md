| Service                   | Primary Entities               | Read-Only Entities                          |
|---------------------------|--------------------------------|---------------------------------------------|
| Appointment Scheduling    | Appointment, Receptionist     | Patient, Doctor, Room                      |
| Patient Management        | Patient, PatientHistory       | Doctor, Room, Receptionist                 |
| Prescription & Medication | Prescription, Pharmacy        | Patient, Doctor, Medication, Room          |
| Lab & Diagnostics         | LabTest, Scan                 | Patient, Doctor, LabTestType, Medication   |
| Treatment & ICU           | Treatment, ICU                | Patient, Doctor, Room, Medication          |
| Medical Operations        | MedicalOperation              | Doctor, Patient, Room, Nurse, Treatment    |
| Technical Support         | TechnicalStaff, Issue         | Room, Doctor, Patient, ICU                 |
