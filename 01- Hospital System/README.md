# Introduction
The hospital consists of a list of commands, each command corresponds to a specific type of request in the hospital. The command pattern is used to encapsulate these requests, and the commands are executed by the appropriate handlers. For complex processes that require multiple steps or involve different departments, the chain of responsibility pattern is used within the execution of the command. After the commands execution, the BillingHandler assigns the receipt.

# Independent entities
`Patient`, `Doctor`, `Appointment`, `Visitor`, `Scan`, `LabTest`, `Laborratory`, `MedicalOperation`, `ICU`, `Pharmacy`, `Prescription`, `Medication`: These classes define the core data elements of the hospital system, each with its atreibutes and relationships.

# Command Pattern
* `Command` interface: Defines the execute method which is implemented by specific command classes like `AdmitPatientCommand`, `ScheduleAppointmentCommand`, etc.
* Concrete commands: Each command class (e.g., `AdmitPatientCommand`, `ScheduleAppointmentCommand`) encapsulates the information needed to perform a specific action.

# Chain of responsibility
* Command handling with `HospitalSystemHandler`:
    * `HospitalSystemHandler`: This abstract class sets the foundation of handling commands in a chain. It includes a `setNextHandler` method to define the next handler in the chain and a `handle` method to process the command.
    * `BillingHandler`: This specifies ahndler processes billing after executing the commands. it is part of the general command handling chain and is invoked after the commands are executed to manage the billing operations.

* Specialized handler handling for `OperateCommand`:
    * MedicalOperationHandler: This specifies command requires a chain of handlers to execute the operation. It involves multiple steps and thus utilized the COR pattern to process each step sequentially.
    * Concrete handlers for `OperateCommand`: The specialized handlers, such as `ConsultationHandler`, `prepOpLabTest`, and `ScheduleORHandler`, form a chain to handle different aspects of the OperateCommand. Each handler performs its specific task and then passes the command to the next handler in the chain.

# Relationships
* Defined relationships between entities such as `Patient` having multiple `Appointment`, `Treatment`, `Visitor`, etc.
* Command handling relationships, where specific handlers are responsible for specific commands.

# Workflow of the System
### 1. Admitting a Patient:
* Step 1: A `patient` arrives and the receptionist creates an `AdmitPatientCommand`.
* Step 2: `AdmitPatientCommand` is passed to the `HospitalSystem`.
* Step 3: `HospitalSystem` forwards the command to the `ReceptionistHandler`.
* Step 4: `ReceptionistHandler` executes the command to admit the `patient`.
* Step 5: After execution, the `BillingHandler` processes billing for the admission.

### 2. Scheduling an Appointment:
* Step 1: A `patient` requests an `appointment` and the receptionist creates a `ScheduleAppointmentCommand`.
* Step 2: `ScheduleAppointmentCommand` is passed to the `HospitalSystem`.
* Step 3: `HospitalSystem` forwards the command to the `ReceptionistHandler`.
* Step 4: `ReceptionistHandler` schedules the `appointment` and assigns it to a `doctor`.
* Step 5: After scheduling, the `BillingHandler` processes the billing for the `appointment`.

### 3. Recording a Treatment:
* Step 1: A `doctor` provides `treatment` to a patient and creates a `RecordTreatmentCommand`.
* Step 2: `RecordTreatmentCommand` is passed to the `HospitalSystem`.
* Step 3: `HospitalSystem` forwards the command to the `DoctorHandler`.
* Step 4: `DoctorHandler` records the `treatment` details for the `patient`.
* Step 5: After recording, the `BillingHandler` processes the billing for the `treatment`.

### 4. Registering a Visitor:
* Step 1: A `visitor` arrives to see a `patient` and the receptionist creates a `RegisterVisitorCommand`.
* Step 2: `RegisterVisitorCommand` is passed to the `HospitalSystem`.
* Step 3: `HospitalSystem` forwards the command to the `ReceptionistHandler`.
* Step 4: `ReceptionistHandler` registers the `visitor` and records the visit.
* Step 5: After registration, the `BillingHandler` processes any associated charges.

### 5. Performing a Scan:
* Step 1: A `doctor` requests a scan for a `patient` and creates a `PerformScanCommand`.
* Step 2: `PerformScanCommand` is passed to the `HospitalSystem`.
* Step 3: `HospitalSystem` forwards the command to the `ScanHandler`.
* Step 4: `ScanHandler` performs the `scan` and records the results.
* Step 5: After performing the `scan`, the `BillingHandler` processes the billing for the `scan`.

### 6. Conducting a Lab Test:
* Step 1: A `doctor` orders a `labtest` for a `patient` and creates a `ConductLabTestCommand`.
* Step 2: `ConductLabTestCommand` is passed to the `HospitalSystem`.
* Step 3: `HospitalSystem` forwards the command to the `LaboratoryHandler`.
* Step 4: `LaboratoryHandler` conducts the `labtest` and records the results.
* Step 5: After conducting the `labtest`, the `BillingHandler` processes the billing for the `labtest`.

### 7. Operating on a Patient:
* Step 1: A `patient` requires surgery and an `OperateCommand` is created.
* Step 2: `OperateCommand` is passed to the `HospitalSystem`.
* Step 3: `HospitalSystem` forwards the command to the `MedicalOperationHandler`.
* Step 4: `MedicalOperationHandler` passes the command through the chain: `ConsultationHandler`, `PreOpLabTestHandler`, and `ScheduleORHandler`.
* Step 5: Each handler performs its task in sequence.
* Step 6: After the operation, the `BillingHandler` processes the billing for the surgery.

### 8. Admitting to ICU:
* Step 1: A `patient` needs `ICU` care and an `ICUCommand` is created.
* Step 2: `ICUCommand` is passed to the `HospitalSystem`.
* Step 3: `HospitalSystem` forwards the command to the `ICUHandler`.
* Step 4: `ICUHandler` admits the `patient` to the `ICU` and records the admission details.
* Step 5: After `ICU` admission, the `BillingHandler` processes the billing for `ICU` care.

### 9. Dispensing Medication:
* Step 1: A `doctor` prescribes medication and a `DispenseMedicationCommand` is created.
* Step 2: `DispenseMedicationCommand` is passed to the `HospitalSystem`.
* Step 3: `HospitalSystem` forwards the command to the `PharmacyHandler`.
* Step 4: `PharmacyHandler` dispenses the `medication` and records the details.
* Step 5: After dispensing the `medication`, the `BillingHandler` processes the billing for the `medication`.

### 10. Discharging a Patient:
* Step 1: A `doctor` decides to discharge a `patient` and updates the `patient`'s records.
* Step 2: All pending commands and treatments are completed.
* Step 3: `HospitalSystem` ensures all related billing is processed by the `BillingHandler`.
* Step 4: The `patient` is officially discharged from the `hospitalsystem`.