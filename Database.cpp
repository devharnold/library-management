#include "Database.h"
#include <iostream>

/*
    Constructor

    Opens the SQLite database file.
    If it doesn't exist, SQLite automatically creates it.
*/
Database::Database(const std::string& filename) {

    if (sqlite3_open(filename.c_str(), &db)) {
        std::cerr << "Error opening database\n";
    }
}

/*
    Destructor

    Always close the database connection when finished.
*/
Database::~Database() {
    sqlite3_close(db);
}


/*
    Initialize database schema.
    Creates tables if they do not already exist.
*/
void Database::initialize() {

    const char* sql = R"(

        CREATE TABLE IF NOT EXISTS users(
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL
        );

        CREATE TABLE IF NOT EXISTS books(
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            title TEXT NOT NULL,
            author TEXT NOT NULL,
            borrowed_by INTEGER,
            FOREIGN KEY(borrowed_by) REFERENCES users(id)
        );

    )";

    char* err;

    if (sqlite3_exec(db, sql, nullptr, nullptr, &err) != SQLITE_OK) {

        std::cerr << "SQL error: " << err << "\n";
        sqlite3_free(err);
    }
}


/*
    Add a new user to the database.
*/
void Database::addUser(const std::string& name) {

    std::string sql =
        "INSERT INTO users(name) VALUES('" + name + "');";

    sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr);
}


/*
    Add a book to the database.
*/
void Database::addBook(const std::string& title, const std::string& author) {

    std::string sql =
        "INSERT INTO books(title,author) VALUES('"
        + title + "','" + author + "');";

    sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr);
}


/*
    Callback function: display query results.
*/
static int callback(void*, int argc, char** argv, char**) {

    for (int i = 0; i < argc; i++) {

        if (argv[i])
            std::cout << argv[i] << " ";
        else
            std::cout << "NULL ";
    }

    std::cout << "\n";

    return 0;
}


/*
    Display all users.
*/
void Database::listUsers() {

    const char* sql = "SELECT id,name FROM users;";

    sqlite3_exec(db, sql, callback, nullptr, nullptr);
}


/*
    Display books and show which user borrowed them.
*/
void Database::listBooks() {

    const char* sql = R"(

        SELECT books.id,
               books.title,
               books.author,
               COALESCE(users.name, 'Available')

        FROM books
        LEFT JOIN users
        ON books.borrowed_by = users.id;

    )";

    sqlite3_exec(db, sql, callback, nullptr, nullptr);
}


/*
    Borrow a book.
    Sets borrowed_by field to the user ID.
*/
void Database::borrowBook(int bookId, int userId) {

    std::string sql =
        "UPDATE books SET borrowed_by = "
        + std::to_string(userId)
        + " WHERE id = "
        + std::to_string(bookId)
        + " AND borrowed_by IS NULL;";

    sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr);
}


/*
    Return a borrowed book.
    Clears the borrowed_by field.
*/
void Database::returnBook(int bookId) {

    std::string sql =
        "UPDATE books SET borrowed_by = NULL WHERE id = "
        + std::to_string(bookId);

    sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr);
}