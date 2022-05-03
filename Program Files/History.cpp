#include "History.h"

void History::displayOrderContent() {

    for (int i = 0; i < orderContent.size(); i++) {
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
int History::getOrderId() {
    return orderId;
}
string History::getDate() {
    return date;
}
float History::getOrderTotal() {
    return orderTotal;
}
string History::getTime() {
    return time;
}
