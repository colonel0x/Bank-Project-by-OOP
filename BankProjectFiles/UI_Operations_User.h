#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankUser.h"
#include "Libary C++ By oop/clsInputValidate.h"

#include <iomanip>





class clsUI_Operations_User : protected clsScreen
{
    private:
        static void _PrintUsersRecordLine(clsUser User)
        {

            cout << setw(8) << left << "" << "| " << setw(12) << left << User.UserName;
            cout << "| " << setw(25) << left << User.FullName();
            cout << "| " << setw(12) << left << User.Phone;
            cout << "| " << setw(20) << left << User.Email;
            cout << "| " << setw(10) << left << User.Password;
            cout << "| " << setw(12) << left << User.Permissions;
            
        }
        static void _PrintUser(clsUser User)
        {
            cout << "\nUser Card:";
            cout << "\n___________________";
            cout << "\nFirstName   : " << User.FirstName;
            cout << "\nLastName    : " << User.LastName;
            cout << "\nFull Name   : " << User.FullName();
            cout << "\nEmail       : " << User.Email;
            cout << "\nPhone       : " << User.Phone;
            cout << "\nUser Name   : " << User.UserName;
            cout << "\nPassword    : " << User.Password;
            cout << "\nPermissions : " << User.Permissions;
            cout << "\n___________________\n";

        }
        
    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidation::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidation::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidation::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidation::ReadString();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidation::ReadString();

        cout << "\nEnter Permission: ";
        User.Permissions = _ReadPermissionsToSet();
    }

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        cout << "\nLogin Register Screen? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pLoginRegisterScreen;
        }
        return Permissions;

    }


    public:

       static void ShowUsersList()
        {
            vector <clsUser> vUsers = clsUser::GetUsersList();

            string Title = "\t  User List Screen";
            string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s).";

            _DrawScreenHeader(Title, SubTitle);

            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "______________________________________________\n" << endl;

            cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
            cout << "| " << left << setw(25) << "Full Name";
            cout << "| " << left << setw(12) << "Phone";
            cout << "| " << left << setw(20) << "Email";
            cout << "| " << left << setw(10) << "Password";
            cout << "| " << left << setw(12) << "Permissions";
            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "______________________________________________\n" << endl;

            if (vUsers.size() == 0)
                cout << "\t\t\t\tNo Users Available In the System!";
            else

                for (clsUser User : vUsers)
                {

                    _PrintUsersRecordLine(User);
                    cout << endl;
                }

            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "______________________________________________\n" << endl;
        }

       static void ShowAddNewUserScreen()
    {

        _DrawScreenHeader("\t  Add New User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidation::ReadString();
        while (clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName Is Already Used, Choose another one: ";
            UserName = clsInputValidation::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

        _ReadUserInfo(NewUser);
  
        clsUser::enSaveResults SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case  clsUser::enSaveResults::svSucceeded:
        {
            cout << "\nUser Addeded Successfully :-)\n";
            _PrintUser(NewUser);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError User was not saved because it's Empty";
            break;

        }
        case clsUser::enSaveResults::svFaildUserExists:
        {
            cout << "\nError User was not saved because UserName is used!\n";
            break;

        }
        }
    }

       static void ShowDeleteUserScreen()
       {

           _DrawScreenHeader("\tDelete User Screen");

           string UserName = "";

           cout << "\nPlease Enter UserName: ";
           UserName = clsInputValidation::ReadString();
           while (!clsUser::IsUserExist(UserName))
           {
               cout << "\nUser is not found, choose another one: ";
               UserName = clsInputValidation::ReadString();
           }

           clsUser User1 = clsUser::Find(UserName);
           _PrintUser(User1);

           cout << "\nAre you sure you want to delete this User y/n? ";

           char Answer = 'n';
           cin >> Answer;

           if (Answer == 'y' || Answer == 'Y')
           {

               if (User1.Delete())
               {
                   cout << "\nUser Deleted Successfully :-)\n";
                   _PrintUser(User1);
               }
               else
               {
                   cout << "\nError User Was not Deleted\n";
               }
           }
       }

       static void ShowUpdateUserScreen()
       {

           _DrawScreenHeader("\tUpdate User Screen");

           string UserName = "";

           cout << "\nPlease Enter UserName: ";
           UserName = clsInputValidation::ReadString();

           while (!clsUser::IsUserExist(UserName))
           {
               cout << "\nAccount number is not found, choose another one: ";
               UserName = clsInputValidation::ReadString();
           }

           clsUser User1 = clsUser::Find(UserName);

           _PrintUser(User1);

           cout << "\nAre you sure you want to update this User y/n? ";

           char Answer = 'n';
           cin >> Answer;

           if (Answer == 'y' || Answer == 'Y')
           {

               cout << "\n\nUpdate User Info:";
               cout << "\n____________________\n";


               _ReadUserInfo(User1);
              
               clsUser::enSaveResults SaveResult;

               SaveResult = User1.Save();

               switch (SaveResult)
               {
               case  clsUser::enSaveResults::svSucceeded:
               {
                   cout << "\nUser Updated Successfully :-)\n";

                   _PrintUser(User1);
                   break;
               }
               case clsUser::enSaveResults::svFaildEmptyObject:
               {
                   cout << "\nError User was not saved because it's Empty";
                   break;

               }

               }

           }

       }

       static void ShowFindUserScreen()
       {

           _DrawScreenHeader("\t  Find User Screen");

           string UserName;
           cout << "\nPlease Enter UserName: ";
           UserName = clsInputValidation::ReadString();
           while (!clsUser::IsUserExist(UserName))
           {
               cout << "\nUser is not found, choose another one: ";
               UserName = clsInputValidation::ReadString();
           }

           clsUser User1 = clsUser::Find(UserName);

           if (!User1.IsEmpty())
           {
               cout << "\nUser Found :-)\n";
           }
           else
           {
               cout << "\nUser Was not Found :-(\n";
           }

           _PrintUser(User1);

       }



};

