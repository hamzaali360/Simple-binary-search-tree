#include <iostream>
#include <string.h>
using namespace std;

// The String class
class String{
    public:
    int size_;
    char* chars_;
    int getSize();
     char* getChars();
    void printChars();
    String();
    String(string s);
    ~String();
    void operator=(String& s);
};
// assignment operator = for setting the char* from one node to the other node
void String::operator=(String& s){
    size_ = s.size_;
    chars_[size_ + 1];
    for(int i = 0; i <= size_; i++) {
        chars_[i] = s.chars_[i];
    }
}
// default constructor
String::String(){
    chars_ = NULL;
}
// parameter constructor
String::String(string s){
    size_ = s.length();
    chars_ = new char[size_ + 1];
    for(int i = 0; i <= s.length(); i++) {
        chars_[i] = s[i];
    }

}
// destructor
String::~String() {
    delete[] chars_;
    size_ = 0;
}
// return the size of the char*
int String::getSize(){
    return size_;
}
// return the char*
 char* String::getChars(){
    return chars_;
}
// prints the char*
void String::printChars() {
    for(int i = 0; i < size_; i++)
    cout << chars_[i];
}