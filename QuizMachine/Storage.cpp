#include "Storage.h"

using namespace std;

// Default no arguments constructor
Storage::Storage()
{
}

Storage::~Storage()
{
}

void Storage::saveNewUser(User &user)
{
	string toFile = "";
	this->outFileStream.open(usersFile, ios::app);

	toFile += user.getFirstName() + "\n";
	toFile += user.getLastName() + "\n";
	toFile += to_string(user.getHighestScore());

	this->outFileStream << toFile << endl;
	this->outFileStream.close();
}

User Storage::getUser(string lastName) const
{
	User user;
	
	// this->inFileStream.open()
	// ... find a user with the same lastname

	return user;
}

Question Storage::getQuestion() const
{
	// Read question from file
	Question question;

	// ... need to memorize location of the next question 
	// and start reading from there (+5 lines, maybe random +5 increments?)

	return question;
}
