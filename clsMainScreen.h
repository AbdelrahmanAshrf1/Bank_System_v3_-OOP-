#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersMenue.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeMenue.h"
#include "Global.h"

using namespace std;

class clsMainScreen :protected clsScreen
{
private:

	enum enMainMenuOptions
	{
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4, eFindClient = 5,
		eTransactions = 6, eMangeUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9, eExit = 10
	};

	static short _ReadMainMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 10,"Enter Number between 1 to 10 ?");
		return Choice;
	}

	static void _GoBackToMainMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenu();
	}

	static void _ShowAllClientsScreen()
	{
		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClienstScreen()
	{
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenue()
	{
		clsTransactionsScreen::ShowTransactionsMenue();
	}

	static void _ShowManageUsersMenue()
	{
		clsManageUsersMenue::ShowManageUsersMenue();
	}

	static void _ShowLoginRegisterScreen()
	{
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchangeMenue()
	{
		clsCurrencyExchangeMenue::ShowCurrencyExchangeMenue();
	}

	/*static void _ShowEndScreen()
	{
		cout << "End Screen will be here ...\n";
	}*/

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
		// then it will back to main function.
	}

	static void _PerfromMainMenueOption(enMainMenuOptions MainMenuOptions)
	{
		switch (MainMenuOptions)
		{
		case clsMainScreen::eListClients:

			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenu();
			break;

		case clsMainScreen::eAddNewClient:
			system("cls");
			_ShowAddNewClienstScreen();
			_GoBackToMainMenu();
			break;

		case clsMainScreen::eDeleteClient:

			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;

		case clsMainScreen::eUpdateClient:

			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;

		case clsMainScreen::eFindClient:

			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;

		case clsMainScreen::eTransactions:

			system("cls");
			_ShowTransactionsMenue();
			_GoBackToMainMenu();
			break;

		case clsMainScreen::eMangeUsers:

			system("cls");
			_ShowManageUsersMenue();
			_GoBackToMainMenu();
			break;

		case clsMainScreen::eLoginRegister:

			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenu();
			break;

		case clsMainScreen::eCurrencyExchange:

			system("cls");
			_ShowCurrencyExchangeMenue();
			_GoBackToMainMenu();
			break;

		case clsMainScreen::eExit:

			system("cls");
			_Logout();
			break;
		}
	}

public:

	static void ShowMainMenu()
	{
		system("cls");

		clsScreen::_DrawScreenHeader("\t\tMain Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[01] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[02] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[03] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[04] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[05] Find Client.\n";
		cout << setw(37) << left << "" << "\t[06] Transactions.\n";
		cout << setw(37) << left << "" << "\t[07] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[08] Login Register.\n";
		cout << setw(37) << left << "" << "\t[09] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerfromMainMenueOption((enMainMenuOptions)_ReadMainMenuOption());
	}
};

