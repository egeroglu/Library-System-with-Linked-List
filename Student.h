
#ifndef __STUDENT_H
#define __STUDENT_H
#include <iostream>
#include "Book.h"
using namespace std;

class Student
{
public:
    Student();
    Student(string sName, int sId);
    ~Student();
    void setName(string sName);
    string getName();
    void setId(int sId);
    int getId();
    struct BNode
    {
        Book b;
        BNode* bNext;
    };
    BNode* findBook(int bookId);
    BNode *bHead;
    int bookCount;
private:
    string name;
    int id;
};
#endif // __STUDENT_H

