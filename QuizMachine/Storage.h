#include "User.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

class Storage
{
public:
	Storage();
	~Storage();
	void saveNewUser(User &user);
private:
	const std::string usersFile = "C:\\Users.txt";
	std::ofstream outFileUsers;
};

