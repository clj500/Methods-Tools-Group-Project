#include "Cart.h"
int Cart::getUserId()
{
    return userId;
}

float Cart::getCartTotal()
{
    return cartTotal;
}

void Cart::addToCart(int bookISBN, int quantity, vector<Book> books)
{
    bool exists = false;

    for (int i = 0; i < cartContents.size(); i++)
    {
        if (cartContents[i].getIsbn() == bookISBN)
        {
            exists = true;
            cartContents[i].setQuantity(cartContents[i].getQuantity() + quantity);
            
            for (int i = 0; i < quantity; i++)
            {
                cartTotal += cartContents[i].getPrice();
            }
        }
    }

    if (exists == false)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].getIsbn() == bookISBN)
            {
                books[i].setQuantity(quantity);
                cartContents.push_back(books[i]);
               
                for (int i = 0; i < quantity; i++)
                {
                    cartTotal += books[i].getPrice();
                }
            }
        }
    }
}

void Cart::removeBook(int bookISBN)
{
    for (int i = 0; i < cartContents.size(); i++)
    {
        if (bookISBN == cartContents[i].getIsbn())
        {
            cartContents[i].setQuantity(cartContents[i].getQuantity() - 1);
            cartTotal -= cartContents[i].getPrice();

            if (cartContents[i].getQuantity() == 0)
            {
                cartContents.erase(cartContents.begin() + i);
            }
        }
    }
}

void Cart::outputCartContents()
{
    for (int i = 0; i < cartContents.size(); i++)
    {
        cout << cartContents[i].getTitle() << " x" << cartContents[i].getQuantity() << "         $" << cartContents[i].getPrice() << endl;
    }
}

void Cart::checkoutCart(vector<Book> books)
{
    int tempQuantity;

    for (int i = 0; i < cartContents.size(); i++)
    {
        tempQuantity = cartContents[i].getQuantity();

        for(int j = 0; j < books.size(); j++)
        {
            if (cartContents[i].getTitle() == books[i].getTitle())
            {
                books[i].setQuantity(tempQuantity);
            }
        }

        cartContents.erase(cartContents.begin() + i);
        cout << cartTotal << endl;
        cartTotal=0;
    }
}
 
