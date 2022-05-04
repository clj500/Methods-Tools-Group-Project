//READ USER (put before start of program to load book info)

ifstream usersIs("users.txt");

if (usersIs.is_open())
{
	string line;

	while (!usersIs.eof())
	{
		int count = 0;
		string load = "";

		User userTemp
		getline(bookIs, line);
		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] != ';')
			{
				load += line[i];
			}
			else
			{
				if (count == 0) { userTemp.setUserId(stoi(load)); }
				if (count == 1) { userTemp.setUsername(load); }
				if (count == 2) { userTemp.setPassword(load); }
				if (count >= 3 && count <= 7) { userTemp.shippingInfo.push_back(load); }
				if (count >= 8 && count <= 11) { userTemp.paymentInfo.push_back(load); }
				count++;
				load = "";
			}
		}
		
		UserList.push_back(userTemp);
	}
}

//READ BOOK (put before start of program to load book info)

ifstream booksIs("books.txt");

if (bookIs.is_open())
{
	string line;

	while (!bookIs.eof())
	{
		int count = 0;
		string load = "";

		int isbn = 0, quantity = 0;
		float price = 0;
		string title, author, genre;

		getline(bookIs, line);
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

//READ CART (put before start of program to load book info)

//READ HISTORY (put before start of program to load book info)

//WRITE USER (put at the end of exit command)

ofstream usersOs("users.txt", ios::trunc);

for (int i = 0; i < UserList.size(); i++)
{
	usersOs << UserList[i].getUserId() << ";" << UserList[i].getUsername() << ";" << UserList[i].getPassword() << ";" 
		<< UserList[i].shippingInfo[0] << ";" << UserList[i].shippingInfo[1] << ";"	<< UserList[i].shippingInfo[2] << ";" 
		<< UserList[i].shippingInfo[3] ";" << UserList[i].shippingInfo[4] << ";" << UserList[i].shippingInfo[5] << ";" 
		<< UserList[i].paymentInfo[0] << ";" << UserList[i].paymentInfo[1] << ";" << UserList[i].paymentInfo[2] << ";" 
		<< UserList[i].paymentInfo[3] << ";" << UserList[i].paymentInfo[4] << "\n";
}

//WRITE BOOK (put at the end of exit command)

ofstream booksOs("books.txt", ios::trunc);

for (int i = 0; i < BookVector.size(); i++)
{
	booksOs << BookVector[i].getIsbn() << ";" << BookVector[i].getQuantity() << ";" << BookVector[i].getPrice() << ";"
		<< BookVector[i].getTitle() << ";" << BookVector[i].getAuthor() << ";" << BookVector[i].getGenre() << "\n";
}

//WRITE CART (put at the end of exit command)

ofstream cartsOs("carts.txt", ios::trunc);

for (int i = 0; i < CartVector.size(); i++)
{
	cartsOs << CartVector[i].getUserId() << ";" << CartVector[i].getCartTotal() << ";";
	for(int j = 0; j <CartVector[i].cartContents.size(); j++)
	{
		cartsOs << CartVector[i].cartContents[j].getIsbn() << ";" << CartVector[i].cartContents[j].getQuantity() << ";" << CartVector[i].cartContents[j].getPrice() << ";"
			<< CartVector[i].cartContents[j].getTitle() << ";" << CartVector[i].cartContents[j].getAuthor() << ";" << CartVector[i].cartContents[j].getGenre();
	}
	cartsOs << "\n";
}

//WRITE HISTORY (put at the end of exit command)

ofstream historyOs("history.txt", ios::trunc);

for (int i = 0; i < HistoryVector.size(); i++)
{
	historyOs << HistoryVector[i].getUserId() << ";" << HistoryVector[i].getOrderTotal() << ";";
	for (int j = 0; j < HistoryVector[i].orderContent.size(); j++)
	{
		historyOs << HistoryVector[i].orderContent[j].getIsbn() << ";" << HistoryVector[i].orderContent[j].getQuantity() << ";" << HistoryVector[i].orderContent[j].getPrice() << ";"
			<< HistoryVector[i].orderContent[j].getTitle() << ";" << HistoryVector[i].orderContent[j].getAuthor() << ";" << HistoryVector[i].orderContent[j].getGenre();
	}
	historyOs << "\n";
}