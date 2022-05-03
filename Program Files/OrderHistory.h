#ifndef HISTORY_H
#define HISTORY_H
#include <iostream>
#include <string>

using mamespace::std;

class History {
	private:
		int userId;
		int orderId;
		string date;
		string time;
		vector<Book> orderContent;
		int orderTotal;
	public:
		History();
		void addOrder(userId, orderId, date, time, orderContent, orderTotal)
		void displayOrderContent();
		int getUserId;
		int getOrderId;
		string getDate;
		string getTime;
		int getOrderTotal;
};
