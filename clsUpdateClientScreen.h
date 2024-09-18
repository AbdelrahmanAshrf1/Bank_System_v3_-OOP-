#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsUpdateClientScreen :protected clsScreen
{
private:

	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nUpdate Client Info :";
		cout << "\n__________________________";
		cout << "\nEnter First Name :";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter Last Name :";
		Client.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Email :";
		Client.Email = clsInputValidate::ReadString();
		cout << "\nEnter Phone :";
		Client.Phone = clsInputValidate::ReadString();
		cout << "\nEnter PinCode :";
		Client.PinCode = clsInputValidate::ReadString();
		cout << "\nEnter Balance Balance :";
		Client.AccountBalance = clsInputValidate::ReadDblNumber();
	}

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

	static void ShowUpdateClientScreen()
	{
		_DrawScreenHeader("\t Update Client Screen");

		string AccountNumber = "";
		cout << "Please Enter  Client Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number is not found ,chose another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClient(Client);
		_ReadClientInfo(Client);

		clsBankClient::enSaveResult SaveResult;

		SaveResult = Client.Save();

		switch (SaveResult)
		{
		case clsBankClient::svFaildEmptyObject:

			cout << "\nError Account was not save ,becouse it's Empty";
			break;

		case clsBankClient::svSucceeded:

			cout << "\nAccount Updated Successfuly :-)\n";
			_PrintClient(Client);
			break;
		}
	}
};

