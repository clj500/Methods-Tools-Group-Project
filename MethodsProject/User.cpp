#include "User.h"

void User::setUsername(string username)
{
	this->username = username;
}

void User::setPassword(string password)
{
	this->password = password;
}

string User::getUsername()
{
	return username;
}

string User::getPassword()
{
	return password;
}