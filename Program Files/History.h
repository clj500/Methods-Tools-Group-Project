#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Book.h"

using namespace::std;

class History {
	private:
		int userId, orderId;
		float orderTotal;
	public:
		vector<Book> orderContent;
	
		History() : userId(0), orderId(1), orderTotal(0.00) {}
		History(int userId, int orderId, float orderTotal) : userId(userId), orderId(orderId), orderTotal(orderTotal) {}
		void displayOrderContent();
		void setOrderId();
		int getUserId();
		int getOrderId();
		float getOrderTotal();
};
