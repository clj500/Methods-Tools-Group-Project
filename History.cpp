#include "History.h"

void History::displayOrderContent() {

    for (int i = 0; i < orderContent.size(); i++) {
<<<<<<< HEAD
            cout << "   Title - " << orderContent[i].getTitle() << endl;
            cout << "    ISBN - " << orderContent[i].getIsbn() << endl;
            cout << "   Price - " << orderContent[i].getPrice() << endl;
            cout << "Quantity - " << orderContent[i].getQuantity() << endl << endl;
        }
}
void History::setOrderId(int orderId) {
    this->orderId = orderId;
=======
            cout << "  Title - " << orderContent[i].getTitle() << endl;
            cout << "  ISBN - " << orderContent[i].getIsbn() << endl;
            cout << "  Price - " << orderContent[i].getPrice() << endl;
            cout << "  Quantity - " << orderContent[i].getQuantity() << endl << endl;
        }
>>>>>>> f58344558eb1059950b300d9fd344f2a8abaff81
}
int History::getUserId() {
    return userId;
}
<<<<<<< HEAD
int History::getOrderId() {
    return orderId;
}
=======
>>>>>>> f58344558eb1059950b300d9fd344f2a8abaff81
float History::getOrderTotal() {
    return orderTotal;
}
