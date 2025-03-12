#pragma once
#include"Appointment.h"
#include"Parser.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include<string>
#include<iostream>
class AppointmentManager
{
private:
    vector<Appointment> appointments;
public:
    vector<Appointment>& getAppointments() { return appointments; }  
    //Load doctors from file when the program starts
    void loadDoctorsFromFile() {
        fstream file("appointments.txt", ios::in | ios::out | ios::app);
        if (file.is_open()) {
            string line;
            while (getline(file, line))
            {
                try {
                    Appointment a = Parser::parseToAppointment(line);
                    appointments.push_back(a); 
                }
                catch (const runtime_error& e)
                {
                    cerr << "Skipping invalid line: " << line << " -> " << e.what() << endl;
                }
            }file.close();
        }
    }
    void saveAppointmentsToFile() {
        ofstream file("appointments.txt", ios::out);
        if (!file.is_open()) {
            cerr << "Error: Cannot open appointments.txt for writing.\n";
            return;
        }

        for (auto& a : appointments) {
            file << a.getAppointmentID() << ","
                << a.getPatientID() << ","
                << a.getDoctorID() << ","
                << a.getDate() << ","
                << a.getTime() << endl;
        }
        file.close();
        cout << "Appointments saved successfully.\n";
    }
    void addAppointment() {
        int appID, patID, docID;
        string date, time;

        cout << "Enter Appointment ID: ";
        cin >> appID;
        cout << "Enter Patient ID: ";
        cin >> patID;
        cout << "Enter Doctor ID: ";
        cin >> docID;
        cin.ignore();
        cout << "Enter Date (YYYY-MM-DD): ";
        getline(cin, date);
        cout << "Enter Time (HH:MM): ";
        getline(cin, time);

        appointments.push_back(Appointment(appID, patID, docID, date, time));
        saveAppointmentsToFile();
        cout << "Appointment added successfully!\n";
    }
    //Displat all Appointments
    void displayAllAppointments() {
        if (appointments.empty()) {
            cout << "No Appointments found.\n";
            return;
        }
        cout << "\n=== List of Appointments ===\n";
        for (auto& a : appointments) {
            a.displayInfo();
        }
        cout << "=========================\n";
    }
    //search for Appointment
    void searchAppointment() {
        int searchId;
        cout << "Enter Patient or Doctor ID to search for appointments: ";
        cin >> searchId;

        bool found = false;
        for (auto& a : appointments) {
            if (a.getPatientID() == searchId || a.getDoctorID() == searchId) {
                a.displayInfo();
                found = true;
            }
        }
    }
    //cancel for Appointment
    void cancelAppointment() {
        int searchId;
        cout << "Enter Appointment ID to cancel: ";
        cin >> searchId;

        for (auto it = appointments.begin(); it != appointments.end(); ++it) {
            if (it->getAppointmentID() == searchId) {
                appointments.erase(it);
                saveAppointmentsToFile();
                cout << "Appointment canceled successfully!\n";
                return;
            }
        } cout << "Appointment not found.\n";
    }
    void menu() {
        int choice;
        while (true) {
            cout << "\n===== Appointment Management =====\n";
            cout << "1. Add Appointment\n";
            cout << "2. Display All Appointments\n";
            cout << "3. Search for Appointment\n";
            cout << "4. Cancel Appointment\n";
            cout << "5. Back to Main Menu\n";
            cout << "Enter your choice: ";
            cin >> choice; 

            switch (choice) { 
            case 1:
                addAppointment(); 
                break;
            case 2:
                displayAllAppointments();  
                break;
            case 3:
                searchAppointment(); 
                break;
            case 4:
                cancelAppointment(); 
                break;
            case 5:
                return; 
            default:
                cout << "Invalid choice! Please try again.\n";
            }
        }
    }

};
