#pragma once
#include "Doctor.h"
#include <vector>
#include <fstream>
#include <iostream>
#include"Parser.h"
using namespace std;
class DoctorManager
{
private:
	vector<Doctor> doctors;
public:
    vector<Doctor>& getDoctors() { return doctors; } 
    //Load doctors from file when the program starts
    void loadDoctorsFromFile() {
        fstream file("doctors.txt", ios::in | ios::out | ios::app);
        if (file.is_open()) {
            string line;
            while (getline(file, line))
            {
                try {
                    Doctor b = Parser::parseToDoctor(line);
                    doctors.push_back(b);
                }
                catch (const runtime_error& e)
                {
                    cerr << "Skipping invalid line: " << line << " -> " << e.what() << endl;
                }
            }file.close();
        }
    }
    void saveDoctorsToFile() {
        ofstream file("doctors.txt", ios::out);
        if (!file.is_open()) {
            cerr << "Error: Cannot open doctors.txt for writing.\n";
            return;
        }

        for (auto& d : doctors) {
            file << d.getId() << ","
                << d.getPhone() << ","
                << d.getName() << ","
                << d.getSpecialty() << endl;
        }
        file.close();
        cout << "Doctors saved successfully.\n";
    }
    //add new doctor
    void addDoctor() {
        int id, phone;
        string name, specialization;

        cout << "Enter Doctor ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Specialization: ";
        getline(cin, specialization);
        cout << "Enter Phone: ";
        cin >> phone;

        doctors.push_back(Doctor(id, phone, name, specialization));
        saveDoctorsToFile();
        cout << "Doctor added successfully!\n";
    }
    //display all doctors
    void displayAllDoctors() {
        if (doctors.empty()) {
            cout << "No Doctors found.\n";
            return;
        }
        cout << "\n=== List of Doctors ===\n";
        for (auto& d : doctors) {
            d.displayInfo();
        }
        cout << "=========================\n";
    }
    //Search for a doctors by ID
    void searchDoctor() {
        int searchId{};
        cout << "Enter Doctor ID: ";
        cin >> searchId;
        for (auto& d : doctors) {
            if (d.getId() == searchId) {
                d.displayInfo();
                return;
            }
        }
        cout << "Doctor not found.\n";
    }
    //clear all doctors
    void clearDoctorFile() {
        ofstream file("doctors.txt", ios::trunc);
        if (!file.is_open()) {
            cerr << "Error: Cannot open file for clearing.\n";
            return;
        }

        file.close();
        doctors.clear();
        cout << "All doctor records have been deleted.\n";
    }
    //Update Doctors
    void updateDoctor() {
        int searchId;
        cout << "Enter Doctor ID to update: ";
        cin >> searchId;

        for (auto& d : doctors) {
            if (d.getId() == searchId) {
                cout << "Updating details for: " << d.getName() << endl;

                int newPhone;
                string newName, newSpecialty;

                cout << "Enter new Name (or press Enter to keep current: " << d.getName() << "): ";
                cin.ignore();
                getline(cin, newName);
                if (!newName.empty()) d.setName(newName);

                cout << "Enter new Specialization (or press Enter to keep current: " << d.getSpecialty() << "): ";
                getline(cin, newSpecialty);
                if (!newSpecialty.empty()) d.setSpecialty(newSpecialty);

                cout << "Enter new Phone number (or -1 to keep current: " << d.getPhone() << "): ";
                cin >> newPhone;
                if (newPhone != -1) d.setPhone(newPhone);

                saveDoctorsToFile(); 
                cout << "Doctor updated successfully!\n";
                return;
            }
        }
        cout << "Doctor not found.\n";
    }
    void menu(DoctorManager& d) {
        int choice;
        while (true) {
            cout << "\n===== Hospital Management System =====\n";
            cout << "1. Add Doctor\n";
            cout << "2. Display All Doctors\n";
            cout << "3. Search for Doctor by ID\n";
            cout << "4. Delet All Doctors\n";
            cout << "5. Update Doctors By Id\n";
            cout << "6. Back to Main Menu\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                d.addDoctor(); // Call the add patient function
                break;
            case 2:
                d.displayAllDoctors(); // Call the function to display patients
                break;
            case 3:
                d.searchDoctor(); // Call the function to search for a patient
                break;
            case 4:
                d.clearDoctorFile();
                break;
            case 5:
                d.updateDoctor();
                break;
            case 6:
                cout << "Exiting program... Goodbye!\n";
                return;
            default:
                cout << "Invalid choice! Please try again.\n";
            }
        }
    }
};

