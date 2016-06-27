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
	this->score = -1;
}

// Constructor with highest score
User::User(string firstName, string lastName, double score)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->score = score;
}

void User::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void User::setLastName(string lastName)
{
	this->lastName = lastName;
}

void User::setScore(double score)
{
	this->score = score;
}

string User::getFirstName() const
{
	return this->firstName;
}

string User::getLastName() const
{
	return this->lastName;
}

double User::getScore() const
{
	return this->score;
}
