#pragma once
#include"Person.h"
class Doctor : public Person {
private:
	string specialty;
public:
	//constractor
	Doctor() {
		this->specialty = " ";
	}
	Doctor(int id, int phone, string name, string specialty) :Person(id, phone, name){
		setSpecialty(specialty); 
	}
	//setter
	void setSpecialty(string specialty) {
		this->specialty = specialty;
	}
	//getter
	string getSpecialty() {
		return this->specialty;
	}
	void displayInfo(){
		cout << "Doctor Info ID: " << id
			<< "\n Name: " << name
			<< "\n Specialty: " << specialty
			<< "\n Phone: " << phone << endl;
	}
};