#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "Global.h"

using namespace std;

class clsTransferScreen :protected clsScreen
{
private:

	static void _PrintClient(clsBankClient& Client)
	{
		cout << "\nClient Card :";
		cout << "\n__________________________";
		cout << "\nFull Name    : " << Client.FullName();
		cout << "\nAcc Number   : " << Client.AccountNumber();
		cout << "\nBalance      : " << Client.AccountBalance;
		cout << "\n__________________________\n";
	}

	static string _ReadAccountNumber(string TransferState = "From")
	{
		cout << "\nPlease enter Account Number to Transfer " << TransferState << " : ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nInvalid Account Number, Please Enter another one?";
			string AccountNumber1 = clsInputValidate::ReadString();
		}

		return AccountNumber;
	}

	static float ReadAmount(clsBankClient SourceClient)
	{
		float Amount;

		cout << "\nEnter Transfer Amount : ";
		Amount = clsInputValidate::ReadDblNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the availble Balance, Enter another Amount : ";
			Amount = clsInputValidate::ReadDblNumber();
		}

		return Amount;
	}

public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t  Transfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
		_PrintClient(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("To"));
		_PrintClient(DestinationClient);

		float Amount = ReadAmount(SourceClient);

		char Answer = 'n';
		cout << "\nAre you sure you wnat to perform this operation  Y/N ?";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			if (SourceClient.Transfer(Amount, DestinationClient))
			{
				cout << "\nTransfer done Successfully.";
			}
			else
			{
				cout << "\nTransfer Faild.";
			}

		}

		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
	}
};

