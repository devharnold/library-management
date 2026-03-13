#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>

/*
    Database class manages all interaction with SQLite.

    Responsibilities:
    - Open and close database connection
    - Create tables if they don't exist
    - Insert users and books
    - Borrow and return books
    - Display stored data
*/

class Database {

private:
    sqlite3* db;   // SQLite database connection pointer

public:

    // Constructor opens the database file
    Database(const std::string& filename);

    // Destructor ensures the connection is closed
    ~Database();

    // Create database tables if they don't exist
    void initialize();

    // User operations
    void addUser(const std::string& name);
    void listUsers();

    // Book operations
    void addBook(const std::string& title, const std::string& author);
    void listBooks();

    // Borrowing operations
    void borrowBook(int bookId, int userId);
    void returnBook(int bookId);
};

#endif