#pragma once
#include<iostream>
#include "person.h"

using namespace std;

class Employee : public Person {

private:
	string _title;
	float _salary;
	string _department;

public:

	Employee(int Id, string firstName, string lastName, string email, string phone,
		string title, string department, float salary)
		: Person(Id, firstName, lastName, email, phone)
	{
		_title = title;
		_department = department;
		_salary = salary;
	}

	void setTitle(string title) {
		_title = title;
	}

	string getTitle() {
		return _title;
	}

	void setSalary(float salary) {
		_salary = salary;
	}

	float getSalary() {
		return _salary;
	}

	void setDepartment(string department) {

		_department = department;

	}

	string getDepartment() {
		return _department;
	}

	void Print() {
		cout << "\n--- Employee Information ---" << endl;
		cout << "ID: " << getUserId() << endl;
		cout << "Name: " << getFullName() << endl;
		cout << "Email: " << getEmail() << endl;
		cout << "Phone: " << getPhoneNumber() << endl;
		cout << "Title: " << _title << endl;
		cout << "Department: " << _department << endl;
		cout << "Salary: " << _salary << endl;
		cout << "----------------------------" << endl;
	}


};

