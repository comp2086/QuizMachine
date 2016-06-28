#include <string>
#include <array>

class Question
{
public:
	Question();
	Question(std::string, std::array<std::string, 4>);
	void setQuestion(std::string);
	void setAnswers(std::array<std::string, 4>);
	std::string getQuestion() const;
	std::string getAnswer(int) const;
	bool checkCorrectAnswer(int) const;
private:
	std::string question;
	std::array<std::string, 4> answers;
	int correctAnswerIndex;
};

