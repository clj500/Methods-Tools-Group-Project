#pragma once
#include <string>
using namespace std;
class Book
{
private:
    int isbn;
    int quantity;
    float price;
    string title;
    string author;
    string genre;

public:
    Book(int isbn, int quantity, float price, string title, string author, string genre) : 
    isbn(isbn), quantity(quantity) price(price), title(title), author(author), genre(genre) {}

    void setQuantity(int quantity);
    int getIsbn();
    int getQuantity();
    float getPrice();
    string getTitle();
    string getAuthor();
    string getGenre();
};
