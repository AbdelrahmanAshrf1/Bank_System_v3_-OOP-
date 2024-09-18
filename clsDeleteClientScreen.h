#pragma once
#include <iostream>
#include "clsScreen.h"

using namespace std;

class clsDeleteClientScreen :protected clsScreen
{
private:

	static void _PrintClient(clsBankClient& Client)
	{
		cout << "\nClient Card :";
		cout << "\n__________________________";
		cout << "\nFirst Name   : " << Client.FirstName;
		cout << "\nLast Name    : " << Client.LastName;
		cout << "\nFull Name    : " << Client.FullName();
		cout << "\nEmail        : " << Client.Email;
		cout << "\nPhone        : " << Client.Phone;
		cout << "\nAcc Number   : " << Client.AccountNumber();
		cout << "\nPassword     : " << Client.PinCode;
		cout << "\nBalance      : " << Client.AccountBalance;
		cout << "\n__________________________\n";
	}

public:

	static void ShowDeleteClientScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return; // This will exit the function and it will not continue.
		}

		_DrawScreenHeader("\tDelete Client Screen");

		string AccountNumber = "";
		cout << "Please Enter  Client Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number is not found ,choose another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClient(Client);

		cout << "\nAre you sure you wnat to delete this Client Y/N :";

		char answer = 'n';
		cin >> answer;

		if (answer == 'Y' || answer == 'y')
		{
			if (Client.Delete())
			{
				cout << "\nClient Deleted Successfully :-)\n";
				_PrintClient(Client);
			}
			else
			{
				cout << "\nError Client was not deleted\n";
			}
		}
	}

};

