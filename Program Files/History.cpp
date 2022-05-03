#include "History.h"

void History::displayOrderContent() {
    orderContent.size
        for (i = 0 : i < orderContent.size(); i++) {
            cout << "Book" << i + 1 << endl;
            cout << "   Title - " << orderContent[i].getTitle() << endl;
            cout << "    ISBN - " << orderContent[i].getIsbn() << endl;
            cout << "   Price - " << orderContent[i].getPrice() << endl;
            cout << "Quantity - " << orderContent[i].getQuantity() << endl;
        }
            


         


}
int History::getUserId() {
    return userId;
}
string History::getDate() {
    return date;
}
int History::getOrderTotal() {
    return orderTotal;
}
string History::getTime() {
    return time;
}
