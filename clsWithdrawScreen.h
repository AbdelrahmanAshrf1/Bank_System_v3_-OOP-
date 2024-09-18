#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsWithdrawScreen :protected clsScreen
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

	static string _ReadAccoutNumber()
	{
		string AccountNumber = "";

		cout << "\nPlease enter Account Number ? ";
		AccountNumber = clsInputValidate::ReadString();

		return AccountNumber;
	}

public:

	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\t  Withdraw Screen");

		string AccountNumber = _ReadAccoutNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient With Account Number (" << AccountNumber << ") does not exist.\n";
			AccountNumber = _ReadAccoutNumber();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		double Amount = 0;
		cout << "\nPlease enter Withdraw amount ?";
		Amount = clsInputValidate::ReadDblNumber();

		cout << "\nAre you sure you want to perform this transaction? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (Client.Withdraw(Amount))
			{
				cout << "\nAmount .Withdraw Successfully.";
				cout << "\nNew Balance is : " << Client.AccountBalance;
			}
			else
			{
				cout << "\nAmount can not Withdraw ,Insuffecient Balance !.";
				cout << "\nAmount to withdraw is : " << Amount;
				cout << "\nYour Balance is : " << Client.AccountBalance;
			}
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}
	}
};

