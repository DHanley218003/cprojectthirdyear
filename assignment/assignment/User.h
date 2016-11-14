#pragma once
#include <string>

class User 
{
public:
	User(std::string nameParam, std::string passwordParam, bool adminParam);

	//getters
	std::string getName(void);
	std::string getPassword(void);
	bool isAdmin(void);

	//setters
	void setName(std::string nameParam);
	void setPassword(std::string passwordParam);
	void setAdmin(bool adminParam);

private:
	std::string userName;
	std::string password;
	bool admin = false;
};