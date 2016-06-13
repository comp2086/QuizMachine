#include <string>

class User
{
public:
	User();
	User(std::string, std::string);
	User(std::string, std::string, float);
	~User();
	void setFirstName(std::string);
	void setLastName(std::string);
	void setHighestScore(float);
	std::string getFirstName() const;
	std::string getLastName() const;
	float getHighestScore() const;

private:
	std::string firstName;
	std::string lastName;
	float highestScore;
};

