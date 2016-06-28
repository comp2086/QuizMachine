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

	int numberOfAnswers = static_cast<int>(answers.size());

	// Save the number of correct answer
	for (int i = 0; i < numberOfAnswers; i++)
	{
		int upperCharsCounter = 0;
		int strLength = static_cast<int>(answers[i].length());

		// Check if all chars are uppercase or a punctuation/space char
		for (int g = 0; g < strLength; g++)
		{
			char charToTest = answers[i][g];

			if (isupper(charToTest) ||
				iscntrl(charToTest) ||
				isdigit(charToTest) ||
				ispunct(charToTest) ||
				isspace(charToTest))
				upperCharsCounter += 1;	
		}

		if (upperCharsCounter == strLength)
		{
			this->correctAnswerIndex = i;
			break;
		}
	}
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
	string answer = "";
	int strLength = static_cast<int>(answers[index].length());

	// Transform to lowercase
	for (int i = 0; i < strLength; i++)
	{
		answer += tolower(answers[index][i]);
	}

	return answer;
}

// Returns true if the answer was correct, false otherwise
bool Question::checkCorrectAnswer(int answerNumber) const
{
	if (answerNumber - 1 == this->correctAnswerIndex)
		return true;
	else
		return false;
}

