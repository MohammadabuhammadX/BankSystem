#pragma once
#include<iostream>
#include "person.h"
#include "Employee.h"

using namespace std;
class Developer : public Employee {

	string _mainProgrammingLanguage;

public:

	Developer(short Id, string firstName, string lastName, string email, string phone, string title, string department,
		float salary, string mainProgrammingLanguage)
		:Employee(Id, firstName, lastName, email, phone, title, department, salary)
	{
		_mainProgrammingLanguage = mainProgrammingLanguage;
	}

	void setMainProgrammingLanguage(string programmingLanguage) {

		_mainProgrammingLanguage = programmingLanguage;

	}

	string getMainProgramminLanguage() {
		return _mainProgrammingLanguage;
	}

	void Print()
	{
		cout << "\nInfo:";         cout << "\n___________________";
		cout << "\nID        : " << getUserId();
		cout << "\nFirstName : " << getFirstName();
		cout << "\nLastName  : " << getLastName();
		cout << "\nFull Name : " << getFullName();
		cout << "\nEmail     : " << getEmail();
		cout << "\nPhone     : " << getPhoneNumber();
		cout << "\nTitle     : " << getTitle();
		cout << "\nDepartment: " << getDepartment();
		cout << "\nSalary    : " << getSalary();
		cout << "\nPLanguage : " << getMainProgramminLanguage();
		cout << "\n___________________\n";
	}

};

class Developer
{
};


