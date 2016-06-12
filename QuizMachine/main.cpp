#include <iostream>
#include "User.h";

using namespace std;

int main()
{
	User u = User("Alex", "123");
	
	u.setUserName("xelA");
	u.setPassword("456");

	cout << u.getUserName() << " " << u.getPassword() << endl;

	cin.get();
	return 0;
}