#pragma once
#include <iostream>
#include <ctime>
#include "clsDate.h"

using namespace std;

class clsUtil
{

public:
	enum enCharType {
		SamallLetter = 1, CapitalLetter = 2,
		Digit = 3, MixChars = 4, SpecialCharacter = 5
	};

	static void Srand()
	{
		srand(unsigned(time(NULL)));
	}

	static int RandomNumber(int From, int To)
	{
		//Function to generate a random number
		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}

	static char GetRandomCharacter(enCharType CharType)
	{

		//updated this method to accept mixchars
		if (CharType == MixChars)
		{
			//Capital/Samll/Digits only
			CharType = (enCharType)RandomNumber(1, 3);

		}

		switch (CharType)
		{

		case enCharType::SamallLetter:
		{
			return char(RandomNumber(97, 122));
			break;
		}
		case enCharType::CapitalLetter:
		{
			return char(RandomNumber(65, 90));
			break;
		}
		case enCharType::SpecialCharacter:
		{
			return char(RandomNumber(33, 47));
			break;
		}
		case enCharType::Digit:
		{
			return char(RandomNumber(48, 57));
			break;
		}
	defualt:
		{
			return char(RandomNumber(65, 90));
			break;
		}
		}
	}

	static string GenerateWord(enCharType Type,short NumberOfDigits)
	{
		string Word = "";
		for (short i = 0; i < NumberOfDigits; i++)
		{
			Word += GetRandomCharacter(Type);
		}
		return Word;
	}

	static string GenerateKey(enCharType Type)
	{
		string Key = "";
		Key += GenerateWord(Type, 4) + "-";
		Key += GenerateWord(Type, 4) + "-";
		Key += GenerateWord(Type, 4) + "-";
		Key += GenerateWord(Type, 4);
		return Key;
	}

	static void GenerateKeys(enCharType Type,short NumberOfKeys)
	{
		for (short i = 0; i < NumberOfKeys; i++)
		{
			cout << "Key  [" << i + 1 << "]   : " << GenerateKey(Type) << endl;
		}
	}

	static void Swap(int &Number1,int &Number2)
	{
		int temp = Number1;
		Number1 = Number2;
		Number2 = temp;
	}

	static void Swap(double& Number1, double& Number2)
	{
		double temp = Number1;
		Number1 = Number2;
		Number2 = temp;
	}

	static void Swap(string& Str1, string& Str2)
	{
		string temp = Str1;
		Str1 = Str2;
		Str2 = temp;
	}

	static  void Swap(clsDate& Date1, clsDate& Date2)
	{
		clsDate::SwapDates(Date1, Date2);
	}

	static void ShuffleArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1],
				arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static void ShuffleArray(string arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1],
				arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static void FillArrayWithRandomNumbers(int arr[100], short arrLength,int From,int To)
	{
		for (short i = 0; i < arrLength; i++)
		{
			arr[i] = RandomNumber(From, To);
		}
	}

	static void FillArrayWithRandomWords(string arr[100], short arrLength, enCharType Type, short WordLength)
	{
		for (short i = 0; i < arrLength; i++)
		{
			arr[i] = GenerateWord(Type, WordLength);
		}
	}

	static void FillArrayWithRandomKeys(string arr[100], short arrLength, enCharType Type)
	{
		for (short i = 0; i < arrLength; i++)
		{
			arr[i] = GenerateKey(Type);
		}
	}

	static string  Tabs(short NumberOfTabs)
	{
		string t = "";

		for (int i = 1; i < NumberOfTabs; i++)
		{
			t = t + "\t";
			cout << t;
		}
		return t;

	}

	static string EncryptText(string Text, short EncryptionKey = 2)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text;
	}

	static string DecryptText(string Text, short EncryptionKey = 2)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		}
		return Text;
	}

	static string NumberToText(int Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}


	}
};
