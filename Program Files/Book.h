#pragma once
#include <string>
using namespace std;
class Book
{
private:
    int isbn;
    int amountInStock;
    float price;
    string title;
    string author;
    string genre;

public:
    Book(int isbn, int amountInStock, float price, string title, string author, string genre) : isbn(isbn), amountInStock(amountInStock) price(price), title(title), author(author), genre(genre) {}

    void setAmountInStock(int amountInStock);
    int getIsbn();
    int getAmountInStock();
    float getPrice();
    string getTitle();
    string getAuthor();
    string getGenre();
};
