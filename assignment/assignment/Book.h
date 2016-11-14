#pragma once
#include <string>

class Book
{
public:

	Book(std::string nameParam, std::string authorParam, unsigned int ISBNParam);

	Book(void);

	void insertAfter(Book *bookParam);
	void insertBefore(Book *bookParam);

	//getters
	std::string getName(void);
	std::string getAuthor(void);
	unsigned int getISBN(void);
	Book* getPreviousBook(void);
	Book* getFirstBook(void);
	Book* getNextBook(void);
	bool isBookAvailable();

	//setters
	void setName(std::string nameParam);
	void setAuthor(std::string authorParam);
	void setISBN(unsigned int ISBNParam);
	void setPreviousBook(Book *bookParam);
	void setFirstBook(Book *bookParam);
	void setNextBook(Book *bookParam);
	void setAvailability(bool param);

private:
	std::string name;
	std::string author;
	unsigned int ISBN;
	Book *firstBook = NULL;
	Book *previousBook = NULL;
	Book *nextBook = NULL;
	bool isAvailable;
};