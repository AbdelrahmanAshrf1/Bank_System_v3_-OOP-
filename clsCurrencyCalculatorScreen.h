#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:

    static float _ReadAmount()
    {
        cout << "\nEnter Amount to Exchange : ";
        float Amount = clsInputValidate::ReadFloatNumber();
        return Amount;
    }

    static clsCurrency _GetCurrency(string Massage)
    {
        string CurrencyCode;
        cout << Massage << endl;

        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not Found, Choose anoter one ?";
            string CurrencyCode = clsInputValidate::ReadString();
        }
        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        return Currency;
    }

    static void _PrintCurrencyCard(clsCurrency& Currency,string Title = "Currency Card")
    {
        cout << "\n" << Title << ":\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();
        cout << "\n_____________________________\n";
    }

    static void _PrintCalculationResult(float Amout, clsCurrency CurrencyFrom, clsCurrency CurrencyTo)
    {
        _PrintCurrencyCard(CurrencyFrom, "Convert From");

        float AmountInUSD = CurrencyFrom.ConvertToUSD(Amout);

        cout << Amout << " " << CurrencyFrom.CurrencyCode() << " = " << AmountInUSD << " USD\n";

        if (CurrencyTo.CurrencyCode() == "USD")
        {
            return;
        }

        cout << "\nConverting From USD to :\n";
        _PrintCurrencyCard(CurrencyTo,"To:");

        float AmountInCurrency2 = CurrencyFrom.ConvertToOtherCurrency(Amout, CurrencyTo);

        cout << AmountInCurrency2 << " " << CurrencyFrom.CurrencyCode() 
            << " = " << AmountInCurrency2 << " " << CurrencyTo.CurrencyCode();
    }

public:

	static void ShowCurrencyCalculatorScreen()
	{
        char Continue = 'y';
        while (Continue == 'y' || Continue == 'Y')
        {
            system("cls");
            _DrawScreenHeader("\tCurrency Calculator Screen");

            clsCurrency CurrencyFrom = _GetCurrency("\nPlease enter Currency 1 Code : ");
            clsCurrency CurrencyTo = _GetCurrency("\nPlease enter Currency 2 Code : ");

            float Amout = _ReadAmount();

            _PrintCalculationResult(Amout, CurrencyFrom, CurrencyTo);

            cout << "\nDo you wnat to do Another Calculation y/n ?";
            cin >> Continue;
        }
	}
};

