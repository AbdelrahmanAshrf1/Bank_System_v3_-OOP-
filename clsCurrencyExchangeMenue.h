#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyExchangeMenue :protected clsScreen
{
private:

	enum enCurrencyExchangeMenueOptions
	{
		eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
		eCurrencyCalculator = 4, eMainMenue = 5
	};

	static short _ReadCurrencyExchangeMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5 ?");
		return Choice;
	}

	static void _GoBackToCurrencyExchangeMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		system("pause>0");
		ShowCurrencyExchangeMenue();
	}

	static void _ShowListCurrenciesScreen()
	{
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void PerformCurrencyExchangeMenueOptions(enCurrencyExchangeMenueOptions CurrencyExchangeMenueOptions)
	{
		switch (CurrencyExchangeMenueOptions)
		{
		case clsCurrencyExchangeMenue::eListCurrencies:

			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyExchangeMenue();
			break;

		case clsCurrencyExchangeMenue::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		case clsCurrencyExchangeMenue::eUpdateRate:

			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyExchangeMenue();
			break;

		case clsCurrencyExchangeMenue::eCurrencyCalculator:

			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMenue();
			break;

		case clsCurrencyExchangeMenue::eMainMenue:

		{
			//do nothing here the main screen will handle it :-) ;
		}
		}
	}

public:

	static void ShowCurrencyExchangeMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::eCurrencyExchange))
		{
			return; // This will exit the function and it will not continue.
		}

		system("cls");
		_DrawScreenHeader("  Currency Exchange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Currency Exchange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		PerformCurrencyExchangeMenueOptions((enCurrencyExchangeMenueOptions)_ReadCurrencyExchangeMenueOption());
	}
};

