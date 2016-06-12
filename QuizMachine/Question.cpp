#include "Question.h"

using namespace std;

// Constructor
Question::Question(string question, vector<string> answers)
{
	this->question = question;
	this->answers = answers;
}

// Destructor
Question::~Question()
{

}

void Question::setQuestion(string question)
{
	this->question = question;
}

void Question::setAnswers(vector<string> answers)
{
	this->answers = answers;
}

string Question::getQuestion() const
{
	return this->question;
}

vector<string> Question::getAnswers() const
{
	return this->answers;
}

