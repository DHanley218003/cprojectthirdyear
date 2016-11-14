#include "Book.h"

Book::Book(std::string nameParam, std::string authorParam, unsigned int ISBNParam)
{
	name = nameParam; author = authorParam; ISBN = ISBNParam;
}

Book::Book(void)
{
	name = "NULL";
	author = "NULL";
	ISBN = 0;
}

void Book::insertAfter(Book *bookParam)
{
	bookParam->setFirstBook(firstBook);
	bookParam->setNextBook(nextBook);
	bookParam->setPreviousBook(this);
	nextBook = bookParam;
}

void Book::insertBefore(Book *bookParam)
{
	bookParam->setFirstBook(firstBook);
	bookParam->setNextBook(this);
	bookParam->setPreviousBook(previousBook);
	previousBook = bookParam;
}

//getters
std::string Book::getName(void) { return name; }
std::string Book::getAuthor(void) { return author; }
unsigned int Book::getISBN(void) { return ISBN; }
Book* Book::getFirstBook(void) { return firstBook; }
Book* Book::getPreviousBook(void) { return previousBook; }
Book* Book::getNextBook(void) { return nextBook; }
bool Book::isBookAvailable(void) { return isAvailable; }

//setters
void Book::setName(std::string nameParam) { name = nameParam; }
void Book::setAuthor(std::string authorParam) { author = authorParam; }
void Book::setISBN(unsigned int ISBNParam) { ISBN = ISBNParam; }
void Book::setFirstBook(Book *bookParam) { firstBook = bookParam; }
void Book::setPreviousBook(Book *bookParam) { previousBook = bookParam; }
void Book::setNextBook(Book *bookParam) { nextBook = bookParam; }
void Book::setAvailability(bool param) { isAvailable = param; }