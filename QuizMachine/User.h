#include <string>

class User
{
public:
	User();
	User(std::string, std::string);
	User(std::string, std::string, double);
	void setFirstName(std::string);
	void setLastName(std::string);
	void setScore(double);
	std::string getFirstName() const;
	std::string getLastName() const;
	double getScore() const;

private:
	std::string firstName, lastName;
	double score;
};

