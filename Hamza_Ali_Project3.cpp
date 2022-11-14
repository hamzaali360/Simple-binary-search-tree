#include <iostream>
#include "BST.h"
using namespace std;

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