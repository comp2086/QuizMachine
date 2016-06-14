#include "User.h"
#include "Question.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

class Storage
{
public:
	Storage();
	~Storage();
	void saveNewUser(User &user);
	User getUser(string) const;
	Question getQuestion() const;

private:
	const std::string usersFile = "Users.txt";
	const std::string questionsFile = "Questions.txt";
	std::ofstream outFileStream;
	std::ifstream inFileStream;
};

