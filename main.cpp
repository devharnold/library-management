#include <iostream>
#include "Database.h"

/*
    Simple menu-driven interface for interacting with the system.
*/

int main() {

    // Open database file
    Database db("library.db");

    // Ensure tables exist
    db.initialize();

    int choice;

    do {

        std::cout << "\nLibrary System\n";
        std::cout << "1. Register User\n";
        std::cout << "2. Add Book\n";
        std::cout << "3. Show Users\n";
        std::cout << "4. Show Books\n";
        std::cout << "5. Borrow Book\n";
        std::cout << "6. Return Book\n";
        std::cout << "0. Exit\n";

        std::cout << "Choice: ";
        std::cin >> choice;

        std::string name, title, author;
        int bookId, userId;

        switch (choice) {

            case 1:

                std::cout << "Enter user name: ";
                std::cin >> name;

                db.addUser(name);
                break;


            case 2:

                std::cout << "Enter book title: ";
                std::cin >> title;

                std::cout << "Enter author: ";
                std::cin >> author;

                db.addBook(title, author);
                break;


            case 3:

                db.listUsers();
                break;


            case 4:

                db.listBooks();
                break;


            case 5:

                std::cout << "Book ID: ";
                std::cin >> bookId;

                std::cout << "User ID: ";
                std::cin >> userId;

                db.borrowBook(bookId, userId);
                break;


            case 6:

                std::cout << "Book ID: ";
                std::cin >> bookId;

                db.returnBook(bookId);
                break;
        }

    } while (choice != 0);

    return 0;
}