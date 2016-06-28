#include "Question.h"
#include <string>

using namespace std;

// Default no arguments constructor
Question::Question()
{
}

// Constructor
Question::Question(string question, array<string, 4> answers)
{
	this->question = question;
	this->answers = answers;
}

void Question::setQuestion(string question)
{
	this->question = question;
}

void Question::setAnswers(array<string, 4> answers)
{
	this->answers = answers;
}

string Question::getQuestion() const
{
	return this->question;
}

string Question::getAnswer(int index) const
{
	return this->answers[index];
}

