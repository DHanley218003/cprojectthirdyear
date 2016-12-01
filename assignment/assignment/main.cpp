#include <iostream>
#include "Book.h"
#include <fstream>
#include "ClearScreen.h"

Book* loadFile(void);
void  printAllBooks(Book *firstBook);
void  saveAllBooks(Book *currentBook);
void  saveABook(Book *currentBook);
Book* searchForBook(Book *firstBook);
void  insertBook(Book *firstBook);
Book* createBook(void);
void  removeBook(Book *firstBook);
void  changeUser();
bool  passwordMatch(std::string password, int line);
void  guestMenu();
void  adminMenu();
void  userMenu();
bool  checkUser(std::string userName);
void  removeUser();
void  addUser();

int main(void)
{
	changeUser();
	return 0;
}

void  removeUser()
{
	std::cout << "Please enter the user to remove:" << std::endl;
	std::string user;
	std::cin >> user;
	int line = 1;
	std::fstream fileReader;
	fileReader.open("users");
	std::string temp;
	if (fileReader.is_open())
	{
		while (getline(fileReader, temp))
		{
			if (!temp.compare(user))
			{
				fileReader.put(*"");
				break;
			}
			line++;
		}
		
		std::fstream fileReader;
		fileReader.open("passwords");
		std::string temp;
		if (fileReader.is_open())
		{
			for(int i = 0; i <= line; i++)
			{
				if (i == line)
				{
					fileReader.put(*"");
					break;
				}
				getline(fileReader, temp);
			}
			fileReader.close();
		}
		else
		{
			std::cout << "Cannot find password file! Please contact system administrator!" << std::endl;
		}
	}
	else
	{
		std::cout << "Cannot find user file! Please contact system administrator!" << std::endl;
	}
}
void  addUser()
{
	std::cout << "Please enter the user to add:" << std::endl;
	std::string input;
	std::cin >> input;
	std::fstream fileWriter;
	fileWriter.open("users", std::ios::app);
	if (fileWriter.is_open())
	{
		fileWriter << input << std::endl;
		fileWriter.close();
		fileWriter.open("passwords", std::ios::app);
		if (fileWriter.is_open())
		{
			std::cout << "Please enter the password for the user:" << std::endl;
			std::cin >> input;
			fileWriter << input << std::endl;
			fileWriter.close();
		}
		else
		{
			std::cout << "Cannot find password file! Please contact system administrator!" << std::endl;
		}
	}
	else
	{
		std::cout << "Cannot find user file! Please contact system administrator!" << std::endl;
	}
}

void guestMenu()
{
	Book *firstBook = new Book();
	Book *temp;
	bool running = true;
	unsigned int menu;
	while (running)
	{
		std::cout << "Please select an option:\n1: Load file \n2: Print all books\n3: Search for a book\n4: Check availabilit of a book\n5: Change user/login\n0: Exit program" << std::endl;
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
				firstBook = loadFile();
				break;
			case 2:
				ClearScreen();
				printAllBooks(firstBook);
				break;
			case 3:
				ClearScreen();
				temp = searchForBook(firstBook);
				std::cout << "Name: " << temp->getName() << "\nAuthor: " << temp->getAuthor() << "\nISBN: " << temp->getISBN() << "\nIs available: " << temp->isBookAvailable() << std::endl;
				delete temp;
				break;
			case 4:
				ClearScreen();
				temp = searchForBook(firstBook);
				if (temp->isBookAvailable())
					std::cout << "Book is available" << std::endl;
				else
					std::cout << "Book is not available" << std::endl;
				break;
			case 5:
				ClearScreen();
				changeUser();
				break;
			}
		}
		else
			std::cout << "Please enter a number!" << std::endl;
	}
}

void adminMenu()
{
	Book *firstBook = new Book();
	Book *temp;
	bool running = true;
	unsigned int menu;
	while (running)
	{
		std::cout << "Please select an option:\n1: Insert a book\n2: Remove a book\n3: Load file \n4: Save a book\n5: Print all books\n6: Save all books\n7: Search for a book\n8: Checkout/return a book\n9: Change user/login\n10: Add user\n11: Remove user\n0: Exit program" << std::endl;
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
				insertBook(firstBook);
				break;
			case 2:
				ClearScreen();
				removeBook(firstBook);
				break;
			case 3:
				ClearScreen();
				firstBook = loadFile();
				break;
			case 4:
				ClearScreen();
				saveABook(firstBook);
				break;
			case 5:
				ClearScreen();
				printAllBooks(firstBook);
				break;
			case 6:
				ClearScreen();
				saveAllBooks(firstBook);
				break;
			case 7:
				ClearScreen();
				temp = searchForBook(firstBook);
				std::cout << "Name: " << temp->getName() << "\nAuthor: " << temp->getAuthor() << "\nISBN: " << temp->getISBN() << "\nIs available: " << temp->isBookAvailable() << std::endl;
				delete temp;
				break;
			case 8:
				ClearScreen();
				temp = searchForBook(firstBook);
				if (temp->isBookAvailable())
					std::cout << "Book is available" << std::endl;
				else
					std::cout << "Book is not available" << std::endl;
				break;
			case 9:
				ClearScreen();
				changeUser();
				break;
			case 10:
				ClearScreen();
				addUser();
				break;
			case 11:
				ClearScreen();
				removeUser();
				break;
			}
		}
		else
			std::cout << "Please enter a number!" << std::endl;
	}
}

void userMenu()
{
	Book *firstBook = new Book();
	Book *temp;
	bool running = true;
	unsigned int menu;
	while (running)
	{
		std::cout << "Please select an option:\n1: Load file \n2: Save a book\n3: Print all books\n4: Save all books\n5: Search for a book\n6: Checkout/return a book\n7: Change user/login\n0: Exit program" << std::endl;
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
				firstBook = loadFile();
				break;
			case 2:
				ClearScreen();
				saveABook(firstBook);
				break;
			case 3:
				ClearScreen();
				printAllBooks(firstBook);
				break;
			case 4:
				ClearScreen();
				saveAllBooks(firstBook);
				break;
			case 5:
				ClearScreen();
				temp = searchForBook(firstBook);
				std::cout << "Name: " << temp->getName() << "\nAuthor: " << temp->getAuthor() << "\nISBN: " << temp->getISBN() << "\nIs available: " << temp->isBookAvailable() << std::endl;
				delete temp;
				break;
			case 6:
				ClearScreen();
				temp = searchForBook(firstBook);
				if (temp->isBookAvailable())
					std::cout << "Book is available" << std::endl;
				else
					std::cout << "Book is not available" << std::endl;
				break;
			case 7:
				ClearScreen();
				changeUser();
				break;
			}
		}
		else
			std::cout << "Please enter a number!" << std::endl;
	}
}

bool checkUser(std::string userName)
{
	int line = 1;
	std::ifstream fileReader;
	fileReader.open("users");
	std::string temp;
	if (fileReader.is_open())
	{
		bool match = false;
		while (getline(fileReader, temp))
		{
			if (!temp.compare(userName))
			{
				match = true;
				break;
			}
			line++;
		}
		fileReader.close();

		std::cout << "Please enter your password:" << std::endl;
		std::string password;
		std::cin >> password;
		if (passwordMatch(password, line))
		{
			if(match)
				return true;
			else
			{
				std::cout << "Invalid user name or password, enter 1 to retry or 0 to exit" << std::endl;
				unsigned int input;
				std::cin >> input;
				if (input == 0)
					return false;
			}
		}
		else
		{
			std::cout << "Invalid user name or password, enter 1 to retry or 0 to exit" << std::endl;
			unsigned int input;
			std::cin >> input;
			if (input == 0)
				return false;
		}
	}
	else
	{
		std::cout << "Cannot find user file! Please contact system administrator!" << std::endl;
		return false;
	}
}

void changeUser()
{
	//Implement login and either three seperate menus or disable options depending on user level
	bool invusrpwd = true;
	unsigned int loop;
	while (invusrpwd)
	{
		std::cout << "Please enter your username to login, or enter guest for limited functionality" << std::endl;
		std::string input;
		std::cin >> input;
		if (!input.compare("guest"))
		{
			guestMenu();
		}
		else if (!input.compare("admin"))
		{
			std::cout << "Please enter your password" << std::endl;
			std::cin >> input;
			if (passwordMatch(input, 0))
				adminMenu();
			else
			{
				std::cout << "Invalid user name or password, enter 1 to retry or 0 to exit" << std::endl;
				std::cin >> loop;
				if (loop == 0)
					invusrpwd = false;
			}
		}
		else
		{
			if (checkUser(input)) //calls function that checks username and password to file
				userMenu();
			else
			{
				std::cout << "Invalid user name or password, enter 1 to retry or 0 to exit" << std::endl;
				std::cin >> loop;
				if (loop == 0)
					invusrpwd = false;
			}
		}
	}
}

bool passwordMatch(std::string password, int line)
{
	int count = 0;
	std::ifstream fileReader;
	fileReader.open("passwords");
	std::string temp;
	if (fileReader.is_open())
	{
		bool match = false;
		while (getline(fileReader, temp))
		{
			if (!password.compare(temp) || count == line)
			{
				match = true;
				break;
			}
			count++;
		}
		fileReader.close();
		return match;
	}
	else
	{
		std::cout << "Cannot find password file! Please contact system administrator!" << std::endl;
		return false;
	}
}

void insertBook(Book *firstBook)
{	
	bool loop = true;
	Book *temp = firstBook;
	int menu;
	while (loop)
	{
		std::cout << "Please select an option:\n1: Insert a book at the end\n2: Insert a book at the start\n3: Search for a book and add before it\n4: Search for a book and add after it\n0: Go back to main menu" << std::endl;
		std::cin >> menu;
		if (std::cin)
		{
			loop = false;
			switch (menu)
			{
			case 0:
				std::cout << "No action performed (insertBook)" << std::endl;
				break;
			case 1:
				ClearScreen();
				while (temp->getNextBook() != NULL)
				{
					temp = temp->getNextBook();
				}
				temp->insertAfter(createBook());
				std::cout << "Book inserted at the emd!" << std::endl;
				break;
			case 2:
				ClearScreen();
				firstBook->insertBefore(createBook());
				std::cout << "Book inserted at the start!" << std::endl;
				break;
			case 3:
				ClearScreen();
				searchForBook(firstBook)->insertBefore(createBook());
				std::cout << "Book inserted before searched book!" << std::endl;
				break;
			case 4:
				ClearScreen();
				searchForBook(firstBook)->insertAfter(createBook());
				std::cout << "Book inserted after searched book!" << std::endl;
				break;
			}
		}
		else
			std::cout << "Please enter a number!" << std::endl;
	}
}

Book* createBook(void)
{
	std::string title;
	std::string author;
	unsigned int ISBN;
	std::cout << "Please enter book title" << std::endl;
	std::cin >> title;
	std::cout << "Please enter book author" << std::endl;
	std::cin >> author;
	std::cout << "Please enter book ISBN" << std::endl;
	std::cin >> ISBN;
	return new Book(title, author, ISBN);
}

void removeBook(Book *firstBook)
{
	Book *temp = firstBook;
	std::cout << "Please search for a book to remove" << std::endl;
	temp = searchForBook(firstBook);
	temp->getNextBook()->setPreviousBook(temp->getPreviousBook());
	temp->getPreviousBook()->setNextBook(temp->getNextBook());
	delete temp;
	std::cout << "Removed searched book!" << std::endl;
}

Book* searchForBook(Book *firstBook)
{
	bool loop = true;
	Book *temp = firstBook;
	std::string title;
	int menu;
	while(loop)
	{
		std::cout << "Please select an option:\n1: Search for book title\n2: Search for book Author\n3: Search for book ISBN\n0: Go back to main menu" << std::endl;
		std::cin >> menu;
		if (std::cin)
		{
			loop = false;
			switch (menu)
			{
			case 0:
				std::cout << "No action performed (searchForBook)" << std::endl;
				break;
			case 1:
				ClearScreen();
				std::cout << "Please enter the books title" << std::endl;
				std::cin >> title;
				do 
				{
					if (title.compare(temp->getName()))
						return temp;
				} while (temp->getNextBook() != NULL);
				break;
			case 2:
				ClearScreen();
				std::cout << "Please enter the books author" << std::endl;
				std::cin >> title;
				do
				{
					if (title.compare(temp->getAuthor()))
						return temp;
				} while (temp->getNextBook() != NULL);
				break;
			case 3:
				ClearScreen();
				std::cout << "Please enter the books ISBN" << std::endl;
				std::cin >> menu;
				do
				{
					if (menu == temp->getISBN())
						return temp;
				} while (temp->getNextBook() != NULL);
				break;
			}
		}
		else
			std::cout << "Please enter a number!" << std::endl;
	}
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
		std::cin >> temp;
		fileReader.open(temp);
		if ( fileReader.is_open() )
		{
			getline(fileReader, temp);
			std::string nameParam = temp;
			getline(fileReader, temp);
			std::string authorParam = temp;
			getline(fileReader, temp);
			long ISBNParam = std::stoi(temp);
			firstBook = new Book(nameParam, authorParam, ISBNParam);
			previousBook = firstBook;
			while ( getline(fileReader, temp) )
			{
				nameParam = temp;
				getline(fileReader, temp);
				authorParam = temp;
				getline(fileReader, temp);
				ISBNParam = std::stoi(temp);
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
		std::cin >> temp;
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
		std::cin >> temp;
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
