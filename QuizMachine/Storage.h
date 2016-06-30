#include "User.h"
#include "Question.h"
#include <string>


namespace storage
{
	void saveUser(User &user, bool);
	User findUser(std::string, std::string);
	Question getQuestion();
	int getQuestionsCount();
	double getAverageScore();
	std::string strToLower(std::string);

	static unsigned int location;
	const std::string usersFile = "Users.txt";
	const std::string questionsFile = "Questions.txt";
	const int answersCount = 4;
};

