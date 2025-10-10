#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Libary C++ By oop/String.h"
#include "Libary C++ By oop/Data_Lib.h"
#include "Global.h"
class clsLoginRegister
{


	
static	void _AddToLogFile(string Text)
	{
	
	fstream LogFile;

	LogFile.open("Login_Register.txt", std::ios::app);


	if(LogFile.is_open())
	{
	
		LogFile << Text << endl;

	}


	
	}

public:
	static void Regist_LoginToSystem()
	{
		clsDate_Lib Date1;
		string Text = "";
		const string Dele = "#//#";
		Text = to_string(Date1.GetDay()) + "/" + to_string(Date1.GetMonth()) + "/" + to_string(Date1.GetYear()) + " - ";
		Text += Date1.GetSystemTime() + Dele;
		Text += (CurrentUser.GetUserName() + Dele + CurrentUser.GetPassword() + Dele) + to_string(CurrentUser.GetPermissions());
		_AddToLogFile(Text);
		Text = "";


	}


};

