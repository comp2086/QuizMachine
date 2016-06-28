#include "User.h"
#include "Question.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

namespace storage
{
	void saveNewUser(User &user);
	User findUser(std::string, std::string);
	Question getQuestion();
	int getQuestionsCount();
	void resetLocation();

	static unsigned int location;
	const std::string usersFile = "Users.txt";
	const std::string questionsFile = "Questions.txt";
};

