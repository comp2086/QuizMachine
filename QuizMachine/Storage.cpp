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
	outFileStream.open(usersFile, ios::app);

	toFile += user.getFirstName() + "\n";
	toFile += user.getLastName() + "\n";
	toFile += to_string(user.getHighestScore());

	outFileStream << toFile << endl;

	outFileStream.close();
}

Question Storage::getQuestion() const
{
	// Read question from file
	Question question;

	// ...

	return question;
}
