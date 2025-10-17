#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsCurrencyExchange.h"
using namespace std;



class clsCurrencyScreen : protected clsScreen
{
	enum eCurrencyOption 
	{ ListCurrencies = 1, FindCurre = 2, UpdateRate = 3, CurreCulculator = 4,UpdateAllRateCurre=5, BackToMainMenue = 6 };
static	 short _ReadMainMenueOption()
	{
		cout << _Tab(5)<< "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidation::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}
static string _Tab(short HowManyTap)
{
	cout << "\n";
	for (short i = 0; i < HowManyTap; i++)
	{
		cout << "\t";
	}
	return "";
}


static  void _BackToCurrencyScreen()
{
	cout << setw(37) << left << "" << "\n\tPress any key to go back to Currency menue...\n" << endl;

	system("pause>0");
}
static	void _ShowListCurrencies()
	{
	
	clsCurrencyExchange::ShowCurrenciesList();
		
	}





static	void _ShowFindCurrency()
	{

	clsCurrencyExchange::FindCurrency();


	}




static	void _ShowUpdateRate()
	{

	clsCurrencyExchange::UpdateRateCurrency();

	}


static void _UpdateALLRateCurrencyScreen()
{
	clsCurrencyExchange::UpdateAllRateCurrency();
}





static	void _ShowCurrencyCulculatorScreen()
	{
	clsCurrencyExchange::UpdateCurrency();
	}
static	void _BackToMainMenue()
	{

		cout << "Process!";
	}
static	bool _PerformCurrencyScreen_Options(short Option)
	{
	
	switch(Option)
	{
	
	
	case eCurrencyOption::ListCurrencies:
		
		system("cls");
		_ShowListCurrencies();
		_BackToCurrencyScreen();
		return true;
		break;
	case eCurrencyOption::FindCurre:

		system("cls");
		_ShowFindCurrency();
		_BackToCurrencyScreen();
		return true;
		break;
	case eCurrencyOption::UpdateRate:

		system("cls");
		_ShowUpdateRate();
		_BackToCurrencyScreen();
		return true;
		break;
	case eCurrencyOption::CurreCulculator:

		system("cls");
		_ShowCurrencyCulculatorScreen();
		_BackToCurrencyScreen();
		return true;
		break;
	case eCurrencyOption::UpdateAllRateCurre:

		system("cls");
		_UpdateALLRateCurrencyScreen();
		_BackToCurrencyScreen();
		return true;
		break;

	case eCurrencyOption::BackToMainMenue:

		system("cls");
		_BackToMainMenue();
		return false;
		break;

	
	}

	
	}

public:

	static void ShowCurrencyScreen()
	{
		 
		
		do
		{
		system("cls");

		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}

		_DrawScreenHeader("Currency Exchange Main Screen");

		cout << _Tab(5) << string(38,'=');
		cout << _Tab(5) << "Currency Exchange  Menue\n";
		cout << _Tab(5) << string(38, '=');
		cout << _Tab(5) << "[1] List Currencies.";
		cout << _Tab(5) << "[2] Find Currency.";
		cout << _Tab(5) << "[3] Update Rate.";
		cout << _Tab(5) << "[4] Currency Culculator.";
		cout << _Tab(5) << "[5] Update All Rate Currencies.";
		cout << _Tab(5) << "[6] Main Menue.";
		cout << _Tab(5) << string(38, '=');
	
		

		} while (_PerformCurrencyScreen_Options((eCurrencyOption)_ReadMainMenueOption()));


	
	}




};