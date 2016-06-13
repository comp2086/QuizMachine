#include "Storage.h"
#include <iostream>

using namespace std;

int main()
{
	Storage storage;
	User user("Alex", "123");

	storage.saveNewUser(user);

	cin.get();
	return 0;
}