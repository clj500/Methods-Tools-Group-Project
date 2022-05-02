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

    void setAmountInStock(amountInStock)
    {
        this->amountInStock = amountInStock;
    }

    int getIsbn(): 
    {
        return isbn;
    }

    int getAmountInStock()
    {
        return amountInStock;
    }

    float getPrice()
    {
        return price;
    }

    string getTitle()
    {
        return title;
    }

    string getAuthor()
    {
        return author;
    }

    string getGenre()
    {
        return genre;
    }
};