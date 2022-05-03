#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Book.h"

using namespace::std;

class History {
	private:
		int userId, orderId;
		string date;
		string time;
		float orderTotal;
	public:
		vector<Book> orderContent;
	
		History() : userId(0), orderId(1), date(""), time(""), orderTotal(0.00) {}
		History(int userId, int orderId, string date, string time, float orderTotal) : userId(userId), orderId(orderId), date(date), time(time), orderTotal(orderTotal) {}
		void displayOrderContent();
		int getUserId();
		int getOrderId();
		string getDate();
		string getTime();
		float getOrderTotal();
};
