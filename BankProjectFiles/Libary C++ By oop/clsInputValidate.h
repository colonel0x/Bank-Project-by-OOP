#pragma once
#include <iostream>
#include "/Users/Mr.x/Desktop/Libary C++ By oop/Data_Lib.h"
using namespace std;


class clsInputValidation
{
public:

	static bool IsNumberBetween(int Number,int from,int to)
	{

		if (Number >= from && Number <= to)
		{
			return true;

		}
		else
		{
			return false;

		}


	}
	static bool IsNumberBetween(double Number, double from,double to)
	{

		if (Number >= from && Number <= to)
		{
			return true;

		}
		else
		{
			return false;

		}


	}
	static bool IsDateBetween(clsDate_Lib SystemDate, clsDate_Lib From, clsDate_Lib To)
	{

		if (SystemDate.IsSystemDateBeforeDate2(SystemDate, To) && SystemDate.IsSystemDateAfterDate2(SystemDate, From)) {

			return true;

		}
		else
		{
			return false;
		}
	}
	static int ReadIntNumber(string Text = "")
	{
		int Num = 0;
		
		while (!(cin >> Num)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Text;
		};
		return Num;

	}
	static int ReadIntNumberBetween(int From,int To,string Text)
	{
		int Number = 0;
		Number = ReadIntNumber();

		while (Number < From || Number > To) 
		{
			cout << Text;
			Number = ReadIntNumber();
			

		};

		return Number;

	}
	static double ReadDblNumber(string Text = "")
	{
		double Num = 0;

		while (!(cin >> Num)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Text;
		};
		return Num;

	}
	static double ReadDblNumberBetween(int From, int To, string Text)
	{
		double Number = 0;
		Number = ReadDblNumber();

		while (Number < From || Number > To)
		{
			cout << Text;
			Number = ReadDblNumber();


		};

		return Number;

	}
	static bool IsValidDate(clsDate_Lib GetDate)
	{
	
	
		if (GetDate.IsValidDate(GetDate))
		{
			return true;

		};

		return false;
	
	}
	static string ReadString()
	{
		string Text = "";

		getline(cin >> ws, Text);
	
		return Text;
	}
	static float ReadFloatNumber(string Text = "")
	{
		float Num = 0;
		cout << Text;
		while (!(cin >> Num)) {

			cin.clear();
			
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			
		};
		return Num;

	}

	static short ReadShortNumber(string Text = "")
	{
		short Num = 0;

		while (!(cin >> Num)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Text;
		};
		return Num;
	}
	static short ReadShortNumberBetween(short From, short To, string Text)
	{
		short Number = 0;
		Number = ReadShortNumber();

		while (Number < From || Number > To)
		{
			cout << Text;
			Number = ReadDblNumber();


		};

		return Number;

	}







};
