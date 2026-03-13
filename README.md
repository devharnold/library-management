# library-management

---

# Library Management System (C++ + SQLite)

A simple **Library Management System** written in C++ that demonstrates object-oriented programming and database integration using SQLite.

The project allows users to:

* Register library users
* Add books to the system
* Borrow books
* Return books
* View users and books stored in the database

All data is stored persistently in an SQLite database file (`library.db`).

---

# Features

* User registration
* Book registration
* Borrow and return books
* Persistent storage using SQLite
* Menu-driven CLI interface
* Simple relational database schema
* Demonstrates C++ database integration

---

# Technologies Used

* **C++17**
* **SQLite3**
* **Makefile build system**

SQLite was chosen because it is lightweight and embedded, making it ideal for proof-of-concept backend systems.

---

# Project Structure

```
LibrarySystem/
│
├── Database.h        # Database class interface
├── Database.cpp      # SQLite implementation
├── main.cpp          # CLI menu and program entry point
├── Makefile          # Build configuration
└── library.db        # SQLite database (generated automatically)
```

---

# Database Schema

The system uses two relational tables.

### Users Table

| Column | Type    | Description |
| ------ | ------- | ----------- |
| id     | INTEGER | Primary key |
| name   | TEXT    | User name   |

### Books Table

| Column      | Type    | Description                          |
| ----------- | ------- | ------------------------------------ |
| id          | INTEGER | Primary key                          |
| title       | TEXT    | Book title                           |
| author      | TEXT    | Book author                          |
| borrowed_by | INTEGER | ID of the user who borrowed the book |

A foreign key relationship connects books to users.

---

# Installation

Install SQLite development libraries if not already installed.

Linux:

```bash
sudo apt install sqlite3 libsqlite3-dev
```

---

# Build

Compile the project using Make:

```bash
make
```

---

# Run

```bash
make run
```

The program will automatically create the database file:

```
library.db
```

---

# Example Menu

```
Library System

1. Register User
2. Add Book
3. Show Users
4. Show Books
5. Borrow Book
6. Return Book
0. Exit
```

---

# Example Workflow

1. Register a user
2. Add a book
3. Borrow the book using the user ID
4. Display books to see who borrowed them
5. Return the book

---

# Learning Objectives

This project demonstrates:

* Object-Oriented Programming in C++
* Database integration with SQLite
* SQL queries from C++
* Simple relational schema design
* Persistent data storage
* CLI application structure

---

# Future Improvements

Possible extensions include:

* Prepared SQL statements for safer queries
* Borrow history tracking
* Search functionality
* REST API integration
* User authentication
* Web interface

---