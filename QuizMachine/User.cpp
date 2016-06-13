#include "User.h"

using namespace std;

// Constructor
User::User(string firstName, string lastName)
{
	this->firstName = firstName;
	this->lastName = lastName;
}

// Destructor
User::~User()
{
}

void User::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void User::setLastName(string lastName)
{
	this->lastName = lastName;
}

void User::setHighestScore(float highestScore)
{
	this->highestScore = highestScore;
}

string User::getFirstName() const
{
	return this->firstName;
}

string User::getLastName() const
{
	return this->lastName;
}

float User::getHighestScore() const
{
	return this->highestScore;
}
