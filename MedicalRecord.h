#pragma once
#include <iostream>
using namespace std;
class MedicalRecord
{
private:
    int recordID;
    int patientID;
    string diagnosis;
    string treatment;
    int doctorID;
    string date;
public:
    //constractor
    MedicalRecord() {
        this->recordID = 0;
        this->patientID = 0;
        this->diagnosis = " ";
        this->treatment = " ";
        this->doctorID = 0;
        this->date = "Unknown";
    }
    MedicalRecord(int recordID, int patientID, string diagnosis, string treatment, int doctorID, string date) {
            setRecordID(recordID);
            setPatientID(patientID);
            setDiagnosis(diagnosis);
            setTreatment(treatment);
            setDoctorID(doctorID);
            setDate(date);
    }
    //setter
    void setRecordID(int recordID) {
        this->recordID = recordID;
    }
    void setPatientID(int patientID) {
        this->patientID = patientID;
    }
    void setDiagnosis(string diagnosis) {
        this->diagnosis = diagnosis;
    }
    void setTreatment(string treatment) {
        this->treatment = treatment;
    }
    void setDoctorID(int doctorID) {
        this->doctorID = doctorID;
    }
    void setDate(string date) {
        this->date = date;
    }
    // Getters
    int getRecordID() { return this-> recordID; }
    int getPatientID() { return this-> patientID; }
    string getDiagnosis() { return this -> diagnosis; }
    string getTreatment() { return this -> treatment; }
    int getDoctorID() { return this-> doctorID; }
    string getDate() { return this-> date; }
    //methods
    void displayInfo() {
        cout << "Record ID: " << recordID
            << ", Patient ID: " << patientID
            << ", Diagnosis: " << diagnosis
            << ", Treatment: " << treatment
            << ", Doctor ID: " << doctorID
            << ", Date: " << date << endl;
    }
};

