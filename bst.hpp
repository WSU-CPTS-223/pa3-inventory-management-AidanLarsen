#pragma once

#include "node.hpp"
#include "data.hpp"

template<typename T>
class BST
{
public:
    BST() : root(nullptr) {};

    Node<T>*& getRoot();
    void insert(T& newData, Node<T>*& tree);
    
    Node<T>* search(const string target, Node<T>*& curNode);

    void printIfContains(Node<T>* node, const string& target);


private:
    Node<T>* root;
    
};

// returns the root of the bst
template <typename T>
Node<T>*& BST<T>::getRoot()
{
    return root;
}



//Basic seach function for a bst
template <typename T>
Node<T> *BST<T>::search(const string target, Node<T> *&curNode)
{
    
    if(curNode == nullptr)
    {
        return nullptr;
    }
    if(curNode->getData()->getId() == target)
    {
        return curNode;
    }
    else if(curNode->getData()->getId() > target)
    {
        return search(target, curNode->getLeft());
    }
    else{
        return search(target, curNode->getRight());
    }
}

//prints if the category target is within the category string of the node.
template <typename T>
void BST<T>::printIfContains(Node<T> *node, const string &target)
{
    if(node == nullptr)
    {
        return;
    }

    printIfContains(node->getLeft(), target);

    if(node->getData()->getCategories().find(target) != string::npos)
    {
        node->getData()->print();
    }

    printIfContains(node->getRight(), target);
}


// insert function based on the unique id
template <typename T>
void BST<T>::insert(T&newData, Node<T> *&cur)
{
    if(root == nullptr)
    {
        root = cur;
    }
    if(cur == nullptr)
    {
        cur = new Node<T>(new T(newData));
    }
    else if(newData.getId() < cur->getData()->getId())
    {
        insert(newData, cur->getLeft());
    }
    else if(newData.getId() > cur->getData()->getId())
    {
        insert(newData, cur->getRight());
    }

}



