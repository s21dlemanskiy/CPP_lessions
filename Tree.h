#pragma once
struct Treenode {
    int data;
    Treenode* left;
    Treenode* right;
    Treenode* parent;
};


class Tree {
    Treenode* root;
public:
    Treenode* findNode(int);
    void swap(Treenode*, Treenode*);
    Tree() : root(nullptr) {};
    int add(int);
    void remove(int);
    void print();
};


