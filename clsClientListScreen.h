#pragma once
#include <iostream>
#include "clsBankClient.h"
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"

using namespace std;

class clsClientListScreen :protected clsScreen
{
private:

	static void _PrintClientRecordLine(clsBankClient& Client)
	{
		cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(20) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.Phone;
		cout << "| " << setw(20) << left << Client.Email;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(12) << left << Client.AccountBalance;
	}

public:

	static void ShowClientsList()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pListClients))
		{
			return; // This will exit the function and it will not continue.
		}

		vector<clsBankClient> vClients = clsBankClient::GetClientsList();

		string Title = "\t  Client List Screen";
		string SubTitle = "\t   (" + to_string(vClients.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vClients.size() == 0)
		{
			cout << "\t\t\tNo Clients Available in the System!";
		}
		else
		{
			for (clsBankClient& C : vClients)
			{
				_PrintClientRecordLine(C);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
};

