### Communicaton between each pair of microservices:
1. Patient Management Service <-> Prescription & Medication service
    * Exmaple on the communication:
        * Request from `Patient Management Service`:
        ```json
        {
            "patientId": "12345",
            "prescription" : [{"medication": "Amoxicillin", "dosage": "500mg", "instruction": "twice a day"}],
            "doctorInstructions": "take after meals"
        }
        ```
        * Resonse from `Prescription & Medication Service`:
        ```json
        {
            "prescriptionId": "98765",
            "status": "Processed",
            "availability": "In Stock",
            "pickupDetails": {
                "location": "Pharmacy, Ground Floor",
                "readyAt": "2024-08-15T15:00:00"
            }
        }
        ```

2. `Patient Management Service` <-> `Appointment Scheduling Service`
    * Exmaple on the communication:
        * Request from `Patient Management Service`:
        ```json
        {
            "patientId": "12345",
            "preferredDate": "2024-08-16",
            "appointmentType": "Consultation"
        }
        ```
        * Resonse from `Appointment Scheduling Service`:
        ```json
        {
            "appointmentId": "67890",
            "scheduledDate": "2024-08-16T14:00:00",
            "location": "Consultation Room 5",
            "specialist": "Dr. John Doe"
        }
        ```

3. `Patient Management Service` <-> `Lab & Diagnostics Service`
    * Exmaple on the communication:
        * Request from `Patient Management Service`:
        ```json
        {
            "patientId": "12345",
            "testType": "Blood Test",
            "testDetails": "Complete blood count"
        }
        ```
        * Resonse from `Lab & Diagnostics Service`:
        ```json
        {
            "testRequestId": "54321",
            "scheduledDate": "2024-08-17T09:00:00",
            "location": "Lab 2, 2nd Floor",
            "resultsTimeline": "2024-08-20"
        }
        ```

4. `Patient Management Service` <-> `Medical Operations Service`
    * Exmaple on the communication:
        * Request from `Patient Management Service`:
        ```json
        {
            "patientId": "12345",
            "procedureDetails": "Appendectomy",
            "preferredDate": "2024-08-18"
        }
        ```
        * Resonse from `Lab & Diagnostics Service`:
        ```json
        {
            "procedureId": "98765",
            "scheduledDate": "2024-08-18T11:00:00",
            "location": "Surgical Theater 3",
            "attendingStaff": ["Dr. Alan Brown"],
            "preProcedureInstructions": "Fast for 8 hours before the procedure"
        }
        ```

5. `Patient Management Service` <-> `Treatment & ICU Service`
    * Exmaple on the communication:
        * Request from `Patient Management Service`:
        ```json
        {
            "patientId": "12345",
            "admissionReason": "Severe respiratory distress",
            "initialTreatmentPlan": "Intensive monitoring and ventilation support"
        }

        ```
        * Resonse from `Treatment & ICU Service`:
        ```json
        {
            "patientId": "12345",
            "status": "Admitted to ICU",
            "icuRoom": "ICU-15",
            "attendingStaff": ["Dr. Lisa White"],
            "initialCarePlan": "Monitor vitals, administer medications"
        }
        ```

6. `Appointment Scheduling Service` <-> `Prescription & Medication Service`
    * Exmaple on the communication:
        * Request from `Appointment Scheduling Service`:
            ```json
            {
                "patientId": "12345",
                "appointmentId": "67890",
                "medicationDetails": [
                    {"medication": "Lisinopril", "dosage": "10mg", "instructions": "Once daily"}
                ]
            }
            ```
        * Request from `Prescription & Medication Service`:
            ```json
            {
                "medicationAdjustment": "No adjustment needed",
                "updatedPrescription": {
                    "medication": "Lisinopril",
                    "dosage": "10mg",
                    "instructions": "Once daily"
                }
            }
            ```

7. `Appointment Scheduling Service` <-> `Technical Support Service`
    * Exmaple on the communication:
        * Request from `Appointment Scheduling Service`:
            ```json
            {
                "issueId": "9876",
                "issueDescription": "Appointment scheduling system outage",
                "urgencyLevel": "High"
            }
            ```
        * Request from `Technical Support Service`:
            ```json
            {
                "issueId": "9876",
                "status": "In Progress",
                "technician": "Alex Turner",
                "estimatedTimeToResolution": "1 hour"
            }
            ```

8. `Prescription & Medication Service` <-> `Technical Support Service`
    * Exmaple on the communication:
        * Request from `Prescription & Medication Service`:
            ```json
            {
                "issueId": "5432",
                "issueDescription": "Prescription processing delay",
                "urgencylevel": "Medium"
            }
            ```
        * Request from `Technical Support Service`:
            ```json
            {
                "issueId": "5432",
                "status": "In progress",
                "technician": "Linda Gomez",
                "estimatedTimeToResolution": "3 hours"
            }
            ```

9. `Medical Operations Service` <-> `Treatment & ICU Service`
    * Exmaple on the communication:
        * Request from `Medical Operations Service`:
            ```json
            {
                "patientId": "12345",
                "transferReason": "Post-surgery recovery",
                "initialTreatmentPlan": "Monitor vitals, administer pain relief"
            }
            ```
        * Request from `Treatment & ICU Service`:
            ```json
            {
                "patientId": "12345",
                "status": "Admitted to ICU",
                "icuRoom": "ICU-12",
                "attendingStaff": ["Dr. Emily Johnson"]
            }
            ```

10. `Treatment & ICU Service` <-> `Technical Support Service`
    * Exmaple on the communication:
        * Request from `Treatment & ICU Service`:
            ```json
            {
                "issueId": "5678",
                "equipmentDetails": "Ventilator not functioning",
                "priorityLevel": "Critical"
            }
            ```
        * Request from `Technical Support Service`:
            ```json
            {
                "issueId": "5678",
                "status": "Repair in Progress",
                "technician": "Sarah Lee",
                "estimatedCompletion": "30 minutes"
            }
            ```

11. `Lab & Diagnostics Service` <-> `Treatment & ICU Service`
    * Exmaple on the communication:
        * Request from `Lab & Diagnostics Service`:
            ```json
            {
                "patientId": "12345",
                "testRequestId": "56789",
                "labResults": {
                    "X-ray": "No fractures detected",
                    "notes": "Mild inflammation observed"
                }
            }
            ```
        * Request from `Treatment & ICU Service`:
            ```json
            {
                "status": "Results Received",
                "furtherActionRequired": "Monitor inflammation, adjust medication if needed"
            }
            ```

12. `Medical Operations Service` <-> `Technical Support Service`
    * Exmaple on the communication:
        * Request from `Medical Operations Service`:
            ```json
            {
                "issueId": "4321",
                "issueDescription": "Surgical light malfunction",
                "urgencyLevel": "High"
            }
            ```
        * Request from `Technical Support Service`:
            ```json
            {
                "issueId": "4321",
                "status": "In Progress",
                "technician": "Mike Davis",
                "estimatedTimeToResolution": "2 hours"
            }
            ```

13. `Medical Operations Service` <-> `Lab and Diagnostics Service`
    * Exmaple on the communication:
        * Request from `Medical Operations Service`:
            ```json
            {
                "patientId": "12345",
                "testRequestId": "56789"
            }
            ```
        * Request from `Lab and Diagnostics Service`:
            ```json
            {
                "testRequestId": "56789",
                "status": "Completed",
                "results": {
                    "X-ray": "No fractures detected",
                    "notes": "Mild inflammation observed"
                },
                "attachments": ["scan_image_1.png"]
            }
            ```