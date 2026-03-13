#pragma once
#include <string>
#include <iostream>


//  Transaction: Records a borrow / return event
class Transaction {
private:
    int         m_id;
    int         m_userId;
    int         m_bookId;
    std::string m_borrowDate;
    std::string m_dueDate;
    std::string m_returnDate;   // empty = not yet returned
    bool        m_returned;

public:
    Transaction()
        : m_id(0), m_userId(0), m_bookId(0), m_returned(false) {}

    Transaction(int id, int userId, int bookId,
                const std::string& borrowDate,
                const std::string& dueDate,
                const std::string& returnDate,
                bool returned)
        : m_id(id), m_userId(userId), m_bookId(bookId),
          m_borrowDate(borrowDate), m_dueDate(dueDate),
          m_returnDate(returnDate), m_returned(returned) {}

    // Getters
    int         getId()          const { return m_id; }
    int         getUserId()      const { return m_userId; }
    int         getBookId()      const { return m_bookId; }
    std::string getBorrowDate()  const { return m_borrowDate; }
    std::string getDueDate()     const { return m_dueDate; }
    std::string getReturnDate()  const { return m_returnDate; }
    bool        isReturned()     const { return m_returned; }

    // Setters
    void setReturnDate(const std::string& d) { m_returnDate = d; }
    void setReturned(bool r)                 { m_returned   = r; }

    // Display
    void display() const {
        std::cout << "  Txn ID     : " << m_id                           << "\n"
                  << "  User ID    : " << m_userId                       << "\n"
                  << "  Book ID    : " << m_bookId                       << "\n"
                  << "  Borrowed   : " << m_borrowDate                   << "\n"
                  << "  Due        : " << m_dueDate                      << "\n"
                  << "  Returned   : " << (m_returned ? m_returnDate
                                                      : "Not yet")      << "\n";
    }
};