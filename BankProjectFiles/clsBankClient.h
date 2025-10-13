#pragma once
#include <iostream>
#include <string>
#include "Libary C++ By oop/String.h"
#include "Libary C++ By oop/clsUtil.h"
#include "clsPerson.h"

#include <vector>
#include <fstream>
using namespace std;


class clsBankClient :public clsPerson
{
	private:

		enum enMode { Empty = 0, UpdateMode = 1,AddNewMode = 2 };;
		enMode _Mode;


		string _AccountNumber;
		string _PinCode;
		float _AccountBalance;
		bool _MarkForDelete = false;

		static clsBankClient _ConvertLineClientToObject(string Line,string Seperator = "#//#") 
		{
		
			vector<string> vClientData;
			vClientData = clsString::clsStr_Splits_Fun::SplitStringRecord(Line,Seperator);

			return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3],
				vClientData[4], vClientData[5], stod(vClientData[6]));
		
		}
		static string _ConvertObjectClientToLine(clsBankClient Info, string Seperator = "#//#")
		{

			string stClientRecord = "";
			stClientRecord += Info.FirstName + Seperator;
			stClientRecord += Info.LastName + Seperator;
			stClientRecord += Info.Email + Seperator;
			stClientRecord += Info.Phone+ Seperator;
			stClientRecord += Info.GetAccountNumber() + Seperator;
			stClientRecord += Info.PinCode + Seperator;
			stClientRecord += to_string(Info.AccountBalance);
			return stClientRecord;


		}
		static clsBankClient _GetEmpty()
		{
		
			return clsBankClient(enMode::Empty, "", "", "", "", "", "", 0);
		}
		static 	vector <clsBankClient> _LoadClientDataFromFile()
		{

			vector <clsBankClient>vClient;
			fstream MyFile;
			MyFile.open("Clients.txt", ios::in);

			if (MyFile.is_open()) {

				string Line = "";
				while(getline(MyFile,Line))
				{
				
				
					clsBankClient Client = _ConvertLineClientToObject(Line);
					vClient.push_back(Client);
				
				}
				MyFile.close();
			}	

			return vClient;
		}
		static void _SaveClientsDataToFile(vector <clsBankClient>vClients)
		{
		
		
			
			fstream MyFile;
			MyFile.open("Clients.txt", ios::out);

			string DataLine = "";

			if (MyFile.is_open()) {

				for(clsBankClient C:vClients)
				{

					if (C._MarkForDelete == false)
					{
					

						DataLine = _ConvertObjectClientToLine(C);
						MyFile << DataLine << endl;
					}

				}


				MyFile.close();
			}


		
		
		
		
		}
	
		void _Update()
		{
		
			vector <clsBankClient> _vClient;
			_vClient = _LoadClientDataFromFile();

			for (clsBankClient& C : _vClient)
			{

				if (C.GetAccountNumber() == GetAccountNumber())
				{
					C = *this;
					break;
				
				}

			}
				_SaveClientsDataToFile(_vClient);
		}
		void _AddDataLineToFile(string  stDataLine)
		{
			fstream MyFile;
			MyFile.open("Clients.txt", ios::out | ios::app);

			if (MyFile.is_open())
			{

				MyFile << stDataLine << endl;

				MyFile.close();
			}

		}
		void _AddNew() 
		{

			_AddDataLineToFile(_ConvertObjectClientToLine(*this));
		}
	

public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone,string AccountNumber,string PinCode,
		float AccountBalance):
	clsPerson( FirstName,  LastName,  Email,  Phone)
	{
	
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	

	}


	bool IsEmpty() {


		return (_Mode == enMode::Empty);

	}

  string GetAccountNumber()
	{
	
	
		return _AccountNumber;
	}
//  __declspec(property(get = GetPinCode)) string AccountNumber;

	void SetPinCode(string PinCode)
	{
	

		_PinCode = PinCode;
	
	}
	string GetPinCode()
	{

		return _PinCode;
	};
	
	__declspec(property(put = SetPinCode, get = GetPinCode)) string PinCode;


	void SetAccountBalance(float AccountBalance)
	{


		_AccountBalance = AccountBalance;

	}
	float GetAccountBalance()
	{

		return _AccountBalance;
	};

	__declspec(property(put = SetAccountBalance, get = GetAccountBalance)) float AccountBalance;




	static clsBankClient Find(string AccountNumber)
	{
		vector <clsBankClient> vClients;

		fstream MyFile; 
		MyFile.open("Clients.txt", ios::in);


		if (MyFile.is_open())
		{
			string Line; 

			while (getline(MyFile,Line)) 
			{

				clsBankClient Client =_ConvertLineClientToObject(Line);
				if (Client.GetAccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}


			}

		}
		MyFile.close();
		return _GetEmpty();
	}
	static clsBankClient Find(string AccountNumber,string Password)
	{
		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);


		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{

				clsBankClient Client = _ConvertLineClientToObject(Line);
				if (Client.GetAccountNumber() == AccountNumber && Client.GetPinCode() == Password)
				{
					MyFile.close();
					return Client;
				}


			}

		}
		MyFile.close();
		return _GetEmpty();
	}

	static bool IsAccountExist(string AccountNumber) {


		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return(!Client.IsEmpty());	

	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1 ,FailAccountNumberExist =2};

	enSaveResults Save()
	{
	
		switch (_Mode)
		{

		case enMode::Empty:
		{
			return
				enSaveResults::svFaildEmptyObject;
		}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
			break;
		}

		case enMode::AddNewMode:
			if (clsBankClient::IsAccountExist(_AccountNumber))
			{
				return enSaveResults::FailAccountNumberExist;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}


		};
	
	}
	static	clsBankClient GetAddNewClientObject(string AccountNumber)
	{
	
	
		return clsBankClient(enMode::AddNewMode, "", "", "", "",AccountNumber, "", 0);

	
	
	}
	bool Delete()
	{
	
		vector <clsBankClient> _vClient;
		_vClient = _LoadClientDataFromFile();

		for (clsBankClient& C : _vClient)
		{
		
			if (C.GetAccountNumber() == _AccountNumber)
			{
				C._MarkForDelete = true;
				break;
			}

		}
		_SaveClientsDataToFile(_vClient);
		*this = _GetEmpty();
		return true;
		
	}
	static vector<clsBankClient>GetClientList()
	{

		return _LoadClientDataFromFile();

	}
	static double GetTotalBalances()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientList();

		double TotalBalances = 0;
		for(clsBankClient Client: vClients)
		{
		
			TotalBalances += Client.AccountBalance;

		
		}

		return TotalBalances;


	}
	void Deposit(double Amount) 
	{
		_AccountBalance += Amount;
		Save();
	}
	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;

		}
		else
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}
		}
     void TransferAmount( clsBankClient TO_Client_2,float Amount_Transfer)
	{
		// (this) == FROM_CLIENT_1; 
		 this->AccountBalance -= Amount_Transfer;

		TO_Client_2.AccountBalance += Amount_Transfer;

		Save();
		TO_Client_2.Save();


	}













};

