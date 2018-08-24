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

// forward definition
template<class T>
class Stack;

// friend function prototype 
template<class S> 
ostream &operator<<(ostream &, const Stack<S> &);

template<class T>
struct Node {
    T data;
    Node<T> *next;
    Node();
    Node(const T);
};

template<class T>
class Stack {
    template<class S> friend ostream &operator<<(ostream &os, Stack<S> &st);   
        
    public:
        void pop();
        void push(T);
        
        T top();
        Stack();
        Stack(T);
        ~Stack();
    private:
        Node<T> *head;
};


template<class S>
ostream &operator<<(ostream &os, Stack<S> &st)
{
    os << '[';
    Node<S> *i = st.head;
    for (; i->next != NULL; i = i->next)
        os << i->data << ',';
    
    os << i->data << ']';
    
    return os;
}

template<class T>
Node<T>::Node()
{
    next = NULL;
}

template<class T>
Node<T>::Node(const T data_)
{
    data = data_;
    next = NULL;
}

template<class T>
Stack<T>::Stack() {
    head = new Node<T> ();
}

template<class T>
Stack<T>::Stack(T d) {
    head = new Node<T> (d);
}

template<class T>
void Stack<T>::push(T entry)
{
    Node<T> *new_head = new Node<T>(entry);
    
    new_head->next = head;
    head = new_head;
}

template<class T>
void Stack<T>::pop()
{
    if (head == NULL) {
        cout << "WARNING:  Empty stack." << endl;
    }
    
    Node<T> *old_head = head;
    
    head = head->next;
    delete old_head;   
}

template<class T>
T Stack<T>::top()
{
    if (head != NULL)
        return *head;
    else {
        cout << "WARNING:  Empty stack." << endl;
    }       
}

template<class T>
Stack<T>::~Stack()
{
    Node<T> *n = head;
    
    while (n != NULL) {
        Node<T> *m = n->next;
        delete n;
        n = m;
    }
}

int main()
{
    Stack<int> *stack = new Stack<int>(0);
    
    stack->push(5);
    stack->push(6);
    stack->pop();
    stack->push(8);
    
    cout << *stack << endl; // should give [8,5,0]
  
    delete stack;
    return 0;
}