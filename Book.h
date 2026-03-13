#ifndef BOOK_H
#define BOOK_H

#include <string>

/*
    Book represents a single library book.

    Responsibilities:
    - Store book information
    - Track whether it is borrowed
    - Track which user borrowed it
*/

class Book {
private:
    int id;                 // Unique identifier for the book
    std::string title;      // Title of the book
    std::string author;     // Author name

    bool isBorrowed;        // True if the book is currently borrowed
    int borrowedBy;         // ID of the user who borrowed it (-1 if none)

public:

    // Constructor initializes all book information
    Book(int id, std::string title, std::string author);

    // Getters provide read-only access to private data
    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;

    // Returns borrowing status
    bool borrowed() const;

    // Returns the ID of the user who borrowed the book
    int getBorrowedBy() const;

    // Marks the book as borrowed by a specific user
    void borrow(int userId);

    // Marks the book as returned
    void giveBack();
};

#endif