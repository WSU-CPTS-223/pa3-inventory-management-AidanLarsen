#pragma once


#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Node
{
public:
    Node(T *newData) : data(newData), left(nullptr), right(nullptr) {};

    T* getData();

    void setLeft(Node<T>* newLeft);
    void setRight(Node<T>* newRight);

    Node<T>*& getLeft();
    Node<T>*& getRight();


private:
    T* data;
    Node<T>* left;
    Node<T>* right;
};


// getter and setter functions
template <typename T>
inline T *Node<T>::getData()
{
    return data;
}

template <typename T>
inline void Node<T>::setLeft(Node<T> *newLeft)
{
    this->left = newLeft;
}

template <typename T>
inline void Node<T>::setRight(Node<T> *newRight)
{
    this->right = newRight;

}

template <typename T>
inline Node<T> *&Node<T>::getLeft()
{
    
    return this->left;
}

template <typename T>
inline Node<T> *&Node<T>::getRight()
{
    
    return this->right;

}
