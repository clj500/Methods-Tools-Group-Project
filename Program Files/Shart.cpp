#include <iostream>
#include <iomanip>
#include <vector>
#include "Book.h"

using namespace std;

class Cart
{
private:
    int userId; 
    float cartTotal;
    vector<Book> cartContents;
    
public:
    Cart(int userId) : userId(userId), cartTotal(0) {}
    void addToCart(Book novel);
    void removeBook(string bookName);
    void outputCartContents();
    void checkoutCart();
    int getUserId();
    int getCartTotal();


};
int Cart::getUserId()
{
    return userId;
}
float Cart::getCartTotal()
{
    return cartTotal;
}
void Cart::addToCart(Book novel)
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
 
