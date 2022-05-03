#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Book.h"

using namespace::std;

class History {
	private:
<<<<<<< HEAD
		int userId, orderId;
=======
		int userId;
>>>>>>> f58344558eb1059950b300d9fd344f2a8abaff81
		float orderTotal;
	public:
		vector<Book> orderContent;
	
<<<<<<< HEAD
		History() : userId(0), orderId(1), orderTotal(0.00) {}
		History(int userId, int orderId, float orderTotal) : userId(userId), orderId(orderId), orderTotal(orderTotal) {}
=======
		History() : userId(0), orderTotal(0.00) {}
		History(int userId, float orderTotal) : userId(userId), orderTotal(orderTotal) {}
>>>>>>> f58344558eb1059950b300d9fd344f2a8abaff81
		void displayOrderContent();
		void setOrderId(int orderId);
		int getUserId();
<<<<<<< HEAD
		int getOrderId();
=======
>>>>>>> f58344558eb1059950b300d9fd344f2a8abaff81
		float getOrderTotal();
};
