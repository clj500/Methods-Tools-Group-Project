// MethodsProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace::std;

#include "Tokenizer.h"
#include "User.h"
#include "Shart.h"

int main()
{
	bool runProg = true;
	bool LoggedIn = false;
	string user_input, command1, userLoggedIn;
	vector<User> UserList;
	vector<Book> BookVector;

	Book book1(420, 10, 15.00, "book1", "cam", "horror");
	Book book2(420, 10, 10.00, "book2", "cam", "horror");
	Book book3(420, 10, 30.00, "book3", "cam", "horror");
	Book book4(420, 10, 200.00, "book4", "cam", "horror");

	BookVector.push_back(book1);
	BookVector.push_back(book2);
	BookVector.push_back(book3);
	BookVector.push_back(book4);

	Tokenizer tkn;
	Cart userCart(420);

	cout << "Welcome to 'The Book Store'" << endl << "Type help to pull up a list of commands" << endl;
	cout << "-> LOGIN" << endl;
	cout << "-> CREATE ACCOUNT" << endl;
	cout << "-> EXIT PROGRAM" << endl;

	while (runProg == true)
	{
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
						UserList[i].setShippingInfo();
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

		//User requests to logout
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

		//User requests to add item in cart
		else if (command1 == "add")
		{
			if (LoggedIn == true)
			{
				string bookName;

				if (tkn.readWord(bookName))
				{
					int quantity;

					if (tkn.readInteger(quantity))
					{
						for (int i = 0; i < BookVector.size(); i++)
						{
							if (bookName == BookVector[i].getTitle())
							{
								userCart.addToCart(BookVector[i], quantity);
							}
						}
					}

					else
					{
						cout << "ERROR: Invalid command" << endl;
					}
				}

				else
				{
					cout << "ERROR: Invalid command" << endl;
				}
			}

			else
			{
				cout << "ERROR: Must be logged in to add an item" << endl;
			}
		}

		//User requests to remove item from cart
		else if (command1 == "remove")
		{
			if (LoggedIn == true)
			{
				string bookName;

				if (tkn.readWord(bookName))
				{
					userCart.removeBook(bookName);
				}

				else
				{
					cout << "ERROR: Invalid command" << endl;
				}
			}

			else
			{
				cout << "ERROR: Must be logged in to remove an item" << endl;
			}
		}

		//User requests to view
		else if (command1 == "view")
		{
			string command2;
			tkn.readWord(command2);

			//User requests to view books
			if (command2 == "books")
			{
				cout << "Viewing books..." << endl;
				
				if (LoggedIn == true)
				{
					cout << showpoint << setprecision(4);
					cout << "CATALOG:" << endl
						<< book1.getTitle() << " " << "Price:$" << book1.getPrice() << endl
						<< book2.getTitle() << " " << "Price:$" << book2.getPrice() << endl
						<< book3.getTitle() << " " << "Price:$" << book3.getPrice() << endl
						<< book4.getTitle() << " " << "Price:$" << book4.getPrice() << endl;

					cout << endl << endl << "LOGOUT" << endl;
				}

				else
				{
					cout << "ERROR: Must be logged in to view books" << endl;
				}
			}

			//User requests to view cart
			else if (command2 == "cart")
			{
				cout << "Viewing cart..." << endl;

				if (LoggedIn == true)
				{	
					cout << showpoint << setprecision(4);
					userCart.outputCartContents();

					cout << "Total: $" << userCart.getCartTotal() << endl;
				}

				else
				{
					cout << "ERROR: Must be logged in to view cart" << endl;
				}
			}

			//User requests to view history
			else if (command2 == "history")
			{
				cout << "Viewing history..." << endl;

				if (LoggedIn == true)
				{
					cout << endl << endl << "LOGOUT" << endl;
				}

				else
				{
					cout << "ERROR: Must be logged in to view history" << endl;
				}
			}

			else if (command2 == "shipping")
			{
				cout << "Viewing shipping info..." << endl;

				if (LoggedIn == true)
				{
					for (int i = 0; i < UserList.size(); i++)
					{
						if (userLoggedIn == UserList[i].getUsername())
						{
							UserList[i].getShippingInfo();
						}
					}
				}

				else
				{
					cout << "ERROR: Must be logged in to view shipping info" << endl;
				}
			}

			else if (command2 == "payment")
			{
				cout << "Viewing payment info..." << endl;

				if (LoggedIn == true)
				{
					for (int i = 0; i < UserList.size(); i++)
					{
						if (userLoggedIn == UserList[i].getUsername())
						{
							UserList[i].getPaymentInfo();
						}
					}
				}

				else
				{
					cout << "ERROR: Must be logged in to view shipping info" << endl;
				}
			}

			//Output error
			else
			{
				cout << "ERROR: Invalid command" << endl;
			}
		}

		//User requests to checkout their cart
		else if (command1 == "checkout")
		{
			if (LoggedIn == true)
			{
				cout << endl << endl << "LOGOUT" << endl;
			}

			else
			{
				cout << "ERROR: Must be logged in to checkout" << endl;
			}
		}

		//Displays a list of commands
		else if (command1 == "help")
		{
			cout << "List of available commands: " << endl
				<< "create account - initiates account creation" << endl
				<< "login <username> <password> - login to an existing account" << endl
				<< "logout - logs user out of account" << endl
				<< "add <bookName> <quantity> - adds specified book and quantity to cart" << endl
				<< "remove <bookName> - removes specified book from cart" << endl
				<< "view books - displays a catalog of all books" << endl
				<< "view cart - display cart contents" << endl
				<< "view history - displays user history" << endl
				<< "view shipping - display shipping info" << endl
				<< "view payment - display payment info" << endl
				<< "checkout - checks out all items in user's cart" << endl
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