#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace::std;

class User
{
public:
	int userId = 0;
	string username, password;
	vector<string> shippingInfo;
	vector<string> paymentInfo;

	void setUsername(string username);
	void setPassword(string password);
	void setShippingInfo();
	void setPaymentInfo();

	int getUserId();
	string getUsername();
	string getPassword();
	void getShippingInfo();
	void getPaymentInfo();
};


