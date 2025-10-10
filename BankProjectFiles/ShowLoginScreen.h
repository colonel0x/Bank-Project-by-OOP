#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsBankUser.h"
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:


    static void _WarningScreen(short CounterNumber)
    {
        cout << "\nInvlaid Username/Password!\n";
        cout << "You have " << CounterNumber << " Trails to login.\n" << endl;

    }


    static  void _Login()
    {
        bool LoginFaild = false;
        short FailLoginCount = 2;
        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                _WarningScreen(FailLoginCount);
                FailLoginCount--;
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild && FailLoginCount != 0);

        if (!LoginFaild)
        {
            clsMainScreen::ShowMainMenue();
            FailLogin = true;
        }
        else
        {
            FailLogin = false;
            cout << "\nyou are locked after 3 faild trails.\n";
        }

    }


public:


    static void ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        _Login();

    }

};

