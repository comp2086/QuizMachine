#include "Storage.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

void storage::saveUser(User &user, bool newUser = false)
{
	double score;
	string fName, lName;
	vector<User> *users = new vector<User>();

	// Read all users
	ifstream inFileStream(usersFile, ios::in);
	if (!inFileStream)
	{
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}

	do
	{
		inFileStream >> fName >> lName >> score;
		users->push_back(User(fName, lName, score));
	} while (!inFileStream.eof());

	// Add a new user
	if (newUser)
	{
		users->push_back(user);
	}
	// Update the existing one with a new grade
	else
	{
		for (User &user_ : *users)
		{
			if (user_.getFirstName() == user.getFirstName() &&
				user_.getLastName() == user.getLastName())
				user_.setScore(user.getScore());
		}
	}

	// Sort users by the first name
	sort(users->begin(), users->end(),
		[](User const &u1, User const &u2) -> bool {
		return u1.getFirstName() < u2.getFirstName();
	});

	// Write to the file
	ofstream outFileStream(usersFile, ios::out);
	if (!outFileStream)
	{
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}

	for (User user_ : *users)
	{
		outFileStream << user_.getFirstName() << ' '
			<< user_.getLastName() << ' '
			<< setprecision(3) << user_.getScore() << endl;
	}

	inFileStream.close();
	outFileStream.close();

	// Free up memory
	delete users;
	users = nullptr;
}

User storage::findUser(string firstName, string lastName)
{
	User user(firstName, lastName);
	string fName, lName;
	double score;
	bool stop = false;

	ifstream inFileStream(usersFile, ios::in);

	if (!inFileStream)
	{
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}

	// Read from the file until a match is found or EOF
	do
	{
		inFileStream >> fName >> lName >> score;

		if (user.getFirstName() == fName &&
			user.getLastName() == lName)
		{
			user.setScore(score);
			stop = true;
		}
	} while (!stop && !inFileStream.eof());
	inFileStream.close();

	return user;
}

Question storage::getQuestion()
{
	string q;
	array<string, 4> answers;
	Question question;
	ifstream inFileStream(questionsFile, ios::in);

	// Move to the next location
	inFileStream.seekg(location);

	// 1. Based on the argument, extract the question from a file
	inFileStream >> q >> answers[0] >> answers[1] >> answers[2] >> answers[3];

	// Save location of the next question
	location = static_cast<unsigned int>(inFileStream.tellg());

	// Reset locatio if this is the end of file
	if (inFileStream.eof())
		location = 0;

	// Close the stream
	inFileStream.close();

	// Create a question object and return it
	question = Question(q, answers);

	return question;
}

int storage::getQuestionsCount()
{
	int count = 0;
	string line;
	ifstream inFileStream(questionsFile, ios::in);

	while (getline(inFileStream, line))
	{
		count += 1;
	}
	inFileStream.close();

	return count;
}