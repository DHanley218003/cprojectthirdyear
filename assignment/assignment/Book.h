#pragma once
#include <string>

class Book
{
public:

	Book(std::string nameParam, std::string authorParam, long long int ISBNParam);

	Book(void);

	void insertAfter(Book *bookParam);
	void insertBefore(Book *bookParam);

	//getters
	std::string getName(void);
	std::string getAuthor(void);
	long long int getISBN(void);
	Book* getPreviousBook(void);
	Book* getFirstBook(void);
	Book* getNextBook(void);
	bool isBookAvailable(void);

	//setters
	void setName(std::string nameParam);
	void setAuthor(std::string authorParam);
	void setISBN(long long int ISBNParam);
	void setPreviousBook(Book *bookParam);
	void setFirstBook(Book *bookParam);
	void setNextBook(Book *bookParam);
	void setAvailability(bool param);

private:
	std::string name;
	std::string author;
	long long int ISBN;
	Book *firstBook;
	Book *previousBook;
	Book *nextBook;
	bool isAvailable;
};