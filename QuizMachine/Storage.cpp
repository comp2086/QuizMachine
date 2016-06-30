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

	while (inFileStream >> fName >> lName >> score)
	{
		users->push_back(User(fName, lName, score));
	}
	inFileStream.close();

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
			if (strToLower(user_.getFirstName()) == strToLower(user.getFirstName()) &&
				strToLower(user_.getLastName()) == strToLower(user.getLastName()))
				user_.setScore(user.getScore());
		}
	}

	// Sort users by the first name (case insensitive)
	sort(users->begin(), users->end(),
		[](User const &u1, User const &u2) -> bool {

		return strToLower(u1.getFirstName()) < strToLower(u2.getFirstName());
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

	outFileStream.close();

	// Free up the memory
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

		if (strToLower(user.getFirstName()) == strToLower(fName) &&
			strToLower(user.getLastName()) == strToLower(lName))
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
	array<string, answersCount> answers;
	Question question;
	ifstream inFileStream(questionsFile, ios::in);

	if (!inFileStream)
	{
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}

	// Move to the next location
	inFileStream.seekg(location);

	// Extract a question and its answers from the file
	getline(inFileStream, q);

	for (int i = 0; i < answersCount; i++)
	{
		getline(inFileStream, answers[i]);
	}

	// Save location of the next question
	location = static_cast<unsigned int>(inFileStream.tellg());

	// Reset location if this is the end of file
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

	// A question spans around 5 lines
	return count / 5;
}

double storage::getAverageScore()
{
	double score, average;
	string fName, lName;
	vector<User> *users = new vector<User>();

	ifstream inFileStream(usersFile, ios::in);
	if (!inFileStream)
	{
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}

	// Read all users
	while (inFileStream >> fName >> lName >> score)
	{
		users->push_back(User(fName, lName, score));
	}
	inFileStream.close();

	// Calculate the average
	unsigned int usersCount = static_cast<unsigned int>((*users).size());
	if (usersCount > 0)
	{
		score = 0;
		for (User user : *users)
		{
			score += user.getScore();
		}
		average = score / usersCount;
	}
	else
	{
		average = -1;
	}

	// Free up the memory
	delete users;
	users = nullptr;

	return average;
}

// Converts a string to the lower case
string storage::strToLower(string str)
{
	string lowerCaseStr = "";

	for (int i = 0; i < str.size(); i++)
	{
		lowerCaseStr += tolower(str[i]);
	}

	return lowerCaseStr;
}