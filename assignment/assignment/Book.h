#pragma once
#include <string>

class Book
{
public:

	Book(std::string nameParam, std::string authorParam, long ISBNParam);

	Book(void);

	//getters
	std::string getName(void);
	std::string getAuthor(void);
	long getISBN(void);
	Book* getPreviousBook(void);
	Book* getFirstBook(void);
	Book* getNextBook(void);

	//setters
	void setName(std::string nameParam);
	void setAuthor(std::string authorParam);
	void setISBN(long ISBNParam);
	void setPreviousBook(Book *bookParam);
	void setFirstBook(Book *bookParam);
	void setNextBook(Book *bookParam);

private:
	std::string name;
	std::string author;
	long ISBN;
	Book *firstBook = NULL;
	Book *previousBook = NULL;
	Book *nextBook = NULL;
};