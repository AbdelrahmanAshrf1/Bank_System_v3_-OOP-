#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"

using namespace std;

class clsLogin : protected clsScreen
{
private:

	static bool _Login()
	{
		bool LoginFaild = false;

		string UserName, Password;
		short FaildLoginCount = 0;
		do
		{
			if (LoginFaild)
			{
				FaildLoginCount++;

				cout << "\nInvlaid Username/Password!\n";
				cout << "You have " << (3 - FaildLoginCount) << " Trails to login.\n\n";

				if (FaildLoginCount == 3)
				{
					cout << "\nYou are Locked after 3 faild trails.";
					return false;
				}
			}


			cout << "Enter User Name : ";
			cin >> UserName;

			cout << "Enter Password : ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);


		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenu();
	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t   Login Screen");
		return _Login();
	}
};

