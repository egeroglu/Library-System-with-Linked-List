

#ifndef __BOOK_H
#define __BOOK_H
#include <iostream>
using namespace std;

class Book
{
public:
    Book();
    Book(int bId, string bName, int bYear);
    ~Book();
    void setBookId(int bId);
    int getBookId();

    void setBookName(string bName);
    string getBookName();

    void setBookYear(int bYear);
    int getBookYear();

    void setBookAvailability(bool ava);
    bool getBookAvailability();

private:
    int bookId;
    string bookName;
    int year;
    bool available;
};
#endif // __BOOK_H
