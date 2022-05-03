// MethodsProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace::std;

#include "Tokenizer.h"
#include "User.h"

int main()
{
	bool runProg = true;
	bool LoggedIn = false;
	string user_input, command1, userLoggedIn;
	vector<User> UserList;

	Tokenizer tkn;

	cout << "Welcome to 'The Book Store'" << endl << "Type help to pull up a list of commands" << endl;
	cout << "-> LOGIN" << endl;
	cout << "-> CREATE ACCOUNT" << endl;
	cout << "-> EXIT PROGRAM" << endl;

	while (runProg == true)
	{
		if (LoggedIn == true)
		{
			cout << "CATALOG:" << endl
				<< "Book1 Price:$" << endl
				<< "Book2 Price:$" << endl
				<< "Book3 Price:$" << endl
				<< "Book4 Price:$" << endl
				<< "Book5 Price:$" << endl
				<< "Book6 Price:$" << endl
				<< "Book7 Price:$" << endl
				<< "Book8 Price:$" << endl
				<< "Book9 Price:$" << endl
				<< "Book10 Price:$" << endl;

			cout << endl << endl << "LOGOUT" << endl;
		}

		cout << ">> ";

		//Get user input
		getline(cin, user_input);
		tkn.setString(user_input);

		//Read user command
		tkn.readWord(command1);

		//User requests to create an account
		if (command1 == "create")
		{
			string command2;

			tkn.readWord(command2);

			if (command2 == "account")
			{
				//Prepare user to set up their username
				string username;
				bool userWorked = false;
				bool checkUserExists;

				//Creates a logical error right now
				while (userWorked == false)
				{
					checkUserExists = false;

					cout << "Enter your username: ";

					cin >> username;

					for (int i = 0; i < UserList.size(); i++)
					{
						if (username == UserList[i].getUsername())
						{
							checkUserExists = true;
						}
					}

					if (checkUserExists == false)
					{
						User newUser;

						newUser.setUsername(username);

						UserList.push_back(newUser);

						userWorked = true;
					}

					else
					{
						cout << "ERROR: Username is unavailable" << endl;
					}
				}

				//Prompt user to set up their password
				cout << "Enter your password: ";

				string password;

				cin >> password;

				for (int i = 0; i < UserList.size(); i++)
				{
					if (username == UserList[i].getUsername())
					{
						UserList[i].setPassword(password);
					}
				}
			}

			else
			{
				cout << "ERROR: Invalid command" << endl;
			}
		}

		//User requests to login
		else if (command1 == "login")
		{
			string username;
			bool checkUserExists = false;

			string password;
			bool passwordMatches = false;

			if (LoggedIn == false)
			{
				//Check for account input and that account with that username exists
				if (tkn.readWord(username))
				{
					if (tkn.readWord(password))
					{
						for (int i = 0; i < UserList.size(); i++)
						{
							if (username == UserList[i].getUsername())
							{
								checkUserExists = true;

								if (password == UserList[i].getPassword())
								{
									passwordMatches = true;
								}
							}
						}
					}

					//If account does exist, check that password is present and correct
					if (checkUserExists == true)
					{
						if (passwordMatches == true)
						{
							cout << "Login successful" << endl;
							LoggedIn = true;
							userLoggedIn = username;
						}

						else
						{
							cout << "ERROR: Incorrect password" << endl;
						}
					}

					else
					{
						cout << "ERROR: An account does not exist with this username" << endl;
					}
				}

				else
				{
					cout << "ERROR: Incomplete command" << endl;
				}
			}

			else
			{
				cout << "ERROR: " << userLoggedIn << " is already logged in" << endl;
			}
		}

		else if (command1 == "logout")
		{
			if (LoggedIn == true)
			{
				cout << "Logging out " << userLoggedIn << endl;
				LoggedIn = false;
			}
			else
			{
				cout << "ERROR: No account signed in" << endl;
			}
		}

		else if (command1 == "add")
		{
		}

		else if (command1 == "remove")
		{
		}

		else if (command1 == "view")
		{
			string command2;
			tkn.readWord(command2);

			if (command2 == "cart")
			{

			}

			else
			{
				cout << "ERROR: Invalid command" << endl;
			}
		}



		//Displays a list of commands
		else if (command1 == "help")
		{
			cout << "List of available commands: " << endl
				<< "create account - initiates account creation" << endl
				<< "login <username> <password> - login to an existing account" << endl
				<< "logout - logs user out of account" << endl
				<< "add <bookName> <quantity> - adds specified book and quantity to cart"
				<< "help - displays a list of valid commands" << endl
				<< "exit - exits program" << endl;
		}

		//Exits program
		else if (command1 == "exit")
		{
			cout << "Exiting program..." << endl;
			runProg = false;
		}

		//Error message for invalid command
		else
		{
			cout << "ERROR: Invalid command" << endl;
		}
	}
}