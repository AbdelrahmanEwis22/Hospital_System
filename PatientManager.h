#pragma once
#include "Patient.h"
#include<vector>
#include <fstream>
#include <sstream>
#include"Parser.h"
#include<iostream>
using namespace std;
class PatientManager
{
private:
	vector<Patient>patients;
public:
	vector<Patient>& getPatients() { return patients; } 
	/*void createFileIfNotExists() {
		ifstream file("patients.txt");
		if (!file) {
			cout << "File 'patients.txt' does not exist. Creating a new one...\n";
			ofstream newFile("patients.txt");
			if (!newFile) {
				cerr << "Error: Failed to create 'patients.txt'.\n";
				return;
			}
			newFile.close();
			cout << "File 'patients.txt' created successfully.\n";
		}
		else {
			cout << "File 'patients.txt' already exists.\n";
		}
	}*/
	// Load patients from file when the program starts
	void loadPatientsFromFile() {
		fstream file("patients", ios::in | ios::out | ios::app);
		if (file.is_open()) {
			string line;
			while (getline(file,line))
			{
				try {
					Patient p = Parser::parseToPatient(line);
					patients.push_back(p);
				}
				catch (const runtime_error& e)
				{
					cerr << "Skipping invalid line: " << line << " -> " << e.what() << endl;
				}
			}file.close();
		}
	}
	//save patient to file
	void savePatientToFile() {
		fstream file("patients",ios::out);
		if (!file.is_open())
		{
			cout << "Error: Canot open file for write" << endl;
		}
		for (auto& p : patients) {
			file << p.getId() << ','
				<< p.getPhone() << ','
				<< p.getName() << ','
				<< p.getAge() << ','
				<< p.getDisease() << endl;
		}file.close();
	}
	//add new patient
	void addPatients() {
		int id, age, phone; 
		string name, disease; 

		cout << "Enter Patient ID: ";
		cin >> id;
		cin.ignore();
		cout << "Enter Name: ";
		getline(cin, name);
		cout << "Enter Age: ";
		cin >> age;
		cin.ignore();
		cout << "Enter Disease: ";
		getline(cin, disease);
		cout << "Enter Phone: ";
		cin >> phone;

		patients.push_back(Patient(id, phone, name, age, disease));
		savePatientToFile(); 
		cout << "Patient added successfully!\n";
	}
	//Display all Patients
	void displayAllPatients() {
		if (patients.empty()) {
			cout << " No Patients found.\n"; 
			return;
		}

		cout << "\n=== List of Patients ===\n";
		for (auto& p : patients) {
			p.displayInfo(); 
		}
		cout << "=========================\n"; 
	}
	//Search for a patient by ID
	void searchPatient() {
		int searchId{};
		cout << "Enter Patient Id:\n ";
		cin >> searchId;
		for (auto& p : patients) {
			if (p.getId() == searchId)
			{
				p.displayInfo();
				return;
			}
		}cout<< "Patient not found.\n";
	}
	//delet all patients
	void clearPatientsFile() {
		ofstream file("patients.txt", ios::trunc); 
		if (!file.is_open()) {
			cerr << "Error: Cannot open file for clearing.\n";
			return;
		}

		file.close();
		patients.clear(); 
		cout << "All patient records have been deleted.\n";
	}
	void updatePatient() {
		int searchId;
		cout << "Enter Patient ID to update: ";
		cin >> searchId;

		for (auto& p : patients) {
			if (p.getId() == searchId) {
				cout << "Updating details for: " << p.getName() << endl;

				int newAge, newPhone;
				string newName, newDisease;

				cout << "Enter new Name (or press Enter to keep current: " << p.getName() << "): ";
				cin.ignore();
				getline(cin, newName);
				if (!newName.empty()) p.setName(newName);

				cout << "Enter new Age (or -1 to keep current: " << p.getAge() << "): ";
				cin >> newAge;
				if (newAge != -1) p.setAge(newAge);

				cout << "Enter new Disease (or press Enter to keep current: " << p.getDisease() << "): ";
				cin.ignore();
				getline(cin, newDisease);
				if (!newDisease.empty()) p.setDisease(newDisease);

				cout << "Enter new Phone number (or -1 to keep current: " << p.getPhone() << "): ";
				cin >> newPhone;
				if (newPhone != -1) p.setPhone(newPhone);

				savePatientToFile(); 
				cout << "Patient updated successfully!\n";
				return;
			}
		}
		cout << "Patient not found.\n";
	}
	void menu(PatientManager& pm) {
		int choice;
		while (true) {
			cout << "\n===== Hospital Management System =====\n";
			cout << "1. Add Patient\n";
			cout << "2. Display All Patients\n";
			cout << "3. Search for Patient by ID\n";
			cout << "4. Delet All Patients\n";
			cout << "5. update Patients By Id\n";
			cout << "6. Back to Main Menu\n";
			cout << "Enter your choice: ";
			cin >> choice;

			switch (choice) {
			case 1:
				pm.addPatients(); // Call the add patient function
				break;
			case 2:
				pm.displayAllPatients(); // Call the function to display patients
				break;
			case 3:
				pm.searchPatient(); // Call the function to search for a patient
				break;
			case 4:
				pm.clearPatientsFile();
				break;
			case 5:
				pm.updatePatient();
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

