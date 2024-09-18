#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>

using namespace std;

class clsTransferLogScreen : protected clsScreen
{
private:

	static void _PrintClientRecordLine(clsBankClient::stTransferLogRecord& Record)
	{
		cout << setw(8) << left << "" << "| " << setw(23) << left << Record.DateTime;
		cout << "| " << setw(8) << left << Record.SourceAccountNumber;
		cout << "| " << setw(8) << left << Record.DestinationAccountNumber;
		cout << "| " << setw(8) << left << Record.Amount;
		cout << "| " << setw(10) << left << Record.srcBalanceAfter;
		cout << "| " << setw(10) << left << Record.destBalanceAfter;
		cout << "| " << setw(8) << left << Record.UserName;
	}

public:

	static void ShowTransferLogScreen()
	{

		vector<clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogList();

		string Title = "\t  Transfer log List Screen";
		string SubTitle = "\t   (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/time";
		cout << "| " << left << setw(8) << "s.Acc";
		cout << "| " << left << setw(8) << "d.Acc";
		cout << "| " << left << setw(8) << "Amount";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(8) << "User";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vTransferLogRecord.size() == 0)
		{
			cout << "\t\t\tNo Transfer Log Available in the System!";
		}
		else
		{
			for (clsBankClient::stTransferLogRecord & R : vTransferLogRecord)
			{
				_PrintClientRecordLine(R);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
};

