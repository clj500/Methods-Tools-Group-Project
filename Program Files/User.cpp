#include "User.h"
#include "Tokenizer.h"

void User::setUserId(int userId)
{
	this->userId = userId;
}

void User::setUsername(string username)
{
	this->username = username;
}

void User::setPassword(string password)
{
	this->password = password;
}

void User::setShippingInfo()
{
	Tokenizer tkn1;
	string input;
	string first, last, address, city, state, zip;

	cout << "First name: ";
	cin >> first;

	cout << "Last name: ";
	cin >> last;

	cout << "Street address: ";
	
	//Get user input
	getline(cin, input);
	tkn1.setString(input);

	//Read user command
	tkn1.readWord(address);

	cout << "City: ";
	cin >> city;

	cout << "State: ";
	cin >> state;

	cout << "Zip Code: ";
	cin >> zip;

	//Push data into vector
	shippingInfo.push_back(first);
	shippingInfo.push_back(last);
	shippingInfo.push_back(address);
	shippingInfo.push_back(city);
	shippingInfo.push_back(state);
	shippingInfo.push_back(zip);

	cout << endl;
}

void User::setPaymentInfo()
{
	Tokenizer tkn1;
	string input;
	string first, last, cardNumber, cvc, expiration;

	cout << "First name: ";
	cin >> first;

	cout << "Last name: ";
	cin >> last;

	cout << "Card number: ";

	//Get user input
	getline(cin, input);
	tkn1.setString(input);

	//Read user command
	tkn1.readWord(cardNumber);

	cout << "CVC: ";
	cin >> cvc;

	cout << "Expiration Date (month/day/year): ";
	cin >> expiration;

	paymentInfo.push_back(first);
	paymentInfo.push_back(last);
	paymentInfo.push_back(cardNumber);
	paymentInfo.push_back(cvc);
	paymentInfo.push_back(expiration);

	filledOutInfo = true;
}

int User::getUserId()
{
	return userId;
}

string User::getUsername()
{
	return username;
}

string User::getPassword()
{
	return password;
}

void User::getShippingInfo()
{
	cout << "Name: " << shippingInfo[0] << " " << shippingInfo[1] << endl;
	cout << "Address: " << endl << shippingInfo[2] << endl << shippingInfo[3] << ", " << shippingInfo[4] << " " << shippingInfo[5] << endl;
}

void User::getPaymentInfo()
{
	cout << "Name: " << paymentInfo[0] << " " << paymentInfo[1] << endl;
	cout << "Card Number: xxxx-xxxx-xxxx-" << paymentInfo[2] << endl;
	cout << "CVC: " << paymentInfo[3] << "   Expiration Date:" << paymentInfo[4] << endl;
}

bool User::getFilledOutInfo()
{
	return filledOutInfo;
}
