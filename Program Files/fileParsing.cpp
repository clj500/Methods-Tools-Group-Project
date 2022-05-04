//READ BOOK (put before start of program to load book info

ifstream myFile("books.txt");

if (myFile.is_open())
{
	string line;
	int count = 0;

	while (!myFile.eof())
	{
		string load = "";
		int isbn, quantity;
		float price;
		string title, author, genre;

		getline(myFile, line);
		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] != ',')
			{
				load += text[i];
			}
			else:
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

//WRITE USER (put at the end of exit command)

ofstream os("users.txt", ios::trunc);

for (int i = 0; i < UserList.size(); i++)
{
	os << BookVector[i].getIsbn() << "," << BookVector[i].getQuantity() << "," << BookVector[i].getPrice() << ","
		<< BookVector[i].getTitle() << "," << BookVector[i].getAuthor() << "," << BookVector[i].getGenre() << "\n";
}

//WRITE BOOK (put at the end of exit command)

ofstream os("books.txt", ios::trunc);

for (int i = 0; i < BookVector.size(); i++)
{
	os << BookVector[i].getIsbn() << "," << BookVector[i].getQuantity() << "," << BookVector[i].getPrice() << ","
		<< BookVector[i].getTitle() << "," << BookVector[i].getAuthor() << "," << BookVector[i].getGenre() << "\n";
}

//WRITE CART (put at the end of exit command)

ofstream os("carts.txt", ios::trunc);

for (int i = 0; i < CartVector.size(); i++)
{
	os << CartVector[i].getUserId() << "," << CartVector[i].getCartTotal() << "," 
	for(int j = 0; j <CartVector[i].cartContents.size(); j++)
	{
		os << CartVector[i].cartContents[j].getIsbn() << "," << CartVector[i].cartContents[j].getQuantity() << "," << CartVector[i].cartContents[j].getPrice() << ","
			<< CartVector[i].cartContents[j].getTitle() << "," << CartVector[i].cartContents[j].getAuthor() << "," << CartVector[i].cartContents.getGenre();
	}
	os << "\n";
}

//WRITE HISTORY (put at the end of exit command)

ofstream os("history.txt", ios::trunc);

for (int i = 0; i < BookVector.size(); i++)
{
	os << HistoryVector[i].getUserId() << "," << HistoryVector[i].getOrderTotal() << "," << BookVector[i].getPrice();
	for (int j = 0; j < CartVector[i].cartContents.size(); j++)
	{
		os << CartVector[i].cartContents[j].getIsbn() << "," << CartVector[i].cartContents[j].getQuantity() << "," << CartVector[i].cartContents[j].getPrice() << ","
			<< CartVector[i].cartContents[j].getTitle() << "," << CartVector[i].cartContents[j].getAuthor() << "," << CartVector[i].cartContents.getGenre();
	}
}