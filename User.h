#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

/*
    User represents a person who can borrow books.

    The class also keeps track of which books
    the user currently has.
*/

class User {
protected:
    int userId;                    // Unique ID for the user
    std::string name;              // User name

    // Stores IDs of borrowed books
    std::vector<int> borrowedBooks;

public:
    User(int id, std::string name);

    // Virtual destructor ensures proper cleanup
    // if this class is later inherited
    virtual ~User() = default;

    int getId() const;
    std::string getName() const;

    // Record that the user borrowed a book
    void borrowBook(int bookId);

    // Remove a book from the user's borrowed list
    void returnBook(int bookId);

    // Returns list of borrowed books
    const std::vector<int>& getBorrowedBooks() const;
};

#endif