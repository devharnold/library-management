#include "User.h"
#include <algorithm>   // required for std::remove

/*
    Constructor initializes user information.
*/
User::User(int id, std::string name)
    : userId(id), name(std::move(name)) {}

int User::getId() const { return userId; }

std::string User::getName() const { return name; }


/*
    Adds a book ID to the list of books borrowed by the user.
*/
void User::borrowBook(int bookId) {
    borrowedBooks.push_back(bookId);
}


/*
    Removes a book ID from the borrowed list.

    Uses the erase-remove idiom which is the
    standard way to remove elements from vectors.
*/
void User::returnBook(int bookId) {

    borrowedBooks.erase(
        std::remove(borrowedBooks.begin(), borrowedBooks.end(), bookId),
        borrowedBooks.end()
    );
}


/*
    Returns a read-only reference to the borrowed books list.
    This avoids copying the vector.
*/
const std::vector<int>& User::getBorrowedBooks() const {
    return borrowedBooks;
}