#include <iostream>
// #include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        char* num;
        Node* left;
        Node* right;
        Node() {
            // num = "";
            left = nullptr;
            right = nullptr;
            cout << "node is created" << endl;
        }
        Node(char x){
            num = &x;
            left = nullptr;
            right = nullptr;

        }
        Node* getLeft(){
            return left;
        }
    };

class BST {
    public:
    int size_;
    BST();
    BST(const BST& other);
    ~BST();
    void insert(char x);
    void inorder();
    
    Node* node;
    void deleteNode(Node& n);
};

BST::BST() {
    size_ = 0;
    cout << "BST is created" << endl;
}
BST::BST(const BST& other){
    // if(node->getLeft() != nullptr){
    node->left
    // }
    
}
BST::~BST(){

}


int main(){
    cout << "Welcome to the simple calculator!" << endl;

    cout << "enter a command: " << endl;

    string command;
    cin >> command;
    while(command != "q") {
        if(command == "e") {

        }
        else if(command == "s"){

        }
        else if(command == "b"){
            
        }
        else if(command == "c"){
            
        }
        else if(command == "l"){
            
        }
        else if(command == "a"){
            
        }
        else if(command == "u"){
            
        }
        else if(command == "i"){
            
        }
        else {
            cout << "This command does not exist" << endl;
        }
        cout << "Enter another command: ";
        cin >> command;
    }
    return 0;
}