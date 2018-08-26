/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: farismismar
 *
 * Created on August 24, 2018, 12:57 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

template<class T>
struct Node {
    T data;
    Node<T> *left;
    Node<T> *right;
    Node(const T &);
};

template<class T>
Node<T>::Node(const T &d)
{
    left = right = NULL;
    data = d;
}

////////////////////////////////////////////////////////////////////////////////////

template<class T>
class Tree {
    public:
        Node<T> *root;
        void insert(T);
        void clear();
        bool empty() const;
        void recursive_preorder(void(*)(T &), Node<T> *);  
        void recursive_inorder(void(*)(T &), Node<T> *);
        void recursive_postorder(void(*)(T &), Node<T> *);  
        Tree(const T &);
        ~Tree();
    private:
        void postorder_clear(Node<T> *); 
        Node<T> *current_node;

};

template<class T>
Tree<T>::Tree(const T &d)
{
    current_node = root = new Node<T> (d);
}

template<class T>
Tree<T>::~Tree()
{
    clear();
}

template<class T>
bool Tree<T>::empty() const
{
    return (root == NULL);
}


template<class T>
void Tree<T>::insert(const T data)
{       
    if (current_node == NULL) {
        current_node = root = new Node<T>(data);
        return;
    }
    
    // insert to the left first
    if (current_node->left == NULL) {
        current_node->left = new Node<T>(data);
    }
    else if (current_node->right == NULL) {
        current_node->right = new Node<T>(data);
        current_node = current_node->left; // current node must be pointing back to the left node...
    }
    else {
        // create a new node and insert the left to it.
        T left_data = current_node->left->data;
        current_node->left = new Node<T> (left_data);
    }
}

template<class T>
void Tree<T>::recursive_inorder(void(*visit)(T &data), Node<T> *sub_root)
{
    if (sub_root != NULL) {
        recursive_inorder(visit, sub_root->left);
        (*visit)(sub_root->data);
        recursive_inorder(visit, sub_root->right);
    }
}

template<class T>
void Tree<T>::recursive_postorder(void(*visit)(T &data), Node<T> *sub_root)
{
    if (sub_root != NULL) {
        recursive_postorder(visit, sub_root->left);
        recursive_postorder(visit, sub_root->right);
        (*visit)(sub_root->data);
    }
}

template<class T>
void Tree<T>::recursive_preorder(void(*visit)(T &data), Node<T> *sub_root)
{
    if (sub_root != NULL) {
        (*visit)(sub_root->data);
        recursive_preorder(visit, sub_root->left);
        recursive_preorder(visit, sub_root->right);
        
    }
}

template<class T>
void Tree<T>::postorder_clear(Node<T> *sub_root)
{
    if (sub_root != NULL) {
        postorder_clear(sub_root->left);
        postorder_clear(sub_root->right);
        cout << "Deleting node: " << sub_root->data << endl;
        delete sub_root;
    }
    
    root = current_node = NULL;
}


template<class T>
void print(T &data)
{
    cout << data << ',';
} 
 
template<class T>
void Tree<T>::clear()
{
    postorder_clear(root);
}


int main()
{
    Tree<int> *tree = new Tree<int>(5);
    
    tree->insert(6);
    tree->insert(7);  // this should now build a tree with root 5 and left 6 and right 7
    tree->insert(1);
    tree->insert(2);
    
    
    tree->recursive_preorder(print, tree->root);
    cout << endl;
    tree->recursive_inorder(print, tree->root);
    cout << endl;
    tree->recursive_postorder(print, tree->root);
    cout << endl;
        
    delete tree;
    
    return 0;
}