#pragma once
#include<iostream>
using namespace std;
class Appointment {
private:
    int appointmentID;
    int patientID;
    int doctorID;
    string date;
    string time;

public:
    //Constructors
    Appointment() {
        this->appointmentID = 0;
        this->patientID = 0;
        this->doctorID = 0;
        this->date = "Unknown";
        this->time = "Unknown";
    }
    Appointment(int appointmentID, int patientID, int doctorID, string date, string time) {
        setAppointmentID(appointmentID);
        setPatientID(patientID);
        setDoctorID(doctorID);
        setDate(date);
        setTime(time);
    }
    //setter
    void setAppointmentID(int appointmentID) {
        this->appointmentID = appointmentID;
    }
    void setPatientID(int patientID) {
        this->patientID = patientID;
    }
    void setDoctorID(int doctorID) {
        this->doctorID =doctorID;
    }
    void setDate(string data) {
        this->date = data; 
    }
    void setTime(string time) {
        this->time = time; 
    }
    //getter
    int getAppointmentID() { return this->appointmentID; }
    int getPatientID() { return this->patientID; }
    int getDoctorID() { return this-> doctorID; }
    string getDate() { return this-> date; }
    string getTime() { return this-> time; }
    //Display
    void displayInfo() {
        cout << "Appointment ID: " << appointmentID
            << ", Patient ID: " << patientID
            << ", Doctor ID: " << doctorID
            << ", Date: " << date
            << ", Time: " << time << endl;
    }
};