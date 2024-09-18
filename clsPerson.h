#pragma once
#include <iostream>
#include <string>
#include "InterfaceComunication.h"

using namespace std;

class clsPerson :public InterfaceComunication
{
private:

	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:

	clsPerson(string FirstName, string LastName, string Email, string Phone)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}

	// Property set.
	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}

	// Property get.
	string GetFirstName()
	{
		return _FirstName;
	}

	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

	// Property set.
	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}

	// Property get.
	string GetLastName()
	{
		return _LastName;
	}

	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;

	// Property set.
	void SetEmail(string Email)
	{
		_Email = Email;
	}

	// Property get.
	string GetEmail()
	{
		return _Email;
	}

	__declspec(property(get = GetEmail, put = SetEmail)) string Email;

	// Property set.
	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}

	// Property get.
	string GetPhone()
	{
		return _Phone;
	}

	__declspec(property(get = GetPhone, put = SetPhone)) string Phone;

	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

	void SenEmail(string Title, string Body)
	{

	}

	void SendFax(string Title, string Body)
	{

	}

	void SendSMS(string Title, string Body)
	{

	}
};

