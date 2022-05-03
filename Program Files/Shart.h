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
    void addToCart(Book novel, int quantity);
    void removeBook(string bookName, int quantity);
    void outputCartContents();
    void checkoutCart();
    int getUserId();
    int getCartTotal();


};