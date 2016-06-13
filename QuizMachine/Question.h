#include <string>
#include <vector>

class Question
{
public:
	Question(std::string, std::vector<std::string>);
	~Question();
	void setQuestion(std::string);
	void setAnswers(std::vector<std::string>);
	std::string getQuestion() const;
	std::vector<std::string> getAnswers() const;

private:
	std::string question;
	std::vector<std::string> answers;
};

