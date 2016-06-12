#include "User.h"

using namespace std;

// Constructor
User::User(string userName, string password)
{
	this->userName = userName;
	this->password = password;
}

// Destructor
User::~User()
{
}

void User::setUserName(string userName)
{
	this->userName = userName;
}

void User::setPassword(string password)
{
	this->password = password;
}

string User::getUserName() const
{
	return this->userName;
}

string User::getPassword() const
{
	return this->password;
}
