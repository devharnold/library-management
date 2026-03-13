#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"
#include "User.h"

/*
    Library acts as the system controller.

    Responsibilities:
    - Store books
    - Store users
    - Handle borrowing and returning logic
*/

class Library {

private:
    std::vector<Book> books;   // collection of books
    std::vector<User> users;   // collection of users

public:

    // Add new items to the system
    void addBook(const Book& book);
    void addUser(const User& user);

    // Display stored data
    void displayBooks() const;
    void displayUsers() const;

    // Borrowing operations
    void borrowBook(int bookId, int userId);
    void returnBook(int bookId);

    // Helper search functions
    User* findUser(int userId);
    Book* findBook(int bookId);
};

#endif