#pragma once
#include<iostream>

using namespace std;

class Person {

private:
	short _userId;
	string _firstName;
	string _lastName;
	string _email;
	string _phoneNumber;

	struct stAddress
	{
		string AddressLine1;
		string AddressLine2;
		string City;
		string Country;
	};

public:

	Person(short Id, string firstName, string lastName, string email, string phoneNumber)
	{
		_userId = Id;
		_firstName = firstName;
		_lastName = lastName;
		_email = email;
		_phoneNumber = phoneNumber;
	}

	short getUserId() {

		return _userId;

	}

	void setFirstName(string firstName) {

		_firstName = firstName;
	}

	string getFirstName() {
		return _firstName;
	}

	void setLastName(string lastName) {

		_lastName = lastName;

	}

	string getLastName() {

		return _lastName;

	}

	string getFullName() {

		return _firstName + " " + _lastName;

	}

	void setEmail(string email) {

		_email = email;

	}

	string getEmail() {

		return _email;

	}

	void setPhoneNumber(string phoneNum) {

		_phoneNumber = phoneNum;

	}

	string getPhoneNumber() {

		return _phoneNumber;

	}

	void Print() {
		cout << "\nInfo :" << endl;
		cout << "_____________________________" << endl;
		cout << "User Id : " << _userId << endl;
		cout << "First Name : " << _firstName << endl;
		cout << "Last Name : " << _lastName << endl;
		cout << "Full Name : " << _firstName << " " << _lastName << endl;
		cout << "Email : " << _email << endl;
		cout << "Phone Number : " << _phoneNumber << endl;
		cout << "_____________________________";
	}

	void sendEmail(string subject, string message) {

		cout << "\n\nThe following message sent successfully to email :" << _email << endl;

		cout << "Subject :" << subject << endl;
		cout << "Body :" << message << endl;

	}

	void sendSMS(string message) {

		cout << "\n\nThe following message sent successfully to Phone Number :" << _phoneNumber << endl;

		cout << message << endl;

	}

	stAddress Address;

};

