#include <iostream>
#include "User.h";

using namespace std;

int main()
{
	User u = User("Alex", "123");
	
	u.setFirstName("a");
	u.setLastName("a");

	cout << u.getFirstName() << " " << u.getLastName() << endl;

	cin.get();
	return 0;
}