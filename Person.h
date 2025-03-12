#pragma once
#include<string>
#include<iostream>
using namespace std;
class Person
{
protected: 
	int id,phone;
	string name;
public:
	//constractor deufalt
	Person() {
		this-> id = 0;
		this-> phone = 0;
		this-> name = " ";
	}
	//constractor
	Person(int id,int phone,string name) {
		setId(id);
		setPhone(phone);
		setName(name);
	}
	//setter
	void setId(int id) {
		this->id = id;
	}
	void setPhone(int phone) {
		this->phone = phone;
	}
	void setName(string name) {
		this->name = name;
	}
	//getter
	int getId() {
		return this->id;
	}
	int getPhone() { 
		return this->phone;
	}
	string getName() {
		return this->name;
	}
};

