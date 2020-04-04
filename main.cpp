#include <iostream>
#include "BST.h"

using namespace std;

int main() {
    BST root;
    int input;
    vector<double> vec;

    cout << "This program allows you to insert some numbers in binary search tree.\n";
    cout << "It prints out the numbers in the tree inorder.\n";
    cout << "It computes and prints the number of leaves in the tree.\nand the height of the tree.\n";
    cout << "Enter 10 numbers:" << endl;

    for (int i = 0; i < 10; i++) {
        cin >> input;
        root.insert(input);
    }

    cout << "\nThe items in the the tree in inorder are:\n";
    root.inOrder(vec);
    for (double i : vec)
        cout << i << "  ";

    cout << "\n\nThe height of the tree is " << root.height();
    cout << "\n\nThe number of leaves is " << root.leafCounter();


    return 0;
}
