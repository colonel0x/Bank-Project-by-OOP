#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Libary C++ By oop/String.h"
#include "/Users/Mr.x/Desktop/Libary C++ By oop/Data_Lib.h"
#include "Global.h"

class clsTransferLog
{
	//struct Info
	//{
	//	string _Date_Time;
	//	string _AccountNumber_1;
	//	string _AccountNumber_2;
	//	string _TransferAmount;
	//	string _was_Balance_Transfer_From;
	//	string _was_Balance_Transfer_To;
	//	string _User_Performed_TheAction;

	//};

	static	void _AddToLogFile(string Text)
	{

		fstream LogFile;

		LogFile.open("TransferLog.txt", std::ios::app);


		if (LogFile.is_open())
		{

			LogFile << Text << endl;

		}
		LogFile.close();


	}

public:


	static void Regist_TransferLOG(
		string AccountFROM,
		string AccountTO,
		string TransferAmount,
		string was_Balance_Transfer_From,
		string was_Balance_Transfer_To)
	{
	
	

		clsDate_Lib Date1;
		string Text = "";
		const string Dele = "#//#";
		Text = to_string(Date1.GetDay()) + "/" + to_string(Date1.GetMonth()) + "/" + to_string(Date1.GetYear()) + " - ";
		Text += Date1.GetSystemTime() + Dele;
		Text += AccountFROM + Dele;
		Text += AccountTO + Dele;
		Text += TransferAmount + Dele;
		Text += was_Balance_Transfer_From + Dele;
		Text += was_Balance_Transfer_To + Dele;
		Text += CurrentUser.UserName;

		_AddToLogFile(Text);
		Text = "";


	
	}



};

