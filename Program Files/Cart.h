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
    Cart() : userId(0), cartTotal(0) {}
    Cart(int userId) : userId(userId), cartTotal(0) {}
    void addToCart(int bookISBN, int quantity, vector<Book> books);
    void removeBook(int bookISBN);
    void outputCartContents();
    void checkoutCart();
    int getUserId();
    float getCartTotal();
};
