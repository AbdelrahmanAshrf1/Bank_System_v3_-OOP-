#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindCurrencyScreen :protected clsScreen
{

	static void _PrintCurrency(clsCurrency &Currency)
	{
		cout << "\nCurrency Card: \n";
		cout << "________________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$)   : " << Currency.CurrencyName();
		cout << "________________________________\n";
	}

	static void _ShowResult(clsCurrency& Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency was not Found :-(\n";
		}
	}

public:

	static void ShowFindCurrencyScreen()
	{

		_DrawScreenHeader("\t  Find Currency Screen");

		cout << "\nFind by [1] Code or [2] Country ?";
		short Answer = 1;

		Answer = clsInputValidate::ReadShortNumberBetween(1, 2);

		if (Answer == 1)
		{
			string CurrencyCode;
			cout << "\nPlease enter Currency Code : ";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResult(Currency);
		}
		else
		{
			string Country;
			cout << "\nPlease enter Country Name : ";
			Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResult(Currency);
		}
	}
};

