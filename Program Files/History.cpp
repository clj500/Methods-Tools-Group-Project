#include "History.h"

void History::displayOrderContent() {

    for (int i = 0; i < orderContent.size(); i++) {
            cout << "   Title - " << orderContent[i].getTitle() << endl;
            cout << "    ISBN - " << orderContent[i].getIsbn() << endl;
            cout << "   Price - " << orderContent[i].getPrice() << endl;
            cout << "Quantity - " << orderContent[i].getQuantity() << endl << endl;
        }
}
void History::setOrderId(orderId) {
    this->orderId = orderId;
}
int History::getUserId() {
    return userId;
}
int History::getOrderId() {
    return orderId;
}
float History::getOrderTotal() {
    return orderTotal;
}
