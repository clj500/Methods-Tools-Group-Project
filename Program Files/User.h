#pragma once

#include <iostream>
#include <string>

using namespace::std;

class User
{
public:
	int userId;
	string username, password;
	bool loggedIn = false;
	string shippingInfo, paymentInfo;

	void setUsername(string username);
	void setPassword(string password);
	void setLoggedIn(bool loggedIn);
	void setShippingInfo(string address);
	void setPaymentInfo(string cardnumber);

	int getUserId();
	string getUsername();
	string getPassword();
	bool getLoggedIn();
};

