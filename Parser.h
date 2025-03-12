#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include<fstream> 
#include"Patient.h" 
#include"Doctor.h"
#include"Appointment.h"
#include"MedicalRecord.h"
using namespace std;
class Parser
{
public:
    static vector<string> split(string& line, char deli) {
        vector<string> tokens;
        stringstream ss(line);
        string token;
        while (getline(ss, token, deli)) {
            tokens.push_back(token);
        }
        return tokens;
    }
    static Patient parseToPatient(string& line) {
        vector<string> data = split(line, ',');
        if (data.size() !=5) {
            throw runtime_error("Invalid Patient data format.");
        }
        return Patient(stoi(data[0]), stoi(data[1]),data[2], stoi(data[3]),data[4]);
    }
    static Doctor parseToDoctor(string& line) {
        vector<string> data = split(line, ',');
        if (data.size() != 4) {
            throw runtime_error("Invalid Patient data format.");
        }
        return Doctor(stoi(data[0]), stoi(data[1]), data[2], data[3]);
    }
    static Appointment parseToAppointment(string& line) {
        vector<string> data = split(line, ',');
        if (data.size() != 4) {
            throw runtime_error("Invalid Patient data format.");
        }
        return Appointment(stoi(data[0]), stoi(data[1]), stoi(data[2]), data[3], data[4]);
    }
    static MedicalRecord parseToMedicalRecord(string& line) {
        vector<string> data = split(line, ',');
        if (data.size() != 6) {
            throw runtime_error("Invalid Patient data format.");
        }
        return MedicalRecord(stoi(data[0]), stoi(data[1]), data[2], data[3], stoi(data[4]), data[5]);
    }
};

