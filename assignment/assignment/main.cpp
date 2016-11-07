#include <iostream>
#include "Book.h"
#include <mutex>
#include <fstream>
#include <stdexcept>
#include "ClearScreen.h"

Book * loadFile(void);
void printAllBooks(Book *firstBook);
void saveAllBooks(Book *currentBook);
void saveABook(Book *currentBook);

int main(void)
{
	int menu = -1;
	Book *firstBook = new Book();
	bool running = true;
	//Implement login and either three seperate menus or disable options depending on user level
	while (running)
	{
		std::cout << "Please select an option:\n1: insert a book\n2: remove a book\n3: load file \n4: save file\n5: print all books\n6: save all books\n0: exit program" << std::endl;
		std::cin >> menu;
		if (std::cin)
		{
			switch (menu)
			{
			case 0:
				running = false;
				break;
			case 1:
				ClearScreen();
				//insert book here
				break;
			case 2:
				ClearScreen();
				//remove book here
				break;
			case 3:
				ClearScreen();
				firstBook = loadFile();
				break;
			case 4:
				ClearScreen();
				saveABook(firstBook);//Just saves the first book for now
				break;
			case 5:
				ClearScreen();
				printAllBooks(firstBook);
				break; 
			case 6:
				ClearScreen();
				saveAllBooks(firstBook);
				break;
			}
		}
		else
			std::cout << "Please enter a number!" << std::endl;
	}
	return 0;
}

void insertBook(void)
{

}

void removeBook(void)
{

}



Book * loadFile(void) // loads the file and returns pointer to the first Book
{
	try
	{
		Book *previousBook;
		Book *firstBook;
		Book *thisBook = new Book();
		std::ifstream fileReader;
		std::cout << "Please enter file location." << std::endl;
		std::string temp;
		temp = "c:\\users\\desktop\\desktop\\foo.txt";
		//std::cin >> temp;
		fileReader.open(temp);
		if ( fileReader.is_open() )
		{
			getline(fileReader, temp);
			std::string nameParam = temp;
			getline(fileReader, temp);
			std::string authorParam = temp;
			getline(fileReader, temp);
			long ISBNParam = std::stol(temp);
			firstBook = new Book(nameParam, authorParam, ISBNParam);
			previousBook = firstBook;
			while ( getline(fileReader, temp) )
			{
				nameParam = temp;
				getline(fileReader, temp);
				authorParam = temp;
				getline(fileReader, temp);
				ISBNParam = std::stol(temp);
				thisBook = new Book(nameParam, authorParam, ISBNParam);
				thisBook->setFirstBook(firstBook);
				thisBook->setPreviousBook(previousBook);
				previousBook->setNextBook(thisBook);
				previousBook = thisBook;
			}
			fileReader.close();
			std::cout << "File loaded sucessfully!" << std::endl;
			return firstBook;
		}
		else
		{
			std::cout << "No file loaded!" << std::endl;
			return new Book();
		}
	}
	catch (_exception e)
	{
		std::cout << "Unable to open file, error: %s" << &e << std::endl;
		return new Book();
	}
	std::cout << "Failed to load!" << std::endl;
	return new Book();
}

void saveABook(Book *currentBook)
{
	try
	{
		std::ofstream fileSaver;
		std::cout << "Please enter file location." << std::endl;
		std::string temp;
		temp = "c:\\users\\desktop\\desktop\\foo.txt";
		//std::cin >> temp;
		fileSaver.open(temp);
		if (fileSaver.is_open())
		{
			fileSaver << "Name: " << currentBook->getName() << "\nAuthor: " << currentBook->getAuthor() << "\nISBN: " << currentBook->getISBN() << std::endl;
		}
		else
		{
			std::cout << "Failed to save!" << std::endl;
			return;
		}
		std::cout << "File saved sucessfully!" << std::endl;
		return;
	}
	catch (_exception e)
	{
		std::cout << "Unable to open file, error: %s" << &e << std::endl;
	}
	return;
}

void saveAllBooks(Book *firstBook)
{
	try
	{
		Book *currentBook = firstBook;
		std::ofstream fileSaver;
		std::cout << "Please enter file location." << std::endl;
		std::string temp;
		temp = "c:\\users\\desktop\\desktop\\foo.txt";
		//std::cin >> temp;
		fileSaver.open(temp);
		if (fileSaver.is_open())
		{
			do
			{
				fileSaver << "Name: " << currentBook->getName() << "\nAuthor: " << currentBook->getAuthor() << "\nISBN: " << currentBook->getISBN() << std::endl;
			} while (currentBook->getNextBook() != NULL);
			fileSaver << "Name: " << currentBook->getName() << "\nAuthor: " << currentBook->getAuthor() << "\nISBN: " << currentBook->getISBN() << std::endl;
		}
		else
		{
			std::cout << "Failed to save!" << std::endl;
			return;
		}
		std::cout << "File saved sucessfully!" << std::endl;
		return;
	}
	catch (_exception e)
	{
		std::cout << "Unable to open file, error: %s" << &e << std::endl;
	}
	return;
}

void printAllBooks(Book *firstBook)
{
	Book *currentBook = firstBook;
	do
	{
		std::cout << "Name: " << currentBook->getName() << "\nAuthor: " << currentBook->getAuthor() << "\nISBN: " << currentBook->getISBN() << std::endl << std::endl;
		currentBook = currentBook->getNextBook();
	} while (currentBook->getNextBook() != NULL);
	std::cout << "Name: " << currentBook->getName() << "\nAuthor: " << currentBook->getAuthor() << "\nISBN: " << currentBook->getISBN() << std::endl << std::endl;
	return;
}
