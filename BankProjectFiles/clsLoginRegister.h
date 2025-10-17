#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Libary C++ By oop/String.h"
#include "/Users/Mr.x/Desktop/Libary C++ By oop/Data_Lib.h"
#include "Global.h"

class clsLoginRegister
{
	string _Date_Time = "";
	string _UserName = "";
	string _Permission = "";
	string _Password = "";
 
	
static	void _AddToLogFile(string Text)
	{
	
	fstream LogFile;

	LogFile.open("Login_Register.txt", std::ios::app);


	if(LogFile.is_open())
	{
	
		LogFile << Text << endl;

	}
	LogFile.close();

	
	}

static clsLoginRegister _ConvertLineToRecord(vector <string> Data)
{
	clsLoginRegister clsData;

	 clsData._Date_Time = Data[0];
	 clsData._UserName = Data[1];
	 (clsData._Password) = Data[2];
     clsData._Permission = Data[3];
	
	 return clsData;

}
static vector <clsLoginRegister> _LoadDataFromLoginFile()
	{

		fstream MyFile;
		string Line = "";
		vector <clsLoginRegister> vDataLoginRegisterRecord;
		MyFile.open("Login_Register.txt", std::ios::in);

		if (MyFile.is_open())
		{

			while (getline(MyFile, Line))
			{
				vDataLoginRegisterRecord.push_back(_ConvertLineToRecord(clsString::clsStr_Splits_Fun::SplitStringRecord(Line, "#//#")));

			}

		}
		MyFile.close();


		return vDataLoginRegisterRecord;
	}

public:

	string GetDate_Time()
	{
	
		return _Date_Time;
	}
	string GetUserName()
	{

		return _UserName;
	}

	string GetPinCode()
	{

		return _Password;
	}

	string GetPermission()
	{

		return _Permission;
	}


	
	static vector <clsLoginRegister> GetDataRegister()
	{
	
		return	_LoadDataFromLoginFile();
	
	}
	static void Regist_LoginToSystem()
	{
		clsDate_Lib Date1;
		string Text = "";
		const string Dele = "#//#";
		Text = to_string(Date1.GetDay()) + "/" + to_string(Date1.GetMonth()) + "/" + to_string(Date1.GetYear()) + " - ";
		Text += Date1.GetSystemTime() + Dele;
		Text += (CurrentUser.GetUserName() + Dele + clsUtility::EncryptText(CurrentUser.Password, 55) + Dele) + to_string(CurrentUser.GetPermissions());
		_AddToLogFile(Text);
		Text = "";


	}


};

