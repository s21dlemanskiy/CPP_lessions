#include "Tree.h"
#include <iostream>
using namespace std;


Treenode* requrtion_findNode(int node, Treenode* cur) {
    if (cur == nullptr) {
        return nullptr;
    }
    if (cur->data == node) {
        return cur;
    }
    Treenode* left = requrtion_findNode(node, cur->left);
    if (left) {
        return left;
    }
    Treenode* right = requrtion_findNode(node, cur->right);
    return right;

}

void Tree::swap(Treenode* first, Treenode* second) {
    int tmp = first->data;
    first->data = second->data;
    second->data = tmp;
}

void Tree::remove(int node) {
    Treenode* to_delite = findNode(node);
    while (to_delite->left or to_delite->right) {
        if (to_delite->left) {
            Tree::swap(to_delite, to_delite->left);
            to_delite = to_delite->left;
        }else if (to_delite->right) {
            Tree::swap(to_delite, to_delite->right);
            to_delite = to_delite->right;
        }
    }
    if (to_delite->parent) {
        if (to_delite->parent->left == to_delite) {
            to_delite->parent->left = nullptr;
        }
        else {
            to_delite->parent->right = nullptr;
        }
    }
    else {
        this->root = nullptr;
    }
    delete to_delite;
}

int Tree::add(int number) {
    Treenode* node = new Treenode();
    Treenode* cur = this->root;
    node->data = number;
    node->left = node->right = nullptr;
    if (this->root == nullptr) {
        this->root = node;
        node->parent = nullptr;
        return 1;
    }
    while (true) {
        if (cur->data < number) {
            if (cur->left) {
                cur = cur->left;
            }
            else {
                cur->left = node;
                node->parent = cur;
                return 1;
            }
        }
        else {
            if (cur->right) {
                cur = cur->right;
            }
            else {
                cur->right = node;
                node->parent = cur;
                return 1;
            }
        }
    }
    return -1;
}

void print_Tree(Treenode* cur, int level) {
    if (cur)
    {
        print_Tree(cur->left, level + 1);
        for (int i = 0; i < level; i++) cout << "   ";
        cout << cur->data << endl;
        print_Tree(cur->right, level + 1);
    }
}



void Tree::print() {
    print_Tree(this->root, 0);
}

Treenode* Tree::findNode(int node) {
    
    return requrtion_findNode(node, this->root);
}