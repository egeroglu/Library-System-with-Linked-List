


#include "Book.h"
#include <iostream>
using namespace std;
Book::Book(){
    available = true;
}
Book::Book(int bId, string bName,int bYear){
    setBookId(bId);
    setBookName(bName);
    setBookYear(bYear);

}
Book::~Book(){

}
void Book::setBookId(int bId){
    bookId = bId;
}
int Book::getBookId(){
    return bookId;
}

void Book::setBookName(string bName){
    bookName = bName;
}
string Book::getBookName(){
    return bookName;
}

void Book::setBookYear(int bYear){
    year = bYear;
}
int Book::getBookYear(){
    return year;
}

void Book::setBookAvailability(bool ava){
    available = ava;
}
bool Book::getBookAvailability(){
    return available;
}
