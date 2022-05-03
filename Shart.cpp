#include <iostream>
#include <iomanip>
#include <vector>
#include "Book.h"

using namespace std;

class Cart
{
private:
    int userId;
    int cartId; 
    int cartTotal;
    vector<Book> cartContents;
    
public:
    void addToCart(Book novel, int quantity);
    void removeBook(string bookName, int quantity);
    void outputCartContents();
    void checkoutCart();
    int getUserId();
    int getCartId();
    int getCartTotal();


};
int Cart::getUserId()
{
    return userId;
}
int Cart::getCartId()
{
    return cartId;
}
int Cart::getCartTotal()
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
void removeBook(string bookName, int quantity)
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
 
