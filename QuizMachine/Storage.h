#include "User.h"
#include "Question.h"
#include <string>


namespace storage
{
	void saveNewUser(User &user);
	User findUser(std::string, std::string);
	Question getQuestion();
	int getQuestionsCount();

	static unsigned int location;
	const std::string usersFile = "Users.txt";
	const std::string questionsFile = "Questions.txt";
};

