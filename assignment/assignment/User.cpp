#include "User.h"

User::User(std::string nameParam, std::string passwordParam, bool adminParam)
{userName = nameParam; password = passwordParam; admin = adminParam;}


//getters
std::string User::getName(void) { return userName; }
std::string User::getPassword(void) { return password; }
bool User::isAdmin(void) { return admin; }

//setters
void User::setName(std::string nameParam) { userName = nameParam; }
void User::setPassword(std::string passwordParam) { password = passwordParam; }
void User::setAdmin(bool adminParam) { admin = adminParam; }