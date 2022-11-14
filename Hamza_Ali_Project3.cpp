#include <iostream>
#include "BST.h"
using namespace std;

// class String{
//     public:
//     int size_;
//      char* chars_;
//     int getSize();
//      char* getChars();
//     void printChars();
//     String();
//     String(string s);
//     ~String();
//     void operator=(String& s);
// };
// void String::operator=(String& s){
//     size_ = s.size_;
//     chars_[size_ + 1];
//     for(int i = 0; i <= size_; i++) {
//         chars_[i] = s.chars_[i];
//     }
// }
// String::String(){
//     chars_ = NULL;
// }
// String::String(string s){
//     size_ = s.length();
//     cout << "size: " << size_ << endl;
//     chars_ = new char[size_ + 1];
//     for(int i = 0; i <= s.length(); i++) {
//         chars_[i] = s[i];
//     }
//     cout << "chars is add: " << chars_ << " size: " << size_ << endl;

// }
// String::~String() {
//     delete[] chars_;
//     size_ = 0;
// }

// int String::getSize(){
//     return size_;
// }
//  char* String::getChars(){
//     return chars_;
// }
// void String::printChars() {
//     for(int i = 0; i < size_; i++)
//     cout << chars_[i];
// }

// class BST {
    
//     private:
//         struct Node {
            
//             String* value;
//             Node* left;
//             Node* right;  
//             Node(){
//                 value = new String();
//                 left = NULL;
//                 right = NULL;
//             } 
//             Node(string s){        
//                 value = new String(s);
//                 left = NULL;
//                 right = NULL;
//             }
//             Node(String& s){
//                 value->operator=(s);
//                 left = NULL;
//                 right = NULL;
//             }
//             ~Node(){
//                 delete value;
//                 delete left;
//                 delete right;
//             } 
//             Node* operator=(String& s){
//                 Node* temp = new Node(s);
//                 left = NULL;
//                 right = NULL;
//                 return temp;

//             }
//                 };
        
//         void insert(Node* node, string s);
//         void recurInorder(Node* node);
//         void deleteBST(Node* node);
//         char* getCharPointer(Node* node) const;
//         bool isExist(Node* node, char* c);
//         void recurUnion(Node* otherNode);
//         void recurIntersection(BST& other, BST* newTree, Node* cur);
//         void recurSubset(BST& other, Node* cur, int num, int size, bool& result);
        
//     protected:
//         Node* root_;
//         Node* clone(Node* node) const;
//         int size;
//     public:
//         BST();
//         BST(const BST& other);
//         BST& operator=(const BST& other);
//         ~BST();
//         void insert(string s) { insert(root_, s);}
//         void inorder(){recurInorder(root_); cout<<endl;}
//         void swapBST(BST& other);
//         void deleteBST(){deleteBST(this->root_); this->root_ = NULL; this->size = 0;}
//         void unionBST(BST& other);
//         void intersection(BST& other);
//         int getSize(){return size;}
//         void subset(BST& other);
// };
// char* BST::getCharPointer(Node* node) const{
//     char* chars = new char[strlen(node->value->chars_) + 1];
//     strcpy(chars, node->value->chars_);
//     return chars;
// }
// BST::BST() {
//     root_ = NULL;
//     size = 0;
//     cout << "BST is created" << endl;
// }
// BST::BST(const BST& other){
//     cout << "i'm in copy" << endl;
//     this->root_ = clone(other.root_);
//     this->size = other.size;

// }
// BST& BST::operator=(const BST& other) {
//     this->root_ = clone(other.root_);
//     this->size = other.size;
//     return *this;
// }
// BST::~BST(){
//     cout << "delete bst" << endl;
//     deleteBST();
//     size = 0;
// }
// void BST::deleteBST(Node* node){
//     if(node == NULL) {
//         return;
//     }
//     cout << "in the delete" << endl;
//     Node* cur = node;
//     Node* left = node->left;
//     Node* right = node->right;
//     node->left = NULL;
//     node->right = NULL;
//     delete(cur);
//     deleteBST(left);
//     deleteBST(right);
// }
// BST::Node* BST::clone(Node* node) const {
// if(node == NULL) {
//     return NULL;
// }
//     Node* temp = new Node;
//     temp->value->size_ = node->value->getSize();
//     temp->value->chars_ = getCharPointer(node);
//     temp->left = clone(node->left);
//     temp->right = clone(node->right);
//     return temp;



// }

// bool BST::isExist(Node* node, char* c) {
// if(node == NULL){
//     return false;
// }
// if (strcmp(node->value->getChars(), c) == 0) {
//     return true;
// }
// else if ( strcmp(node->value->getChars(), c) > 0) {
//     return isExist(node->left, c);
// }
// else {
//     return isExist(node->right, c);
// }
// }

// void BST::swapBST(BST& other) {
//     Node* temp = this->root_;
//     this->root_ = other.root_;
//     other.root_ = temp;
// }

// void BST::recurIntersection(BST& other, BST* newTree, Node* cur) {
// if(cur == NULL) {
//     return;
// }
// if(isExist(other.root_, cur->value->chars_)) {
//     newTree->insert(cur->value->chars_);
// }
//     recurIntersection(other, newTree, cur->left);
//     recurIntersection(other, newTree, cur->right);
// }
// void BST::intersection(BST& other){
// BST* temp = new BST();
// recurIntersection(other, temp, this->root_);
// this->deleteBST();
// this->root_ == NULL;
// this->root_ = temp->root_;
// // temp->root_->value = NULL;
// // temp->root_ = NULL;
// // temp = NULL;
// // delete temp;
// // temp = NULL;

// // temp->root_ = NULL;

// }
// void BST::recurUnion(Node* otherNode) {
//     if(otherNode == NULL) {
//         return;
//     }
//     else {
//         if(!isExist(this->root_, otherNode->value->chars_)) {
//             this->insert(otherNode->value->chars_);
//         }
//             recurUnion(otherNode->left);
//             recurUnion(otherNode->right);   
//     }
// }
// void BST::unionBST(BST& other){
// recurUnion(other.root_);

// }

// void BST::insert(Node* node, string s) {
//     if(!node) {
//         node = new Node(s);
//         root_ = node;
//         cout << "add: " << s << "in 1" << endl;
//         size++;
//         return;
//     }
//     else{
//         Node* cur = root_;
//         Node* prev = NULL;
//         while(cur != NULL){
//             prev = cur;
//              if (strcmp(cur->value->getChars(), const_cast<char*>(s.c_str())) > 0) {
//                 cur = cur->left;
//             }
//         else {
//             cur = cur->right;
//         }
//         }
//     if (strcmp(prev->value->getChars(), const_cast<char*>(s.c_str())) > 0) {
//         prev->left = new Node(s);
//         size++;
//     } 
//     else {
//         prev->right = new Node(s);
//         size++;
//     }
    
//     }
// }
// void BST::recurInorder(Node* node) {
//     if(node == NULL){
//         return;
//     }
//     recurInorder(node->left);
//     node->value->printChars();
//     cout <<  ", ";
//     recurInorder(node->right);
// }

// void BST::subset(BST& other) {
//     bool result = true;
//     if(this->size >= other.size) {
//         cout << "This is a not proper subset" << endl;
//     }
//     else {
//         recurSubset(other, this->root_, 0, this->size, result);
//         if(result) {
//             cout << "This is a proper subset" << endl;
//         }
//         else {
//             cout << "This is not a proper subset" << endl;
//         }
//     }
// }
// void BST::recurSubset(BST& other, Node* cur, int num, int size, bool& result) {
//         if(cur == NULL & num == size) {
//             result = true;
//             return;
//         } 
//         else if (cur == NULL) {
//             return;
//         }
//         else {
//             if(isExist(other.root_, cur->value->chars_)) {
//                 num++;
//                 recurSubset(other, cur->left,num, size, result);
//                 recurSubset(other, cur->right, num, size, result);
//             }
//             else {
//                 result = false;
//                 return;
//             }
//         }
//         return;
//     }




int main(){
    BST S1;
    BST S2;

    cout << "Welcome to the simple calculator!" << endl;

    cout << "enter a command: " << endl;

    string command;
    cin >> command;
    while(command != "q") {
        if(command == "e") {
            S1.deleteBST();
        }
        else if(command == "s"){
            S1.swapBST(S2);
        }
        else if(command == "b"){
            S2.subset(S1);
        }
        else if(command == "c"){
            S2 = S1;
        }
        else if(command == "l"){
            cout << "S1: ";
            S1.inorder();
            cout << "S2: ";
            S2.inorder();
        }
        else if(command == "a"){
            string element;
            cin >> element;
            S1.insert(element);
            cout << "current size: " << S1.getSize() << endl;;
        }
        else if(command == "u"){
            S1.unionBST(S2);
        }
        else if(command == "i"){
            S1.intersection(S2);
        }
        else {
            cout << "This command does not exist" << endl;
        }
        cout << "Enter another command: ";
        cin >> command;
    }
    cout << "End Result:" << endl;
    cout << "S1: ";
    S1.inorder();
    cout << "S2: ";
    S2.inorder();
    return 0;
}