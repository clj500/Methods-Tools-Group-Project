#include "Shart.h"
int Cart::getUserId()
{
    return userId;
}

float Cart::getCartTotal()
{
    return cartTotal;
}

void Cart::addToCart(Book novel, int quantity)
{
    bool exists = false;

    for (int i = 0; i < cartContents.size(); i++)
    {
        if (cartContents[i].getTitle() == novel.getTitle())
        {
            exists = true;
            cartContents[i].setQuantity(cartContents[i].getQuantity() + quantity);
        }
    }

    if (exists == false)
    {
        novel.setQuantity(quantity);
        cartContents.push_back(novel);
    }
    
    for (int i = 0; i < quantity; i++)
    {
        cartTotal += novel.getPrice();
         
    }
}

void Cart::removeBook(string bookName)
{
    for (int i = 0; i < cartContents.size(); i++)
    {
        if (bookName == cartContents[i].getTitle())
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
        cout << cartContents[i].getTitle() << " x" << cartContents[i].getQuantity() << " $" << cartContents[i].getPrice() << endl;
    }
}

void Cart::checkoutCart()
{
    for (int i = 0; i < cartContents.size(); i++)
    {
        cartContents.erase(cartContents.begin() + i);
        cout << cartTotal << endl;
        cartTotal=0;
    }
}
 
