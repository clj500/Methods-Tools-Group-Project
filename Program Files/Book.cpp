#include "Book.h"

void Book::setQuantity(int quantity)
{
    this->quantity = quantity;
}

int Book::getIsbn()
{
    return isbn;
}

int Book::getQuantity()
{
    return quantity;
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
