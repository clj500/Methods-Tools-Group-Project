#include "Book.h"

void Book::setAmountOfBook(int amountOfBook)
{
    this->amountOfBook = amountOfBook;
}

int Book::getIsbn(): 
{
    return isbn;
}

int Book::getAmountOfBook()
{
    return amountOfBook;
}

float Book::getPrice()
{
    return price;
}

string Book::getTitle()
{
    return title;
}

string Book::getAuthor()
{
    return author;
}

string Book::getGenre()
{
    return genre;
}
