#include "Storage.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;
using namespace storage;

int validateAnswer();
char validateRunQuizAgain();
string validateName();

int main()
{
	string firstName = "", lastName = "";
	int answer = 0, correctAnswersCount = 0,
		questionsCounter = getQuestionsCount(),
		totalQuestions = questionsCounter;
	char runQuizAgain = 'n';
	bool newUser = false;

	// Ask for user's first/last name
	cout << "First Name: ";
	firstName = validateName();
	cout << "Last Name: ";
	lastName = validateName();

	// Check if a user has already written the quiz
	User user = findUser(firstName, lastName);
	if (user.getScore() != -1.0)
		cout << "Your highest score is: " 
		<< setprecision(3)
		<< user.getScore() << ' '
		<< endl;
	else
	{
		newUser = true;
		cout << "This is your 1st attempt, do your best." << endl;
	}	

	// Display the total number of questions
	cout << "There're " << questionsCounter 
		<< " questions in this quiz. Let's get started!" << endl;

	do
	{
		// Tell cin to ignore everything or ignore until there's a newline character
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		while (questionsCounter != 0)
		{
			// Display a question
			Question question = getQuestion();
			cout << '\n' << question.getQuestion() << '?' << endl;

			// Display answers
			for (int g = 0; g <= 3; g++)
			{
				cout << g + 1 << ". " << question.getAnswer(g) << endl;
			}
			
			// Read the answer and validate it
			cout << "Your asnwer: ";
			answer = validateAnswer();

			// Check if the answer given is correct
			if (question.checkCorrectAnswer(answer))
				correctAnswersCount += 1;

			// Display the number of correct answers
			if (questionsCounter > 1)
				cout << "Score: " << correctAnswersCount 
				<< "/" << totalQuestions << endl;

			answer = 0;
			questionsCounter -= 1;
		}

		// Display the score
		double finalScore = static_cast<double>(correctAnswersCount) / totalQuestions * 100;
		cout << "Your final score is: " 
			<< setprecision(3) << finalScore 
			<< '%' << endl;

		// Display the average score
		double average = getAverageScore();
		if (average != -1)
		{
			cout << "The average score for the quiz is " 
				 << setprecision(3) << average << "%" << endl;
		}	

		// Save the new score if higher than the previous one
		// For a new user it will be always higher, since the default score is -1
		if (user.getScore() < finalScore)
		{
			user.setScore(finalScore);
			saveUser(user, newUser);
		}

		// Reset the quiz variables and prompt to run the quiz again
		questionsCounter = getQuestionsCount();
		correctAnswersCount = 0;
		cout << "One more time (y/n): ";
		runQuizAgain = validateRunQuizAgain();
	} while (tolower(runQuizAgain) == 'y');

	// The end
	return 0;
}

int validateAnswer()
{
	int answer = -1;
	string userInput = "";

	while (getline(cin, userInput))
	{
		stringstream strStream(userInput);
		if (!(strStream >> answer))
		{
			// Parse error
			cout << "Invalid input, please enter 1, 2, 3 or 4: ";
			continue;
		}

		if ((answer > 4) || (answer < 1))
		{
			cout << "Invalid input, please enter 1, 2, 3 or 4: ";
			continue;
		}
		char badChar;
		if (strStream >> badChar)
		{
			// If there was something after the number, e.g 2a
			cout << "Invalid input, please enter 1, 2, 3 or 4: ";
			continue;
		}

		// Input validated, quit the loop
		break;
	}

	return answer;
}

char validateRunQuizAgain()
{
	char runQuizAgain = ' ';

	while (cin >> runQuizAgain)
	{
		if (runQuizAgain != 'y' &&
			runQuizAgain != 'n' &&
			runQuizAgain != 'Y' &&
			runQuizAgain != 'N')
		{
			cout << "Invalid input. Plese enter y/n: ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		// Input validated
		break;
	}

	return runQuizAgain;
}

string validateName()
{
	string name = "";

	while (cin >> name)
	{
		bool badInput = false;

		for (int i = 0; i < name.length(); i++)
		{
			if (!isalpha(name[i]))
			{
				cout << "Invalid input, only letters are allowed, try again: ";
				badInput = true;
				break;
			}
		}
		// Input validated
		if (!badInput)
			break;
	}

	return name;
}