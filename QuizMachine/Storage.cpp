#include "Storage.h"

using namespace std;

void storage::saveNewUser(User &user)
{
	string toFile = "";
	ofstream outFileStream(usersFile, ios::app);

	toFile += user.getFirstName() + ' ';
	toFile += user.getLastName() + ' ';
	toFile += to_string(user.getScore());

	outFileStream << toFile << endl;
	outFileStream.close();
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

	return count;
}