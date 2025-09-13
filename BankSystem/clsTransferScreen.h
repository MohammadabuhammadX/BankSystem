#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTransferScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________\n";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

	static string _ReadAccountNumber() {

		string AccountNumber;

		cout << "\nPlease Enter Account Number To Transfer From: ";

		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {

			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		return AccountNumber;
	}

	static float ReadAmount(clsBankClient sourceClient) {

		float amount;

		cout << "\nEnter Transfer Amount? ";

		amount = clsInputValidate::ReadFloatNumber();

		while (amount > sourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount : ";
			amount = clsInputValidate::ReadFloatNumber();
		}

		return amount;
	}



public:

    static void ShowTransferScreen() {

        _DrawScreenHeader("\nTransfer Screen");

        clsBankClient sourseClinet = clsBankClient::Find(_ReadAccountNumber());

        _PrintClient(sourseClinet);

        string destinationAccNumber;
        do {
            cout << "\nPlease Enter Account Number To Transfer To: ";
            destinationAccNumber = clsInputValidate::ReadString();

            while (!clsBankClient::IsClientExist(destinationAccNumber)) {
                cout << "\nAccount number is not found, choose another one: ";
                destinationAccNumber = clsInputValidate::ReadString();
            }

            if (destinationAccNumber == sourseClinet.AccountNumber()) {
                cout << "\nYou cannot transfer to the same account, please enter a different one.\n";
            }

        } while (destinationAccNumber == sourseClinet.AccountNumber());

        clsBankClient destinationClinet = clsBankClient::Find(destinationAccNumber);

        _PrintClient(destinationClinet);

        // Read amount
        float amount = ReadAmount(sourseClinet);

        cout << "\nAre you sure you want to perform this operation ? y/n : ";
        char anwser = 'n';
        cin >> anwser;

        if (anwser == 'Y' || anwser == 'y') {
            if (sourseClinet.Transfer(amount, destinationClinet , sourseClinet.FullName())) {
                cout << "\nTransfer done successfully\n";
            }
            else {
                cout << "\nTransfer Faild \n";
            }
        }

        _PrintClient(sourseClinet);
        _PrintClient(destinationClinet);
    }


};

