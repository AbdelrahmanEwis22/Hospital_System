#pragma once
#include<iostream>
#include"PatientManager.h"
#include"DoctorManager.h"
#include"AppointmentManager.h"
#include"MedicalRecordManager.h"
using namespace std; 
class searchAll
{
public:
    void searchAlls(PatientManager& pm, DoctorManager& dm, AppointmentManager& am, MedicalRecordManager& mrm) {
        int searchID;
        cout << "Enter ID to search across the system: ";
        cin >> searchID;

        cout << "\n=== Search Results ===\n";

        //Find Patients
        bool found = false; 
        for (auto& p : pm.getPatients()) {
            if (p.getId() == searchID) {
                cout << "?? Found Patient:\n";
                p.displayInfo();
                found = true;
            }
        }

         //Find Doctors
        for (auto& d : dm.getDoctors()) {
            if (d.getId() == searchID) {
                cout << "?? Found Doctor:\n";
                d.displayInfo();
                found = true;
            }
        }

        //Find Appointments
        for (auto& a : am.getAppointments()) {
            if (a.getPatientID() == searchID || a.getDoctorID() == searchID) {
                cout << "?? Found Appointment:\n";
                a.displayInfo();
                found = true;
            }
        }

        //Find MedicalRecord
        for (auto& r : mrm.getRecords()) {
            if (r.getPatientID() == searchID) {
                cout << "Found Medical Record:\n";
                r.displayInfo();
                found = true;
            }
        }

        if (!found) {
            cout << "No records found for this ID.\n";
        }
    }
};

