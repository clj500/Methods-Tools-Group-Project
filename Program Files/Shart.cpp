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
    cartContents.push_back(novel);
    
    for (int i = 0; i < cartContents.size(); i++)
    {
        cartTotal += novel.getPrice();
    }
}
void Cart::removeBook(string bookName, int quantity)
{
    for (int i = 0; i < cartContents.size(); i++)
    {
        if (bookName == cartContents[i].getTitle())
        {
            cartContents.erase(cartContents.begin() + i);
        }
    }
}
void Cart::outputCartContents()
{
    for (int i = 0; i < cartContents.size(); i++)
    {
        cout << cartContents[i] << endl;
    }
}
void Cart::checkoutCart()
{
    for (int i = 0; i < cartContents.size(); i++)
    {
         
        cartContents.erase(cartContents.begin() + i);
        cartTotal -=  cartContents[i].getPrice();
        
    }
}
 
