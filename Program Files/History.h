#include <History.h>
#include <iostream>


using mamespace::std;

class History {
	private:
		int userId;
		string date;
		string time;
		vector<Book> orderContent;
		float orderTotal;
	public:
		History(int userId, string date, string time, float orderTotal) : userId(userId), date(date), time(time), orderTotal(orderTotal);
		void displayOrderContent();
		int getUserId;
		int getOrderId;
		string getDate;
		string getTime;
		float getOrderTotal;
};
