#include "User.h"

using namespace std;

// Default no arguments constructor
User::User()
{
}

// Constructor without highest score
User::User(string firstName, string lastName)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->highestScore = -1;
}

// Constructor with highest score
User::User(string firstName, string lastName, float highestScore)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->highestScore = highestScore;
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
