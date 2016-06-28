#include "Storage.h"
#include <iostream>
#include <iomanip>

using namespace std;
using namespace storage;

int main()
{
	bool newUser = false;
	int answer = 0, correctAnswersCount = 0;
	string firstName, lastName;
	char runQuizAgain = 'n';
	int questionsCounter = getQuestionsCount();
	int totalQuestions = questionsCounter;

	// Ask for user's first/last name
	cout << "First Name: ";
	cin >> firstName;
	cout << "Last Name: ";
	cin >> lastName;

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

			// Loop until the correct input is given
			while (answer > 4 || answer < 1)
			{
				cout << "Your answer (1/2/3/4): ";
				cin >> answer;
			}

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
		float finalScore = static_cast<float>(correctAnswersCount) / totalQuestions * 100;
		cout << "Your final score is: " 
			<< setprecision(3) << finalScore 
			<< '%' << endl;

		// Save the new score if higher than the previous one
		if (user.getScore() < finalScore)
		{
			user.setScore(finalScore);
			saveUser(user, newUser);
		}

		// Reset the quiz variables and prompt to run the quiz again
		questionsCounter = getQuestionsCount();
		correctAnswersCount = 0;
		cout << "One more time (y/n): ";
		cin >> runQuizAgain;
	} while (tolower(runQuizAgain) == 'y');

	// Quit
	return 0;
}