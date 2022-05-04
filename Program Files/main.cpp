/*
Class: Methods & Tools in SW Dev.
Section: 01
Contributors: Devin Shead, Cassie Javorsky, David Heaton, Cameron Verser
Program Description:

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace::std;

#include "Tokenizer.h"
#include "User.h"
#include "Cart.h"
#include "History.h"

int main()
{
	bool runProg = true;
	bool LoggedIn = false;
	int userLoggedInId;
	string user_input, command1, userLoggedIn;
	vector<User> UserList;
	vector<Book> BookVector;
	vector<Cart> CartVector;
	vector<History> HistoryVector;

	Tokenizer tkn;

	//READ BOOK DATA
	ifstream myFile("books.txt");

	if (myFile.is_open())
	{
		string line;

		while (!myFile.eof())
		{
			int count = 0;
			string load = "";
			int isbn = 0, quantity = 0;
			float price = 0;
			string title, author, genre;

			getline(myFile, line);
			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] != ';')
				{
					load += line[i];
				}
				else
				{
					if (count == 0) { isbn = stoi(load); }
					if (count == 1) { quantity = stoi(load); }
					if (count == 2) { price = stof(load); }
					if (count == 3) { title = load; }
					if (count == 4) { author = load; }
					if (count == 5) { genre = load; }
					count++;
					load = "";
				}
			}
			Book bookTemp(isbn, quantity, price, title, author, genre);
			BookVector.push_back(bookTemp);
		}
	}

	//Output welcome screen
	cout << "Welcome to 'The Book Store'                           |  CREATE ACCOUNT  | LOGIN | EXIT |" << endl
		<< "----------------------------------------------------------------------------------------" << endl
		<< "Type help to pull up a list of commands" << endl;

	//Start program to allow for user command-line use
	while (runProg == true)
	{
		cout << endl << ">> ";

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

					cout << "Enter a username: ";

					getline(cin, username);

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
				cout << "Enter a password: ";

				string password;

				getline(cin, password);

				for (int i = 0; i < UserList.size(); i++)
				{
					if (username == UserList[i].getUsername())
					{
						UserList[i].setPassword(password);
						UserList[i].setUserId(i);

						Cart userCart(UserList[i].getUserId());
						CartVector.push_back(userCart);

						tkn.clear();
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
			int tempUserId;
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

								tempUserId = UserList[i].getUserId();

								if (password == UserList[i].getPassword())
								{
									passwordMatches = true;
								}
							}
						}

						//If account does exist, check that password is present and correct
						if (checkUserExists == true)
						{
							if (passwordMatches == true)
							{
								LoggedIn = true;
								userLoggedIn = username;
								userLoggedInId = tempUserId;

								cout << endl << "'The Book Store'                            |   VIEW CATALOG   |   VIEW CART   | LOGOUT |" << endl
									<< "----------------------------------------------------------------------------------------" << endl;
							}

							else
							{
								cout << "ERROR: Incorrect password" << endl;
							}
						}

						else if (checkUserExists == false)
						{
							cout << "ERROR: An account does not exist with this username" << endl;
						}
					}

					else if (!tkn.readWord(password))
					{
						cout << "ERROR: Invalid command" << endl;
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

		//User requests to enter/edit their info
		else if (command1 == "edit")
		{
			if (LoggedIn == true)
			{
				string command2;
				tkn.readWord(command2);

				if (command2 == "shipping")
				{
					for (int i = 0; i < UserList.size(); i++)
					{
						if (userLoggedIn == UserList[i].getUsername())
						{
							UserList[i].setShippingInfo();
						}
					}
				}

				else if (command2 == "payment")
				{
					for (int i = 0; i < UserList.size(); i++)
					{
						if (userLoggedIn == UserList[i].getUsername())
						{
							UserList[i].setPaymentInfo();
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
				cout << "ERROR: Must be logged in to edit information" << endl;
			}
		}

		//User requests to logout
		else if (command1 == "logout")
		{
			if (LoggedIn == true)
			{
				LoggedIn = false;

				cout << endl << "Welcome to 'The Book Store'                           |  CREATE ACCOUNT  | LOGIN | EXIT |" << endl
					<< "----------------------------------------------------------------------------------------" << endl
					<< "Type help to pull up a list of commands" << endl;
			}

			else
			{
				cout << "ERROR: Must be logged in to log out" << endl;
			}
		}

		//User requests to add item in cart
		else if (command1 == "add")
		{
			if (LoggedIn == true)
			{
				int bookISBN;

				if (tkn.readInteger(bookISBN))
				{
					int quantity;

					if (tkn.readInteger(quantity))
					{
						for (int i = 0; i < CartVector.size(); i++)
						{
							if (userLoggedInId == CartVector[i].getUserId())
							{
								CartVector[i].addToCart(bookISBN, quantity, BookVector);
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
				int bookISBN;

				if (tkn.readInteger(bookISBN))
				{
					for (int i = 0; i < BookVector.size(); i++)
					{
						if (bookISBN == BookVector[i].getIsbn())
						{
							for (int i = 0; i < CartVector.size(); i++)
							{
								if (userLoggedInId == CartVector[i].getUserId())
								{
									CartVector[i].removeBook(bookISBN);
								}
							}
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
				cout << "ERROR: Must be logged in to remove an item" << endl;
			}
		}

		//User requests to view
		else if (command1 == "view")
		{
			string command2;
			tkn.readWord(command2);

			//User requests to view books
			if (command2 == "catalog")
			{	
				if (LoggedIn == true)
				{
					cout << endl << "'The Book Store'                                               |   VIEW CART   | LOGOUT |" << endl
						<< "----------------------------------------------------------------------------------------" << endl;

					cout << showpoint << setprecision(4);
					cout << "CATALOG:" << endl << endl;
						for (int i = 0; i < BookVector.size(); i++)
						{
							cout << "ISBN #: " << BookVector[i].getIsbn() << " Title: '" << BookVector[i].getTitle() << "'" << " Author: " << BookVector[i].getAuthor() << "   Price:$" << BookVector[i].getPrice() << "Quantity in Stock: " << BookVector[i].getQuantity() << endl << endl;
						}
				}

				else
				{
					cout << "ERROR: Must be logged in to view books" << endl << endl;
				}
			}

			//User requests to view cart
			else if (command2 == "cart")
			{
				if (LoggedIn == true)
				{	
					cout << endl << "'The Book Store'                                           |   VIEW CATALOG  | LOGOUT |" << endl
						<< "----------------------------------------------------------------------------------------" << endl;

					float cartTotal;
					cout << fixed << showpoint << setprecision(2);
					
					for (int i = 0; i < CartVector.size(); i++)
					{
						if (userLoggedInId == CartVector[i].getUserId())
						{
							CartVector[i].outputCartContents();
							cartTotal = CartVector[i].getCartTotal();
						}
					}

					cout << "-------------------------" << endl;
					cout << "         Total: $" << cartTotal << endl;
				}

				else
				{
					cout << "ERROR: Must be logged in to view cart" << endl << endl;
				}
			}

			//User requests to view history
			else if (command2 == "history")
			{
				if (LoggedIn == true)
				{
					cout << endl << "'The Book Store'                            |   VIEW CATALOG   |   VIEW CART   | LOGOUT |" << endl
						<< "----------------------------------------------------------------------------------------" << endl;
					for (int i = 0; i < HistoryVector.size(); i++)
					{
						if (HistoryVector[i].getUserId() == userLoggedInId)
						{
							cout << "Order " << i + 1 << endl;
							HistoryVector[i].displayOrderContent();
						}
					}
				}

				else
				{
					cout << "ERROR: Must be logged in to view history" << endl << endl;
				}
			}

			//User request to view shipping information
			else if (command2 == "shipping")
			{
				cout << "Viewing shipping info..." << endl;

				if (LoggedIn == true)
				{
					for (int i = 0; i < UserList.size(); i++)
					{
						if (userLoggedIn == UserList[i].getUsername())
						{
							if (UserList[i].getFilledOutInfo() == true)
							{
								UserList[i].getShippingInfo();
							}

							else
							{
								cout << "ERROR: No shipping information found" << endl;
							}
						}
					}
				}

				else
				{
					cout << "ERROR: Must be logged in to view shipping info" << endl << endl;
				}
			}

			//User requests to view payment information
			else if (command2 == "payment")
			{
				if (LoggedIn == true)
				{
					string passwordCheck;

					//Re-enter password for security
					cout << "Re-enter your password: ";
					getline(cin, passwordCheck);

					for (int i = 0; i < UserList.size(); i++)
					{
						if (userLoggedIn == UserList[i].getUsername())
						{
							if (passwordCheck == UserList[i].getPassword())
							{
								if (UserList[i].getFilledOutInfo() == true)
								{
									UserList[i].getPaymentInfo();
								}

								else
								{
									cout << "ERROR: No payment information found" << endl;
								}
							}

							else
							{
								cout << "ERROR: Incorrect password" << endl;
							}
						}
					}
				}

				else
				{
					cout << "ERROR: Must be logged in to view payment info" << endl << endl;
				}

				tkn.clear();
			}

			//Output error
			else
			{
				cout << "ERROR: Invalid command" << endl << endl;
			}
		}

		//User requests to checkout their cart
		else if (command1 == "checkout")
		{
		if (LoggedIn == true)
		{
			for (int i = 0; i < UserList.size(); i++)
			{
				if (userLoggedIn == UserList[i].getUsername())
				{
					if (UserList[i].getFilledOutInfo() == true)
					{
						for (int i = 0; i < CartVector.size(); i++)
						{
							if (userLoggedInId == CartVector[i].getUserId())
							{
								History newOrder(userLoggedInId, CartVector[i].getCartTotal());

									for (int j = 0; j < CartVector[i].cartContents.size(); j++)
									{
										newOrder.orderContent.push_back(CartVector[i].cartContents[j]);
									}

								HistoryVector.push_back(newOrder);
							}
							CartVector[i].checkoutCart(BookVector);
						}
					}

					else
					{
						cout << "ERROR: No shipping information found" << endl;
					}
				}
			}
		}

			else
			{
				cout << "ERROR: Must be logged in to checkout" << endl << endl;
			}
		}

		//Displays a list of commands
		else if (command1 == "help")
		{
			cout << endl << "List of available commands: " << endl
				<< "create account - initiates account creation" << endl
				<< "login <username> <password> - login to an existing account" << endl
				<< "edit shipping - allows user to add/edit their shipping information" << endl
				<< "edit payment - allows user to add/edit their payment information" << endl
				<< "logout - logs user out of account" << endl
				<< "add <bookISBN> <quantity> - adds specified book and quantity to cart" << endl
				<< "remove <bookISBN> - removes specified book from cart" << endl
				<< "view catalog - displays a catalog of all books" << endl
				<< "view cart - display cart contents" << endl
				<< "view history - displays user history" << endl
				<< "view shipping - display shipping info" << endl
				<< "view payment - display payment info" << endl
				<< "checkout - checks out all items in user's cart" << endl
				<< "help - displays a list of valid commands" << endl
				<< "exit - exits program" << endl << endl;
		}

		//Exits program
		else if (command1 == "exit")
		{
			//WRITE BOOK
			ofstream booksOs("books.txt", ios::trunc);

			for (int i = 0; i < BookVector.size(); i++)
			{
				booksOs << BookVector[i].getIsbn() << ";" << BookVector[i].getQuantity() << ";" << BookVector[i].getPrice() << ";"
					<< BookVector[i].getTitle() << ";" << BookVector[i].getAuthor() << ";" << BookVector[i].getGenre() << "\n";
			}

			cout << "Exiting program..." << endl;
			runProg = false;
		}

		//Error message for invalid command
		else
		{
			cout << "ERROR: Invalid command" << endl << endl;
		}
	}
}