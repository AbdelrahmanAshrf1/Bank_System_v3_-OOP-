#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;

class clsManageUsersMenue :protected clsScreen
{
private:

	enum enManageUsersMenueOptions
	{
		eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
	};

	static short _ReadManageUsersMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6 ?");
		return Choice;
	}

	static void _GoBackToManageUsersMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		system("pause>0");
		ShowManageUsersMenue();
	}
		
	static void _ShowListUsersScreen()
	{
		clsListUsersScreen::ShowListUsersScreen();
	}

	static void _ShowAddNewUserScreen()
	{
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOptions)
	{
		switch (ManageUsersMenueOptions)
		{
		case clsManageUsersMenue::eListUsers:

			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenue();
			break;

		case clsManageUsersMenue::eAddNewUser:

			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenue();
			break;

		case clsManageUsersMenue::eDeleteUser:

			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenue();
			break;

		case clsManageUsersMenue::eUpdateUser:

			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenue();
			break;

		case clsManageUsersMenue::eFindUser:

			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenue();
			break;

		case clsManageUsersMenue::eMainMenue:
		{
			//do nothing here the main screen will handle it :-) ;
		}
		}
		
	}

public:

	static void ShowManageUsersMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return; // This will exit the function and it will not continue.
		}

		system("cls");
		_DrawScreenHeader("\t Manage Users Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformManageUsersMenueOption((enManageUsersMenueOptions)_ReadManageUsersMenueOption());
	}
};

