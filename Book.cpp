#include "Book.h"

/*
    Constructor using an initializer list.
*/
Book::Book(int id, std::string title, std::string author)
    : id(id),
      title(std::move(title)),      // std::move avoids unnecessary string copying
      author(std::move(author)),
      isBorrowed(false),            // book starts as available
      borrowedBy(-1) {}             // -1 indicates no user has borrowed it


// Getter functions
int Book::getId() const { return id; }

std::string Book::getTitle() const { return title; }

std::string Book::getAuthor() const { return author; }

bool Book::borrowed() const { return isBorrowed; }

int Book::getBorrowedBy() const { return borrowedBy; }


/*
    Borrow the book.
    Stores the ID of the user who borrowed it and
    updates the status.
*/
void Book::borrow(int userId) {
    isBorrowed = true;
    borrowedBy = userId;
}


/*
    Return the book.
    Resets status and clears borrower information.
*/
void Book::giveBack() {
    isBorrowed = false;
    borrowedBy = -1;
}