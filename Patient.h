#pragma once
#include"Person.h"
#include"search.h"
using namespace std;
class Patient : public Person
{
private:
	int age;
	string disease;
public:
	//constrator
	Patient() {
		this->age = 0;
		this->disease = " ";
	}
	Patient(int id,int phone,string name,int age,string disease):Person(id,phone,name) {
		setAge(age);
		setDisease(disease);
	}
	//setter
	void setAge(int age) {
		this->age = age;
	}
	void setDisease(string disease) {
		this->disease = disease;
	}
	//getter
	int getAge() {
		return this->age;
	}
	string getDisease() {
		return this->disease;
	}
	//Methods
	void displayInfo() {
		cout << "Patient info ->Id: " << id
			<< "\n Name: " << name
			<< "\n Phone: " << phone
			<< "\n Age: " << age
			<< "\n Disease: " << disease << endl;
	}

};