#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Book.h"

using namespace::std;

class History {
	private:
		int userId;
		float orderTotal;
	public:
		vector<Book> orderContent;
	
		History() : userId(0), orderTotal(0.00) {}
		History(int userId, float orderTotal) : userId(userId), orderTotal(orderTotal) {}
		void displayOrderContent();
		int getUserId();
		float getOrderTotal();
};
