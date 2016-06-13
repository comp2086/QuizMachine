#include <iostream>
#include "Storage.h"

using namespace std;

int main()
{
	Storage storage;
	User user("Alex", "123");

	storage.saveNewUser(user);

	cin.get();
	return 0;
}