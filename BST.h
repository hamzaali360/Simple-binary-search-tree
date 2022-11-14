#include <iostream>
#include <string.h>
#include "String.h"
using namespace std;

// The main Binary Search Tree
class BST {
    
    private:
        // Every Tree Node added to the BST
        struct Node {
            
            String* value; // Contains char* and size
            Node* left;
            Node* right;
            // default constructor  
            Node(){
                value = new String();
                left = NULL;
                right = NULL;
            } 
            // parameter constructor
            Node(string s){        
                value = new String(s); 
                left = NULL;
                right = NULL;
            }
            // parameter constructor for copy constructor
            Node(String& s){
                value->operator=(s);
                left = NULL;
                right = NULL;
            }
            // destructor
            ~Node(){
                delete value;
                delete left;
                delete right;
            } 
            // assignment operator for = to deep copy the tree
            Node* operator=(String& s){
                Node* temp = new Node(s);
                left = NULL;
                right = NULL;
                return temp;

            }
                };
        
        void insert(Node* node, string s);
        void recurInorder(Node* node);
        void deleteBST(Node* node);
        char* getCharPointer(Node* node) const;
        bool isExist(Node* node, char* c);
        void recurUnion(Node* otherNode);
        void recurIntersection(BST& other, BST* newTree, Node* cur);
        void recurSubset(BST& other, Node* cur, int num, int size, bool& result);
        
    protected:
        Node* root_;
        Node* clone(Node* node) const;
        int size;
    public:
        BST();
        BST(const BST& other);
        BST& operator=(const BST& other);
        ~BST();
        void insert(string s) { insert(root_, s);}
        void inorder(){recurInorder(root_); cout<<endl;}
        void swapBST(BST& other);
        void deleteBST(){deleteBST(this->root_); this->root_ = NULL; this->size = 0;}
        void unionBST(BST& other);
        void intersection(BST& other);
        int getSize(){return size;}
        void subset(BST& other);
};
// returns a char* for the new node
char* BST::getCharPointer(Node* node) const{
    char* chars = new char[strlen(node->value->chars_) + 1];
    strcpy(chars, node->value->chars_);
    return chars;
}
// default constructor of the BST
BST::BST() {
    root_ = NULL;
    size = 0;
}
// copy constructor of the BST
BST::BST(const BST& other){
    this->root_ = clone(other.root_);
    this->size = other.size;

}
// assignment operator of = to copy the tree
BST& BST::operator=(const BST& other) {
    this->root_ = clone(other.root_);
    this->size = other.size;
    return *this;
}
// destructor
BST::~BST(){
    deleteBST();
    size = 0;
}
// helper function to remove every node in the tree safely
void BST::deleteBST(Node* node){
    if(node == NULL) {
        return;
    }
    Node* cur = node;
    Node* left = node->left;
    Node* right = node->right;
    node->left = NULL;
    node->right = NULL;
    delete(cur);
    deleteBST(left);
    deleteBST(right);
}
// helper function to deep copy every node to the new tree
BST::Node* BST::clone(Node* node) const {
if(node == NULL) {
    return NULL;
}
    Node* temp = new Node;
    temp->value->size_ = node->value->getSize();
    temp->value->chars_ = getCharPointer(node);
    temp->left = clone(node->left);
    temp->right = clone(node->right);
    return temp;
}
// check of the char* exist in the other tree
bool BST::isExist(Node* node, char* c) {
if(node == NULL){
    return false;
}
if (strcmp(node->value->getChars(), c) == 0) {
    return true;
}
else if ( strcmp(node->value->getChars(), c) > 0) {
    return isExist(node->left, c);
}
else {
    return isExist(node->right, c);
}
}

// swap the root node of the trees
void BST::swapBST(BST& other) {
    Node* temp = this->root_;
    this->root_ = other.root_;
    other.root_ = temp;
}
// recursion of the intersection to check any existing char* in both trees
// and insert it into the new tree
void BST::recurIntersection(BST& other, BST* newTree, Node* cur) {
if(cur == NULL) {
    return;
}
if(isExist(other.root_, cur->value->chars_)) {
    newTree->insert(cur->value->chars_);
}
    recurIntersection(other, newTree, cur->left);
    recurIntersection(other, newTree, cur->right);
}
// check for intersection between tree and add the new tree to the
// first tree
void BST::intersection(BST& other){
BST* temp = new BST();
recurIntersection(other, temp, this->root_);
this->deleteBST();
this->root_ == NULL;
this->root_ = temp->root_;
// temp->root_->value = NULL;
// temp->root_ = NULL;
// temp = NULL;
// delete temp;
// temp = NULL;

// temp->root_ = NULL;

}
// recursion for the union to add all the char* of both tree into one
void BST::recurUnion(Node* otherNode) {
    if(otherNode == NULL) {
        return;
    }
    else {
        if(!isExist(this->root_, otherNode->value->chars_)) {
            this->insert(otherNode->value->chars_);
        }
            recurUnion(otherNode->left);
            recurUnion(otherNode->right);   
    }
}
// calls the recursion to add all char* to the first tree
void BST::unionBST(BST& other){
recurUnion(other.root_);

}
// add the element to the BST tree
void BST::insert(Node* node, string s) {
    if(!node) { // if the root is null
        node = new Node(s);
        root_ = node;
        size++;
        return;
    }
    else{ // goes through left or right depending the comparison of the two char*
        Node* cur = root_;
        Node* prev = NULL;
        while(cur != NULL){
            prev = cur;
             if (strcmp(cur->value->getChars(), const_cast<char*>(s.c_str())) > 0) { // go left
                cur = cur->left;
            }
        else { // go right
            cur = cur->right;
        }
        }
    if (strcmp(prev->value->getChars(), const_cast<char*>(s.c_str())) > 0) { // add node to the left
        prev->left = new Node(s);
        size++;
    } 
    else { // add node to the right
        prev->right = new Node(s);
        size++;
    }
    
    }
}
// recursion of the inorder to print the char* in the alphabetical order
void BST::recurInorder(Node* node) {
    if(node == NULL){
        return;
    }
    recurInorder(node->left);
    node->value->printChars();
    cout <<  ", ";
    recurInorder(node->right);
}
// check if the second tree is the subset of the first tree
void BST::subset(BST& other) {
    bool result = true;
    if(this->size >= other.size) {
        cout << "This is a not proper subset" << endl;
    }
    else {
        recurSubset(other, this->root_, 0, this->size, result);
        if(result) {
            cout << "This is a proper subset" << endl;
        }
        else {
            cout << "This is not a proper subset" << endl;
        }
    }
}
// recursion to help determine if the tree is a subset to the other tree
void BST::recurSubset(BST& other, Node* cur, int num, int size, bool& result) {
        if(cur == NULL & num == size) {
            result = true;
            return;
        } 
        else if (cur == NULL) {
            return;
        }
        else {
            if(isExist(other.root_, cur->value->chars_)) {
                num++;
                recurSubset(other, cur->left,num, size, result);
                recurSubset(other, cur->right, num, size, result);
            }
            else {
                result = false;
                return;
            }
        }
        return;
    }