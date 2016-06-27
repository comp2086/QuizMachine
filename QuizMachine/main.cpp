#include "Storage.h"
#include <iostream>
#include <iomanip>

using namespace std;
using namespace storage;

int main()
{
	int questionsCount;
	string firstName, lastName;

	// Ask for user's first/last name
	cout << "Hello!\nFirst Name: ";
	cin >> firstName;
	cout << "Last Name: ";
	cin >> lastName;

	// Check if they have already written the quiz
	User user = findUser(firstName, lastName);
	if (user.getScore() != -1.0)
		cout << "Your highest score is: " << setprecision(3) << user.getScore();
	else
		cout << "This is your 1st attempt!" << endl;

	// -Run the quiz-
	// 1. Display the total number of questions
	questionsCount = getQuestionsCount();
	cout << "There're " << questionsCount << " questions in this quiz" << endl;

	// 2. Display a question

	// 3. Display the rest of the questions

	// 4. Display the score

	// 5. Save the new score (if higher than the previous one)

	// 6. Ask to run the quiz again

	// 7. Quit
	return 0;
}