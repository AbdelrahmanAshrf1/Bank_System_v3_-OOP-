#pragma once
#include <iostream>
#include <string>

using namespace std;

class InterfaceComunication
{
	virtual void SenEmail(string Title, string Body) = 0;
	virtual void SendFax(string Title, string Body) = 0;
	virtual void SendSMS(string Title, string Body) = 0;

};
