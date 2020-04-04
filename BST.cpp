//
// Created by Jaquan Jones on 4/3/20.
//

#include "BST.h"

void BST::_insert(BTreeNode *&tree, double x) {
    if (!tree) {
        tree = new BTreeNode(x);
    } else {
        x < tree->value ? _insert(tree->left, x) : _insert(tree->right, x);
    }
}

void BST::inorder(vector<double> &v, BTreeNode *t) {
    if (!t) {
        return;
    }
    inorder(v, t->left);
    v.push_back(t->value);
    inorder(v, t->right);

}

int BST::leafcounter(BTreeNode *t) {
    if (!t) {
        return 0;
    } else if (!(t->left) && !(t->right)) {
        return 1;
    } else {
        return leafcounter(t->left) + leafcounter(t->right);
    }
}

int BST::_height(BTreeNode *t) {
    if (!t) {
        return 0;
    } else {
        int lHeight = _height(t->left);
        int rHeight = _height(t->right);

        return ((lHeight > rHeight ? lHeight : rHeight) + 1);
    }
}

void BST::copyTree(BTreeNode *&copy, BTreeNode *other) {
    if (!other) {
        copy = nullptr;
    } else {
        copy = new BTreeNode(other->value);
        copyTree(copy->left, other->left);
        copyTree(copy->right, other->right);
    }
}


const BST &BST::operator=(const BST &other) {
    if (this != &other) {
        clear(tree);
    }
    if (!other.tree) {
        tree = nullptr;
    } else {
        copyTree(tree, other.tree);
    }
    return *this;
}

void BST::clear(BTreeNode *&t) {
    if (!t) {
        clear(t->left);
        clear(t->right);
        delete t;
        t = nullptr;
    }
}

BST::~BST() {
    clear(tree);
}
