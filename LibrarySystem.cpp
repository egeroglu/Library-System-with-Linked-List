
#include "LibrarySystem.h"
#include <iostream>

using namespace std;

LibrarySystem::LibrarySystem()
{
    head = NULL;
    studentCount = 0;
    headBook = NULL;
    totalBookCount =0;
}

LibrarySystem::~LibrarySystem()
{
    while(head != NULL)
    {
        deleteStudent(head->s.getId());
    }

}

LibrarySystem::Node* LibrarySystem::findStudent(const int studentId) const
{
    Node *active;
    int sId;
    if(studentCount <= 0)
    {
        return NULL;
        delete active;
    }
    else
    {
        active = head;
        while(active != NULL)
        {
            sId = active->s.getId();
            if(sId!=studentId)
            {
                active = active->next;
            }
            else
            {
                return active;
            }
        }
        return NULL;
    }
}
LibrarySystem::NodeBook* LibrarySystem::findBookFromAll(const int bookId) const
{
    NodeBook *activeBook;
    int bId;
    if(totalBookCount <= 0)
    {
        return NULL;
        delete activeBook;
    }
    else
    {
        activeBook = headBook;
        while(activeBook != NULL)
        {
            bId = activeBook->book.getBookId();
            if(bId!=bookId)
            {
                activeBook = activeBook->nextBook;
            }
            else
            {
                return activeBook;
            }
        }
        return NULL;
    }
}

void LibrarySystem::addBook( const int bookId, const string bookName, const int bookYear )
{
    if(bookId <= 0 )
    {
        cout << "a book id must be positive integer. " << endl;;
        return;
    }
    if(findBookFromAll(bookId)==NULL)
    {
        NodeBook *activeB = headBook;
        for(int i = 0; i<totalBookCount-1; i++)
        {
            activeB = activeB->nextBook;
        }
        NodeBook *newBook = new NodeBook;
        newBook->nextBook = NULL;
        newBook->book.setBookId(bookId);
        newBook->book.setBookName(bookName);
        newBook->book.setBookYear(bookYear);
        totalBookCount++;
        cout<<"Book "<<bookId<<" has been added"<<endl;
        if(headBook == NULL)
        {
            headBook = newBook;
        }
        else
        {
            activeB = headBook;
            while((*activeB).nextBook != NULL)
            {
                activeB = activeB->nextBook;
            }
            activeB->nextBook = newBook;
        }
    }
    else
    {
        cout<<"Book "<< bookId<<" already exists"<<endl;
    }
}
void LibrarySystem::addStudent(  const int studentId, const string studentName)
{
    if(studentId <= 0 )
    {
        cout << "a student id must be positive integer. " << endl;;
        return;
    }
    if(findStudent(studentId)==NULL)
    {
        Node *active = head;
        for(int i = 0; i<studentCount-1; i++)
        {
            active = active->next;
        }
        Node *newStudent = new Node;
        newStudent->next = NULL;
        newStudent->s.setName(studentName);
        newStudent->s.setId(studentId);
        studentCount++;
        cout<<"Student "<<studentId <<" has been added"<<endl;
        if(head == NULL)
        {
            head = newStudent;
        }
        else
        {
            active = head;
            while((*active).next != NULL)
            {
                active = active->next;
            }
            active->next = newStudent;
        }
    }
    else
    {
        cout<<"Student "<<studentId<<" already exists"<<endl;
    }
}


void LibrarySystem::deleteBook(const int bookId)
{
    if(!findBookFromAll(bookId))
    {
        return;
    }
    NodeBook* delBook = findBookFromAll(bookId);
    NodeBook *temp = headBook;
    NodeBook *active = headBook;
    if(delBook != NULL)
    {
        if(headBook == delBook)
        {
            headBook = headBook->nextBook;
        }
        else
        {
            while(active != delBook )
            {
                temp = active;
                active = active->nextBook;
            }
            temp->nextBook = delBook->nextBook;
        }
    }
    else
    {
        cout<<bookId<<" is not in the list"<<endl;
    }
    delBook->nextBook = NULL;
    delete delBook;
    delBook = NULL;
    cout<<"Book "<<bookId<<" has been deleted"<<endl;
    totalBookCount--;
}

void LibrarySystem::deleteStudent(const int studentId)
{
    if(!findStudent(studentId))
    {
        cout<<"Student "<<studentId<<" does not in the list"<<endl;
        return;
    }
    Node* delStudent = findStudent(studentId);
    Node *temp = head;
    Node *active = head;
    if(delStudent != NULL)
    {
        if(head == delStudent)
        {
            head = head->next;
        }
        else
        {
            while(active != delStudent )
            {
                temp = active;
                active = active->next;
            }
            temp->next = delStudent->next;
        }
    }
    else
    {
        cout<<studentId<<" is not in the list"<<endl;
    }
    delStudent->next = NULL;
    delete delStudent;
    delStudent = NULL;
    cout<<"Student "<<studentId<<" is deleted"<<endl;
    studentCount--;
}
void LibrarySystem::checkoutBook(const int bookId, const int studentId)
{
    Node* currStudent = findStudent(studentId);
    if(currStudent==NULL)
    {
        cout<<"Student "<<studentId<<" does not exists for checked out"<<endl;
        return;
    }

    NodeBook* currBook= findBookFromAll(bookId);
    if(currBook==NULL)
    {
        cout<<"Book "<<bookId<<" does not exists for checked out"<<endl;
        return;
    }
    if(currBook->book.getBookAvailability()==false)
    {
        cout<<"Book "<<bookId<<" has been already checked out by another student"<<endl;
        return;
    }
    if(currStudent->s.findBook(bookId)==NULL)
    {
        Student::BNode* booklist = currStudent->s.bHead;
        for(int i = 0; i<currStudent->s.bookCount-1; i++)
        {
            booklist = booklist->bNext;
        }
        Student::BNode* newBook = new Student::BNode;
        newBook->bNext = NULL;
        newBook->b.setBookId(bookId);
        newBook->b.setBookName(currBook->book.getBookName());
        newBook->b.setBookYear(currBook->book.getBookYear());
        currBook->book.setBookAvailability(false);
        currStudent->s.bookCount++;
        cout<<"Book "<<bookId<<" has been checked by student "<<studentId<<endl;
        if(currStudent->s.bHead== NULL)
        {
            currStudent->s.bHead = newBook;
        }
        else
        {
            booklist->bNext = newBook;
        }
    }
    else
    {
        cout<<"The book has been already checked out by "<<studentId<<endl;
    }
}

void LibrarySystem::showStudent(const int studentId)const
{
    Node *currStudent = findStudent(studentId);

    if(currStudent== NULL)
    {
        cout<<"There is no student with this id"<<endl;
        delete currStudent;
        return;
    }
    else
    {
        cout<<"Student id: "<<studentId
            <<" Student name: "<<currStudent->s.getName()<<endl;
    }
}

void LibrarySystem::showBook(const int bookId) const
{
    NodeBook* currBook= findBookFromAll(bookId);
    if(currBook==NULL)
    {
        cout<<"Book "<<bookId<<" does not exists"<<endl;
        return;
    }
    else
    {
        string available="Not checked out";
        if(currBook->book.getBookAvailability()==false){
            available ="Checked out by a student";
        }
        cout<<"Book "<<currBook->book.getBookId()<<"\t"<<currBook->book.getBookName()<<"\t"<<currBook->book.getBookYear()<<"\t"<<available<<endl;
    }
}


void LibrarySystem::showAllBooks()const
{
    if(headBook != NULL)
    {
        NodeBook *active = headBook;
        string status ="Not Checked out";
        cout<<"Book id\t\tBook name\tYear\tStatus"<<endl;
        while(active != NULL)
        {
            if(active->book.getBookAvailability()==true)
            {
                status = "Checked out by student";
            }
            cout<<active->book.getBookId()<<"\t"<<active->book.getBookName()
                <<"\t"<<active->book.getBookYear()<<"\t"<<status<<endl;
            active = active->nextBook;
        }
    }
    else
    {
        cout<<"The list is empty..."<<endl;
    }
}


