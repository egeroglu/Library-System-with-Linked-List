#include "Student.h"
#include <iostream>
using namespace std;
Student::Student(){
    bHead = NULL;
    bookCount =0;
}
Student::Student(string sName,int sId){
    setName(sName);
    setId(sId);
}
Student::~Student(){

}

void Student::setName(string sName){
    name = sName;
}
string Student::getName(){
    return name;
}

void Student::setId(int sId){
    id = sId;
}
int Student::getId(){
    return id;
}

Student::BNode* Student::findBook(int bId)
{
    BNode *active;
    int bookId;
    if( bookCount <= 0)
    {
        return NULL;
        delete active;
    }
    else
    {
        active = bHead;
        while(active != NULL)
        {
            bookId = active->b.getBookId();
            if(bookId==bId)
            {
                active = active->bNext;
            }
            else
            {
                return active;
            }
        }
        return NULL;
    }
    return NULL;
}

