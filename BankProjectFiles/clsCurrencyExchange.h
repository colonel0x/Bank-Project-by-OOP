#pragma once
#include <iostream>
#include <vector>
#include "clsScreen.h"
#include "clsCurrencies.h"
#include "Libary C++ By oop/String.h"
#include "Libary C++ By oop/clsInputValidate.h"
#include <iomanip>
#include <array>
#include <thread>   // this_thread::sleep_for
#include <chrono>   //chrono::seconds milliseconds
#include <windows.h>

using namespace std;


class clsCurrencyExchange :protected clsScreen
{
	static void ShowList(clsCurrency sInfo)
	{
	
		cout << "\n" << left << setw(36) << sInfo.Country();
		cout << left << setw(16) <<"| "+sInfo.CurrencyCode();
		cout << left << setw(32) <<"| "+sInfo.CurrencyName();
		cout << left << setw(10) << "| " + to_string(sInfo.Rate());
		
	}
	static void _PrintCurrencyCard(clsCurrency Info)
	{

		if (!Info.IsEmpty())
		{
		cout << "Currency Found (:\n\n";

		cout << "Currency Card\n";	
		cout << string(30, '_');
		cout << "\nCountry  : " << Info.Country();
		cout << "\nCode     : " << Info.CurrencyCode();
		cout << "\nName     : " << Info.CurrencyName();
		cout << "\nRate(1$) : " << Info.Rate();
		cout <<"\n" << string(30, '_') << endl;


		}
		else
		{
			cout << "\nNot Found!!\n";
		}
		
	}
	static void _UpdateCurrencyScreen(clsCurrency Info)
	{
	
		cout << "\nUpdate currency rate\n" << string(20, '-') << endl;
		cout << "Enter New Rate: ";
		Info.UpdateRate(clsInputValidation::ReadFloatNumber());
		cout << "\nUpdated Successfully (:\n";
	}
	static string ToUpper(string text)
	{
	
	
	
		return  clsString::clsStr_Change_Letter_UpperLower_Fun::ChangeStringToUpper(text);

	
	}
	static bool FindWhoUSD(string Info_1)
	{

		return	(ToUpper(Info_1) == "USD") ? true : false;

	}
	static  void _PressToUpdate()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to Update All Rate Currency...\n" << endl;

		system("pause>0");
	}
	static void _StartUpdateAllCurrencies(string CurrencyCode,clsCurrency& Info, float CurrencyRate,short Timer)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hConsole, &csbi);
		COORD pos = csbi.dwCursorPosition;

		Info.UpdateRate(CurrencyRate);

		
		
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "(" << CurrencyCode << ") [" << Timer << "] : Updated Successfully (:";
		this_thread::sleep_for(chrono::milliseconds(250/4));


		SetConsoleCursorPosition(hConsole, pos);
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "(" << CurrencyCode << ") [" << Timer << "] : Updated Successfully (:";
		this_thread::sleep_for(chrono::milliseconds(25 / 2));

		cout << "\n";
		
	}

public:


	static void ShowCurrenciesList()
	{
		vector <clsCurrency> InfoCurrency = clsCurrency::GetCurrenciesList();
		string NumberOFCurrncy = "(" + to_string(InfoCurrency.size()) + ").";

		_DrawScreenHeader("Currency List Screen",NumberOFCurrncy);
		cout << "\n\n";

		cout << string(120, '_');
		cout << "\n\n" << left << setw(36) << "| Country";
		cout << left << setw(16) << "| Code";
		cout << left << setw(32) << "| Name";
		cout << left << setw(10) << "| Rate/(1$)\n";
		cout << string(120, '_') << endl;

		for(clsCurrency CountryCurrency: InfoCurrency)
		{
		
			ShowList(CountryCurrency);

		}


	}
	static void FindCurrency()
	{
		string Text = "";
		short Input = 0;

		_DrawScreenHeader("Find Currency Screen");
		Input = clsInputValidation::ReadShortNumberBetween(1, 2, "Find By: [1] Code or [2] Country ? ");
		
		
		if (Input == 1)
		{
			Text = clsInputValidation::ReadString("Please Enter Code  : ");
			clsCurrency Info = clsCurrency::FindByCode(Text);

			
				_PrintCurrencyCard(Info);

		
		}
		else if(Input == 2)
		{
			Text = clsInputValidation::ReadString("Please Enter Country Name : ");
			clsCurrency Info = clsCurrency::FindByCountry(Text);
			
				_PrintCurrencyCard(Info);

		
		}
	
	
	}
	static void UpdateRateCurrency()
{
	string Text = "";
		
		_DrawScreenHeader("Update Currency Screen");
		Text = clsInputValidation::ReadString("Enter Currency Code: ");
		clsCurrency Info = clsCurrency::FindByCode(Text);
		if (!Info.IsEmpty()) {


			_PrintCurrencyCard(Info);
			char Answer;
			cout << "Are you sure you want update the rate of this currency y/n: ";
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y')
			{
				_UpdateCurrencyScreen(Info);
			}

		};





	
	}
	static void UpdateCurrency()
	{
		string Text = "";
		_DrawScreenHeader("Update Currency Screen");
		char UserWantPerformMore;
		do{

			Text = clsInputValidation::ReadString("Enter Currency_1 Code: ");
			clsCurrency Info_1 = clsCurrency::FindByCode(Text);
			while (Info_1.IsEmpty())
			{
				Text = clsInputValidation::ReadString("Currency Was not found enter another code: ");
				Info_1 = clsCurrency::FindByCode(Text);

			}

			Text = "";
			Text = clsInputValidation::ReadString("Enter Currency_2 Code: ");
			clsCurrency Info_2 = clsCurrency::FindByCode(Text);

			while (Info_2.IsEmpty())
			{
				Text = clsInputValidation::ReadString("Currency Was not found enter another code: ");
				Info_2 = clsCurrency::FindByCode(Text);

			}


			if (ToUpper(Info_1.CurrencyCode()) == "USD" || ToUpper(Info_2.CurrencyCode()) == "USD")
			{

				float Amount = 0;

				Amount = clsInputValidation::ReadFloatNumber("Enter Amount to Exchange: ");
				_PrintCurrencyCard(Info_1);

				float Rate_Result;
				Rate_Result = Amount / Info_1.Rate();
				cout << Amount << " " << Info_1.CurrencyCode() << " = " << Rate_Result << " " << Info_2.CurrencyCode();


				/*bool FindUSD;
				FindUSD = FindWhoUSD(Info_1.CurrencyCode());

				if (FindUSD == true)
				{

				}
				else
				{
					Rate_Result = Amount / Info_1.Rate();
					cout << Amount << " " << Info_1.CurrencyCode() << " = " << Rate_Result << " " << Info_2.CurrencyCode();

				}*/


			}
			else
			{
				float Amount = 0;
				float Rate_Result;

				Amount = clsInputValidation::ReadFloatNumber("Enter Amount to Exchange: ");
				cout << "\nConvert From\n";
				_PrintCurrencyCard(Info_1);

				Rate_Result = Amount / Info_1.Rate();
				Rate_Result *= Info_2.Rate();
				cout << "\nConvert To\n";
				_PrintCurrencyCard(Info_2);

				cout << Amount << " " << Info_1.CurrencyCode() << " = " << Rate_Result << " " << Info_2.CurrencyCode();




			}

			cout << "\nDo you want to perform more culculation? y/n\n";
			cin >> UserWantPerformMore;
			system("cls");
		} while (UserWantPerformMore == 'y' || UserWantPerformMore == 'Y');


	}
	static void UpdateAllRateCurrency() {

		_DrawScreenHeader("Update All Currency");

		string currency = "USD";

		// Choose your Path
		string command = "C:/Users/UserName/Desktop/PYthon1EXEGEtRate.py " + currency;
		
		
		vector <string> vArray;
		array<char, 128> buffer;
		string result;

		FILE* pipe = _popen(command.c_str(), "r");
		if (!pipe) {
			std::cerr << "Falid\n";
			return;
		}
		bool GetAnswer;
		while (GetAnswer = (fgets(buffer.data(), buffer.size(), pipe) != nullptr)) {

			result += buffer.data();

		}

		if (!GetAnswer)
		{

			_pclose(pipe);
			vArray = clsString::clsStr_Splits_Fun::SplitStringRecord(result, ",");

		};

		vector <clsCurrency> AllInfo = clsCurrency::GetCurrenciesList();
		vector <string> Currencies;
		string TextCurrencyCode = "";
		float CurrencyRate = 0;
		short Timer = 0;
		short i = 0;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "We will start UPDATE\n";
		this_thread::sleep_for(chrono::milliseconds(500));

		for (string GetLine : vArray)
		{
			i++;
			
			if (i >= 12)
			{

				for (clsCurrency Record : AllInfo)
				{


					TextCurrencyCode = clsString::clsStr_Splits_Fun::FindWord(GetLine, ":");
					CurrencyRate = clsString::clsStr_Splits_Fun::FindCurrency(GetLine, ":");

					if (TextCurrencyCode == Record.CurrencyCode())
					{
						Timer++;
						_StartUpdateAllCurrencies(TextCurrencyCode,Record, CurrencyRate,Timer);
						break;
					}



				}

			}

		}

		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout << endl;


	}





};

