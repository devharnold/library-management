#include "Library.h"
#include <iostream>

/*
    Adds a book to the library collection.
*/
void Library::addBook(const Book& book) {
    books.push_back(book);
}

/*
    Adds a new user to the system.
*/
void Library::addUser(const User& user) {
    users.push_back(user);
}


/*
    Finds a user by ID.

    Returns a pointer so we can modify the object directly.
*/
User* Library::findUser(int userId) {

    for (auto& user : users)
        if (user.getId() == userId)
            return &user;

    return nullptr;
}


/*
    Finds a book by ID.
*/
Book* Library::findBook(int bookId) {

    for (auto& book : books)
        if (book.getId() == bookId)
            return &book;

    return nullptr;
}


/*
    Displays all books and their status.
*/
void Library::displayBooks() const {

    for (const auto& book : books) {

        std::cout << "ID: " << book.getId()
                  << " | Title: " << book.getTitle()
                  << " | Author: " << book.getAuthor();

        if (book.borrowed())
            std::cout << " | Borrowed by User ID: " << book.getBorrowedBy();
        else
            std::cout << " | Available";

        std::cout << "\n";
    }
}


/*
    Displays all registered users.
*/
void Library::displayUsers() const {

    for (const auto& user : users) {

        std::cout << "User ID: " << user.getId()
                  << " | Name: " << user.getName()
                  << "\n";
    }
}


/*
    Borrow a book.

    Steps:
    1. Find book
    2. Find user
    3. Check availability
    4. Update both objects
*/
void Library::borrowBook(int bookId, int userId) {

    Book* book = findBook(bookId);
    User* user = findUser(userId);

    if (!book || !user) {
        std::cout << "Invalid book or user.\n";
        return;
    }

    if (book->borrowed()) {
        std::cout << "Book already borrowed.\n";
        return;
    }

    book->borrow(userId);
    user->borrowBook(bookId);

    std::cout << "Book borrowed successfully.\n";
}


/*
    Return a book.

    Steps:
    1. Find the book
    2. Find the user who borrowed it
    3. Update both records
*/
void Library::returnBook(int bookId) {

    Book* book = findBook(bookId);

    if (!book || !book->borrowed()) {
        std::cout << "Invalid return.\n";
        return;
    }

    User* user = findUser(book->getBorrowedBy());

    if (user)
        user->returnBook(bookId);

    book->giveBack();

    std::cout << "Book returned successfully.\n";
}