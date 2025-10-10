#pragma once
#include <iostream>
#include "Global.h"
#include "/Users/Mr.x/Desktop/Libary C++ By oop/Data_Lib.h"
using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        clsDate_Lib Date;
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\t\t\t\t\tUser: " << CurrentUser.UserName;
        cout << "\n\t\t\t\t\t" << "Date: " << Date.GetDay() << "/" << Date.GetMonth() << "/" << Date.GetYear() << endl;



    }

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }
};

