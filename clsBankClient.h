#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;

class clsBankClient : public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDelete = false;

	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4]
			, vClientData[5], stod(vClientData[6]));
	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string stClientRecodrd = "";
		stClientRecodrd += Client.FirstName + Seperator;
		stClientRecodrd += Client.LastName + Seperator;
		stClientRecodrd += Client.Email + Seperator;
		stClientRecodrd += Client.Phone + Seperator;
		stClientRecodrd += Client.AccountNumber() + Seperator;
		stClientRecodrd += Client.PinCode + Seperator;
		stClientRecodrd += to_string(Client.AccountBalance);
		return stClientRecodrd;
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector <clsBankClient> _LoadClientsDataFromFile()
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in); // Read mode

		vector <clsBankClient> vClients;

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				vClients.push_back(Client);
			}

			MyFile.close();
		}

		return vClients;
	}

	static void _SaveClientsDataToFile(vector<clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out); // Override mode.

		string DataLine;

		if (MyFile.is_open())
		{
			for (clsBankClient& C : vClients)
			{
				DataLine = _ConvertClientObjectToLine(C);
				MyFile << DataLine << endl;
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsBankClient> _vClients;

		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}

		_SaveClientsDataToFile(_vClients);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}

	string _PrepareTransferLogRecord(float Amount,clsBankClient DestinationClient,string UserName,string Seperator = "#//#")
	{
		string LoginRecord = "";

		LoginRecord += clsDate::GetSystemDateAndTime() + Seperator;
		LoginRecord += AccountNumber() + Seperator;
		LoginRecord += DestinationClient.AccountNumber() + Seperator;
		LoginRecord += to_string(Amount)  + Seperator;
		LoginRecord += to_string(AccountBalance) + Seperator;
		LoginRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		LoginRecord += UserName;

		return LoginRecord;
	}

	void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
	{
		string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}

	struct stTransferLogRecord;
	static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line,string Seperator = "#//#")
	{
		stTransferLogRecord TransferLogRecord;
		vector<string> vTransferLogRecord = clsString::Split(Line, Seperator);

		TransferLogRecord.DateTime = vTransferLogRecord[0];
		TransferLogRecord.SourceAccountNumber = vTransferLogRecord[1];
		TransferLogRecord.DestinationAccountNumber = vTransferLogRecord[2];
		TransferLogRecord.Amount = stof(vTransferLogRecord[3]);
		TransferLogRecord.srcBalanceAfter = stof(vTransferLogRecord[4]);
		TransferLogRecord.destBalanceAfter = stof(vTransferLogRecord[5]);

		return TransferLogRecord;
	}

public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	/*void Print()
	{

		// No UI Realated code inside object.

		cout << "\nClient Card :";
		cout << "\n__________________________";
		cout << "\nFirst Name   : " << FirstName;
		cout << "\nLast Name    : " << LastName;
		cout << "\nFull Name    : " << FullName();
		cout << "\nEmail        : " << Email;
		cout << "\nPhone        : " << Phone;
		cout << "\nAcc Number   : " << _AccountNumber;
		cout << "\nPassword     : " << _PinCode;
		cout << "\nBalance      : " << _AccountBalance;
		cout << "\n__________________________\n";
	}*/

	static clsBankClient Find(string AccountNumber)
	{
		vector<clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in); // Read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			MyFile.close();
		}

		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		vector<clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in); // Read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			MyFile.close();
		}

		return _GetEmptyClientObject();
	}

	enum enSaveResult { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };

	enSaveResult Save()
	{
		switch (_Mode)
		{
		case clsBankClient::EmptyMode:

			return enSaveResult::svFaildEmptyObject;

		case clsBankClient::UpdateMode:

			_Update();

			return enSaveResult::svSucceeded;

			break;

		case clsBankClient::AddNewMode:

			// This will add new record to file or database.
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResult::svFaildAccountNumberExists;
			}
			else
			{
				_AddNew();

				// We need to set the mode to update after add new.
				_Mode = enMode::UpdateMode;
				return enSaveResult::svSucceeded;
			}
		}
	}

	bool Delete()
	{
		vector<clsBankClient> _vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkedForDelete = true;
				break;
			}
		}

		_SaveClientsDataToFile(_vClients);

		*this = _GetEmptyClientObject();

		return true;
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	static double GetTotalBalances()
	{
		vector <clsBankClient> vClients = _LoadClientsDataFromFile();

		double TotalBalances = 0;

		for (clsBankClient& C : vClients)
		{
			TotalBalances += C.AccountBalance;
		}
		return TotalBalances;
	}

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{

		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}
	}

	bool Transfer(double Amount, clsBankClient &DestinationClient)
	{
		if (Amount > AccountBalance)
		{
			return false;
		}

		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(Amount, DestinationClient, CurrentUser.UserName);
		return true;
	}

	struct stTransferLogRecord
	{
		string DateTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		float Amount;
		float srcBalanceAfter;
		float destBalanceAfter;
		string UserName;
	};

	static vector<stTransferLogRecord> GetTransferLogList()
	{
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in); // Read Only.

		vector<stTransferLogRecord> vTransferLogRecord;

		if (MyFile.is_open())
		{
			string Line;
			stTransferLogRecord TransferRecord;

			while (getline(MyFile, Line))
			{
				TransferRecord = _ConvertTransferLogLineToRecord(Line);
				vTransferLogRecord.push_back(TransferRecord);
			}
			MyFile.close();
		}
		return vTransferLogRecord;
	}
}; 

