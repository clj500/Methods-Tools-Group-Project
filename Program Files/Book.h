#pragma once
#include <string>
using namespace std;
class Book
{
private:
    int isbn;
    int amountOfBook;
    float price;
    string title;
    string author;
    string genre;

public:
    Book(int isbn, int amountOfBook, float price, string title, string author, string genre) : isbn(isbn), amountOfBook(amountOfBook) price(price), title(title), author(author), genre(genre) {}

    void setAmountOfBook(int amountOfBook);
    int getIsbn();
    int getAmountOfBook();
    float getPrice();
    string getTitle();
    string getAuthor();
    string getGenre();
};
