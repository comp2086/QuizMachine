#include "Storage.h"
#include <iostream>
#include <iomanip>

using namespace std;
using namespace storage;

int main()
{
	int answer = 0;
	int questionsCount = getQuestionsCount();
	string firstName, lastName;
	char runQuizAgain = 'n';

	do
	{ 
		// Ask for user's first/last name
		cout << "First Name: ";
		cin >> firstName;
		cout << "Last Name: ";
		cin >> lastName;

		// Check if a user has already written the quiz
		User user = findUser(firstName, lastName);
		if (user.getScore() != -1.0)
			cout << "Your highest score is: " << setprecision(3) << user.getScore() << endl;
		else
			cout << "This is your 1st attempt, do your best." << endl;

		// Display the total number of questions
		cout << "There're " << questionsCount << " questions in this quiz" << endl;

		// Display a question
		for (int i = 1; i <= questionsCount; i++)
		{
			Question question = getQuestion();
			cout << question.getQuestion() << '?' << endl;

			for (int g = 0; g <= 3; g++)
			{
				cout << g + 1 << ". " << question.getAnswer(g) << endl;
			}
			
			cout << "Your answer (1/2/3/4): ";

			// Loop until the correct input is given
			cin >> answer;

			// Check if the answer given is correct
		}

		// Display the score

		// Save the new score (if higher than the previous one)

		// Ask to run the quiz again
		cout << "One more time (y/n): ";
		cin >> runQuizAgain;
	} while (tolower(runQuizAgain) == 'y');

	// Quit
	return 0;
}