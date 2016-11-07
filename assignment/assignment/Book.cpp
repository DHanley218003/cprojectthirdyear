#include "Book.h"

Book::Book(std::string nameParam, std::string authorParam, long ISBNParam)
{
	name = nameParam; author = authorParam; ISBN = ISBNParam;
}

Book::Book(void)
{
	name = "NULL";
	author = "NULL";
	ISBN = 0;
}

//getters
std::string Book::getName(void) { return name; }
std::string Book::getAuthor(void) { return author; }
long Book::getISBN(void) { return ISBN; }
Book* Book::getFirstBook(void) { return firstBook; }
Book* Book::getPreviousBook(void) { return previousBook; }
Book* Book::getNextBook(void) { return nextBook; }

//setters
void Book::setName(std::string nameParam) { name = nameParam; }
void Book::setAuthor(std::string authorParam) { author = authorParam; }
void Book::setISBN(long ISBNParam) { ISBN = ISBNParam; }
void Book::setFirstBook(Book *bookParam) { firstBook = bookParam; }
void Book::setPreviousBook(Book *bookParam) { previousBook = bookParam; }
void Book::setNextBook(Book *bookParam) { nextBook = bookParam; }