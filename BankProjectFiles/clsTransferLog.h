#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Libary C++ By oop/String.h"
#include "/Users/Mr.x/Desktop/Libary C++ By oop/Data_Lib.h"
#include "Global.h"

class clsTransferLog
{
	

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
	struct  sInfo;



	static sInfo _ConvertLineToRecord(string Line)
	{


		sInfo LogInfo;
		clsString::clsStr_Splits_Fun StringLIb;
		StringLIb.StringValue = Line;

		vector <string> TransferLOG_Info = StringLIb.SplitStringRecord();


		LogInfo._Date_Time = TransferLOG_Info[0];
		LogInfo._AccountNumber_1 = TransferLOG_Info[1];
		LogInfo._AccountNumber_2 = TransferLOG_Info[2];
		LogInfo._TransferAmount = TransferLOG_Info[3];
		LogInfo._Balance_After_Transfer_From = TransferLOG_Info[4];
		LogInfo._Balance_After_Transfer_To = TransferLOG_Info[5];
		LogInfo._User_Performed_TheAction = TransferLOG_Info[6];

		return LogInfo;
	
	}
	
public:
	static vector <sInfo>  LoadDataFromTransferLog()
	{

		vector <sInfo> TransferLOG_Info;
		fstream LogFile;
		string Line = "";

		LogFile.open("TransferLog.txt", std::ios::in);

		if (LogFile.is_open())
		{
			while (getline(LogFile, Line))
			{

				TransferLOG_Info.push_back(_ConvertLineToRecord(Line));



			}

			LogFile.close();

		};


		return TransferLOG_Info;

	};

struct sInfo
	{
		string _Date_Time;
		string _AccountNumber_1;
		string _AccountNumber_2;
		string _TransferAmount;
		string _Balance_After_Transfer_From;
		string _Balance_After_Transfer_To;
		string _User_Performed_TheAction;

	};

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

