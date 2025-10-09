#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "Libary C++ By oop/clsInputValidate.h"
#include "Libary C++ By oop/clsUtil.h"
#include "Libary C++ By oop/String.h"
#include "UI_Operations_Client.h"
#include "clsScreen.h"
#include "clsBankUser.h"
#include <iomanip>
#include <vector>
class clsUI_Operations : protected clsScreen
{
static void _PrintClientRecordLine(clsBankClient Client)
	{
	cout << setw(8) << left << "" << "| " << setw(15) << left << Client.GetAccountNumber();
	cout << "| " << setw(20) << left << Client.FullName();
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(20) << left << Client.Email;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(12) << left << Client.AccountBalance;

	}
static void _PrintClientRecordBalanceLine(clsBankClient Client)
	{

		cout << "| " << setw(15) << left << Client.GetAccountNumber();
		cout << "| " << setw(40) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.AccountBalance;

	}
static void _Print(clsBankClient Client)
{


	cout << clsUtility::Tab(5) << "Client Card:";
	cout << clsUtility::Tab(5) << "_____________________";
	cout << clsUtility::Tab(5) << "FirstName       :" << Client.FirstName;
	cout << clsUtility::Tab(5) << "LastName        :" << Client.LastName;
	cout << clsUtility::Tab(5) << "FullName        :" << Client.FullName();
	cout << clsUtility::Tab(5) << "Email           :" << Client.Email;
	cout << clsUtility::Tab(5) << "Phone           :" << Client.Phone;
	cout << clsUtility::Tab(5) << "Acc. Number     :" << Client.GetAccountNumber();
	cout << clsUtility::Tab(5) << "Password        :" << Client.PinCode;
	cout << clsUtility::Tab(5) << "Balance         :" << Client.AccountBalance;
	cout << clsUtility::Tab(5) << "_____________________\n";
}


public:
static	void ReadClientInfo(clsBankClient& Client)
	{


		cout << clsUtility::Tab(5) << "Enter First Name: ";
		Client.FirstName = clsInputValidation::ReadString();

		cout << clsUtility::Tab(5) << "\Enter Last Name: ";
		Client.LastName = clsInputValidation::ReadString();

		cout << clsUtility::Tab(5) << "Enter Email: ";
		Client.Email = clsInputValidation::ReadString();

		cout << clsUtility::Tab(5) << "Enter Phone: ";
		Client.Phone = clsInputValidation::ReadString();

		cout << clsUtility::Tab(5) << "Enter Pin Code: ";
		Client.PinCode = clsInputValidation::ReadString();

		cout << clsUtility::Tab(5) << "Enter Account Balance: ";
		Client.AccountBalance = clsInputValidation::ReadFloatNumber();







	}
static	void UpdateClient()
	{
	if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
	{
		return;
	}
	

		string AccountNumber = "";

		string Title = "\t Update Client Client Screen";
		_DrawScreenHeader(Title);


		cout << "Please enter ClientAccount Number: ";
		AccountNumber = clsInputValidation::ReadString();

		while (!clsBankClient::IsAccountExist(AccountNumber))
		{

			cout << "\nAccount number not found, choose another one: ";
			AccountNumber = clsInputValidation::ReadString();

		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_Print(Client1);

		cout <<clsUtility::Tab(5)<< "Update client Info: ";
		cout << clsUtility::Tab(5) << "_________________________\n";

		ReadClientInfo(Client1);

		clsBankClient::enSaveResults  SaveResult;
		SaveResult = Client1.Save();

		switch (SaveResult)
		{

		case clsBankClient::enSaveResults::svSucceeded:
			cout << "\nAccount Updated Succesfully :-)\n";
			_Print(Client1);
			break;

		case clsBankClient::enSaveResults::svFaildEmptyObject:
			cout << "\nError account was not saved because it empty!!\n";
			break;

		}





	}
static	void AddNewClient()
	{

	if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
	{
		return;
	}

		string AccountNumber = "";

		string Title = "\t Add New Client Screen";
		_DrawScreenHeader(Title);


		cout << clsUtility::Tab(5) << "Please enter ClientAccount Number: ";
		AccountNumber = clsInputValidation::ReadString();

		while (clsBankClient::IsAccountExist(AccountNumber))
		{

			cout << clsUtility::Tab(5) << "\nAccount number Already Used, choose another one: ";
			AccountNumber = clsInputValidation::ReadString();

		}

		clsBankClient GetNewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		
		cout << clsUtility::Tab(5) << "Add new client Info: \n";
		cout << clsUtility::Tab(5) << "______________________________________\n";

		ReadClientInfo(GetNewClient);

		clsBankClient::enSaveResults  SaveResult;

		SaveResult = GetNewClient.Save();
			

		switch (SaveResult)
		{

		case clsBankClient::enSaveResults::svSucceeded:
			cout << clsUtility::Tab(5) << "Account Added Successfully :-)\n";
			_Print(GetNewClient);
			break;

		case clsBankClient::enSaveResults::svFaildEmptyObject:
			cout << clsUtility::Tab(5) << "Error account was not saved because it empty!!\n";
			break;

		case clsBankClient::enSaveResults::FailAccountNumberExist:
			cout << clsUtility::Tab(5) << "\nError account was not saved because Account exist!!\n";
			break;
		}


	};
static	void DeleteClient()
	{
	
	if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
	{
		return;
	}
		string AccountNumber = "";


		string Title = "\t Delete Client Screen";
		_DrawScreenHeader(Title);


		cout << "Please enter ClientAccount Number: ";
		AccountNumber = clsInputValidation::ReadString();
		while (!clsBankClient::IsAccountExist(AccountNumber))
		{

			cout << "\nAccount number not found, choose another one: ";
			AccountNumber = clsInputValidation::ReadString();

		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_Print(Client1);

		

		//cout << "\n\033 Are sure want delete this client y/n\033[0m\n\n";
		cout << "\n\33[31mAre you sure you want to delete this client? y/n\033[0m\n\n";
		char Answer = 'n';
		cin >> Answer;
	

		if (Answer == 'y' || Answer == 'Y')
		{
			if(Client1.Delete())
			{
			
				cout << "\nClient Deleted Successfully\n";
					_Print(Client1);
			} else
			{
				cout << "\nError Client Was not Deleted!!";
			}
		}
	
	
	}
static	void ShowClientList()
	{


	if (!CheckAccessRights(clsUser::enPermissions::pListClients))
	{
		return;
	}

		vector <clsBankClient> vClients = clsBankClient::GetClientList();
		string Title = "\t Client List Screen";
		string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s)\n";
	 

		_DrawScreenHeader(Title,SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;



		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsBankClient Client : vClients)
			{

				_PrintClientRecordLine(Client);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;






	}
static	void ShowTotalBalances()
	{

		vector <clsBankClient> vClients = clsBankClient::GetClientList();

		cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		double TotalBalances = clsBankClient::GetTotalBalances();

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsBankClient Client : vClients)
			{
				_PrintClientRecordBalanceLine(Client);
				cout << endl;
			}

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
		cout << "\t\t\t\t\t   ( " << clsUtility::NumberToText(TotalBalances) << ")" << endl;
	}
static  void ShowFindClientScreen()
{
	if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
	{
		return;
	}

	_DrawScreenHeader("\tFind Client Screen");

	string AccountNumber;
	cout << "\nPlease Enter Account Number: ";
	AccountNumber = clsInputValidation::ReadString();
	while (!clsBankClient::IsAccountExist(AccountNumber))
	{
		cout << "\nAccount number is not found, choose another one: ";
		AccountNumber = clsInputValidation::ReadString();
	}

	clsBankClient Client1 = clsBankClient::Find(AccountNumber);

	if (!Client1.IsEmpty())
	{
		cout << "\nClient Found :-)\n";
	}
	else
	{
		cout << "\nClient Was not Found :-(\n";
	}

	_Print(Client1);




}


class clsTransActionMenue : protected clsScreen {


private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.GetAccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease enter AccountNumber? ";
		cin >> AccountNumber;
		return AccountNumber;
	}

   static void _PrintClientRecordBalanceLine(clsBankClient Client)
    {
        cout << setw(25) << left << "" << "| " << setw(15) << left << Client.GetAccountNumber();
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;
    }
public:

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\t   Deposit Screen");

		string AccountNumber = _ReadAccountNumber();


		while (!clsBankClient::IsAccountExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		double Amount = 0;
		cout << "\nPlease enter deposit amount? ";
		Amount = clsInputValidation::ReadDblNumber();

		cout << "\nAre you sure you want to perform this transaction? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			Client1.Deposit(Amount);
			cout << "\nAmount Deposited Successfully.\n";
			cout << "\nNew Balance Is: " << Client1.AccountBalance;

		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}

	}

	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\t   Withdraw Screen");

		string AccountNumber = _ReadAccountNumber();


		while (!clsBankClient::IsAccountExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);


		double Amount = 0;
		cout << "\nPlease enter Withdraw amount? ";
		Amount = clsInputValidation::ReadDblNumber();

		cout << "\nAre you sure you want to perform this transaction? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (Client1.Withdraw(Amount))
			{
				cout << "\nAmount Withdrew Successfully.\n";
				cout << "\nNew Balance Is: " << Client1.AccountBalance;
			}
			else
			{
				cout << "\nCannot withdraw, Insuffecient Balance!\n";
				cout << "\nAmout to withdraw is: " << Amount;
				cout << "\nYour Balance is: " << Client1.AccountBalance;

			}
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}

	}
	
    static void ShowTotalBalances()
    {

        vector <clsBankClient> vClients = clsBankClient::GetClientList();

        string Title = "\t  Balances List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(25) << left << "" << "\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {
                _PrintClientRecordBalanceLine(Client);
                cout << endl;
            }

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;
        
        cout << setw(8) << left << "" << "\t\t\t\t\t\t\t     Total Balances = " << TotalBalances << endl;
        cout << setw(8) << left << "" << "\t\t\t\t  ( " << clsUtility::NumberToText(TotalBalances) << ")";
    }


};



};
