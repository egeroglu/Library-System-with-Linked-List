#ifndef __LIBRARYSYSTEM_H
#define __LIBRARYSYSTEM_H
#include "Student.h"
#include "Book.h"

#include <iostream>

using namespace std;

class LibrarySystem
{
public:
    LibrarySystem();
    ~LibrarySystem();

    void addBook(const int bookId, const string bookName, const int bookYear);
    void deleteBook(const int bookId);

    void addStudent( const int studentId, const string studentName );
    void deleteStudent( const int studentId );

    void checkoutBook(const int bookId, const int studentId);
    //void returnBook(const int bookId);

    void showAllBooks() const;
    void showBook(const int bookId) const;

    void showStudent(const int studentId) const;


private:
    struct Node
    {
        Student s;
        Node* next;
    };
    int studentCount;
    Node *head;
    Node* findStudent(const int studentId) const;

    struct NodeBook
    {
        Book book;
        NodeBook* nextBook;
    };
    int totalBookCount;
    NodeBook *headBook;
    NodeBook* findBookFromAll(const int bookId) const;

};
#endif //__LIBRARYSYSTEM_H

