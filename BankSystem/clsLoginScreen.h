#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:

    static bool _Login()
    {

        bool LoginFaild = false;

        short faildLoginCounter = 0;

        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                faildLoginCounter++;

                cout << "\nInvlaid Username/Password!\n\n";
                cout << "\nYou have " << (3 - faildLoginCounter)
                    << "Trial(s) to login. \n\n";
            }
            if (faildLoginCounter == 3) {

                cout << "\nYour are locked after 3 falid trails \n\n";
                return false;

            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:

    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();

    }
};
