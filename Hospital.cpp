
#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include"Person.h"
#include"Patient.h"
#include"Doctor.h"
#include"Appointment.h"
#include"PatientManager.h"
#include"DoctorManager.h"
#include"Appointment.h"
#include"AppointmentManager.h"
#include"MedicalRecord.h"
#include"MedicalRecordManager.h"
#include"searchAll.h"
using namespace std;
int main()
{
    int ch; MedicalRecordManager m;
    AppointmentManager a; 
    DoctorManager d; 
    PatientManager pm; 
    searchAll s;
    while (true)
    {
        cout << "\n===== Hospital Management System =====\n";
        cout << "1. Manage Patients\n";
        cout << "2. Manage Doctors\n";
        cout << "3. Manage Appointments\n";
        cout << "4. Manage Medical Records\n";
        cout << "5. Search Across System\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        if (ch == 1) {
            pm.loadPatientsFromFile();   // Load patient data at startup
            pm.menu(pm);
        }
        else if (ch == 2) {
            d.loadDoctorsFromFile();
            d.menu(d);
        }
        else if (ch == 3) {
            a.menu();  
        }
        else if (ch == 4) {
            m.menu();  
        }
        else if (ch == 5) {
            s.searchAlls(pm, d, a, m);  
        }
        else if (ch == 6) { cout << "Exiting program... Goodbye!\n";  break; }
        else cout << "Invalid choice! Please try again.\n";
    }
    
 
    return 0;
}

