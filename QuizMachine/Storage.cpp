#include "Storage.h"

using namespace std;

// Constructor
Storage::Storage()
{
	this->outFileUsers = ofstream(this->usersFile, ios::out);
}

Storage::~Storage()
{
}

void Storage::saveNewUser(User &user)
{
	string toFile = "";

	toFile += user.getFirstName() + "\n";
	toFile += user.getLastName() + "\n";
	toFile += user.getHighestScore();

	outFileUsers << toFile << endl;
}
