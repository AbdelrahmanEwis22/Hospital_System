#pragma once
#include"MedicalRecord.h"
#include<vector>
#include <sstream>
#include<fstream>
#include"Parser.h"
using namespace std;
class MedicalRecordManager
{
private:
	vector<MedicalRecord> records;
public:
    vector<MedicalRecord>& getRecords() { return records; } 
    //Load doctors from file when the program starts
    void loadDoctorsFromFile() {
        fstream file("medical_records.txt", ios::in | ios::out | ios::app);
        if (file.is_open()) {
            string line;
            while (getline(file, line))
            {
                try {
                    MedicalRecord a = Parser::parseToMedicalRecord(line);
                    records.push_back(a);
                }
                catch (const runtime_error& e)
                {
                    cerr << "Skipping invalid line: " << line << " -> " << e.what() << endl;
                }
            }file.close();
        }
    }
    void saveRecordsToFile() {
        ofstream file("medical_records.txt", ios::out);
        if (!file.is_open()) {
            cerr << "Error: Cannot open medical_records.txt for writing.\n";
            return;
        }

        for (auto& r : records) {
            file << r.getRecordID() << "," 
                << r.getPatientID() << ","
                << r.getDiagnosis() << "," 
                << r.getTreatment() << ","
                << r.getDoctorID() << "," 
                << r.getDate() << endl;
        }
        file.close();
        cout << "Medical records saved successfully.\n";
    }

    
    void addRecord() {
        int recID, patID, docID;
        string diagnosis, treatment, date;

        cout << "Enter Record ID: ";
        cin >> recID;
        cout << "Enter Patient ID: ";
        cin >> patID;
        cin.ignore();
        cout << "Enter Diagnosis: ";
        getline(cin, diagnosis);
        cout << "Enter Treatment: ";
        getline(cin, treatment);
        cout << "Enter Doctor ID: ";
        cin >> docID;
        cin.ignore();
        cout << "Enter Date (YYYY-MM-DD): ";
        getline(cin, date);

        records.push_back(MedicalRecord(recID, patID, diagnosis, treatment, docID, date));
        saveRecordsToFile();
        cout << "Medical record added successfully!\n";
    }
    //dispaly Records By Patient
    void displayRecordsByPatient() {
        int searchId;
        cout << "Enter Patient ID to view records: ";
        cin >> searchId;

        bool found = false;
        for (auto& r : records) {
            if (r.getPatientID() == searchId) {
                r.displayInfo();
                found = true;
            }
        }

        if (!found) cout << "No records found for this patient.\n";
    }
    //update a records
    void updateRecord() {
        int searchId;
        cout << "Enter Record ID to update: ";
        cin >> searchId;

        for (auto& r : records) {
            if (r.getRecordID() == searchId) {
                cout << "Updating record for Patient ID: " << r.getPatientID() << endl;

                string newDiagnosis, newTreatment;
                cout << "Enter new Diagnosis (or press Enter to keep current): ";
                cin.ignore();
                getline(cin, newDiagnosis);
                if (!newDiagnosis.empty()) r.setDiagnosis(newDiagnosis);

                cout << "Enter new Treatment (or press Enter to keep current): ";
                getline(cin, newTreatment);
                if (!newTreatment.empty()) r.setTreatment(newTreatment);

                saveRecordsToFile();
                cout << "Medical record updated successfully!\n";
                return;
            }
        }
        cout << "Record not found.\n";
    }
    //delete a Records
    void deleteRecord() {
        int searchId;
        cout << "Enter Record ID to delete: ";
        cin >> searchId;

        for (auto it = records.begin(); it != records.end(); ++it) {
            if (it->getRecordID() == searchId) {
                records.erase(it);
                saveRecordsToFile();
                cout << "Medical record deleted successfully!\n";
                return;
            }
        }

        cout << "Record not found.\n";
    }

    //Menu for MediaclRecords
    void menu() {
        int choice;
        while (true) {
            cout << "\n===== Medical Record Management =====\n";
            cout << "1. Add Medical Record\n";
            cout << "2. Display Records by Patient\n";
            cout << "3. Update Medical Record\n";
            cout << "4. Delete Medical Record\n";
            cout << "5. Back to Main Menu\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecordsByPatient();
                break;
            case 3:
                updateRecord();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                return;
            default:
                cout << "Invalid choice! Please try again.\n";
            }
        }
    }
};

