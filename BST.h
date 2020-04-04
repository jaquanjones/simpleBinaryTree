//
// Created by Jaquan Jones on 4/3/20.
//

#ifndef SIMPLEBT_BST_H
#define SIMPLEBT_BST_H

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class BTreeNode {
public:
    explicit BTreeNode(double x, BTreeNode *leftp = nullptr, BTreeNode *rightp = nullptr)
            : value(x), left(leftp), right(rightp) {}

private:
    double value;
    BTreeNode *right;
    BTreeNode *left;

    friend class BST;
};

class BST {
public:
    BST() { tree = nullptr; }

    ~BST();

    void insert(double x) { _insert(tree, x); }

    void inOrder(vector<double> &v) { inorder(v, tree); }

    int height() { return _height(tree); }

    int leafCounter() { return leafcounter(tree); }

    const BST &operator=(const BST &);

protected:
    BTreeNode *tree;

private:
    static void _insert(BTreeNode *&tree, double x);

    static void inorder(vector<double> &tlist, BTreeNode *t);

    static int leafcounter(BTreeNode *t);

    static int _height(BTreeNode *t);

    static void copyTree(BTreeNode *&copy, BTreeNode *other);

    static void clear(BTreeNode *&t);
};


#endif //SIMPLEBT_BST_H
