#include <string>

class User
{
public:
	User(std::string, std::string);
	~User();
	void setUserName(std::string);
	void setPassword(std::string);
	std::string getUserName() const;
	std::string getPassword() const;
private:
	std::string userName;
	std::string password;
};

