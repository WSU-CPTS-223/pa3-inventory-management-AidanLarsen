#include "node.hpp"
#include "data.hpp"
#include "bst.hpp"


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void printHelp()
{
    cout << "Supported list of commands: " << endl;
    cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << endl;
    cout << " 2. listInventory <category_string> - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'.\n"
         << endl;
    cout << " Use :quit to quit the REPL" << endl;
}

bool validCommand(string line)
{
    return (line == ":help") ||
           (line.rfind("find", 0) == 0) ||
           (line.rfind("listInventory") == 0);
}

void evalCommand(string line, BST<Data>& bst)
{
    if (line == ":help")
    {
        printHelp();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0)
    {
        // Look up the appropriate datastructure to find if the inventory exist
        string target;
        
        cout << "Please enter the exact id number of the product youd like to look up: " << endl;
        cin >> target;
        Node<Data>* found = bst.search(target, bst.getRoot());
        if(found != nullptr)
        {
            found->getData()->print();
        }
        else
        {
            cout << "There is no product with that id :-(" << endl;
        }
        
    }
    // if line starts with listInventory
    else if (line.rfind("listInventory") == 0)
    {
        // Look up the appropriate datastructure to find all inventory belonging to a specific category
        string target;
        cout << "Please enter the category in which youd like to see all products that contain that category: " << endl;
        cin >> target;
        bst.printIfContains(bst.getRoot(), target);
    }
}



void bootStrap()
{
    cout << "\n Welcome to Amazon Inventory Query System" << endl;
    cout << " enter :quit to exit. or :help to list supported commands." << endl;
    cout << "\n> ";
    // TODO: Do all your bootstrap operations here
    // example: reading from CSV and initializing the data structures
    // Don't dump all code into this single function
    // use proper programming practices
}

void importList(BST <Data>& bst)
{
    fstream input;
    string line, trash;

    string id, product, brandName, prodAsin, prodCat;

    input.open("amazon_inventory.csv", fstream::in);

    getline(input, trash);

    while(getline(input, line))
    {
        stringstream str(line);
        string temp;

        getline(str, temp, ',');
        id = temp;

        char first = str.peek();
        if(first == '"')
        {
            str.get();
            getline(str, temp, '"');
            product = temp;

            if(str.peek() == ',')
            {
                str.get();
            }
        }
        else
        {
            getline(str, temp, ',');
            product = temp;
        }

        if(str.peek() == ',')
        {
            str.get();
            brandName = "N/A";
        }
        else{
            getline(str, temp, ',');
            brandName = temp;
        }

        if(str.peek() == ',')
        {
            str.get();
            prodAsin = "N/A";
        }
        else{
            getline(str, temp, ',');
            prodAsin = temp;
        }
        

        if(str.peek() == '"')
        {
            str.get();
            prodCat = "N/A";
        }
        else{
            getline(str, temp, ',');
            prodCat = temp;
        }
        
        Data* newData = new Data(id, product, brandName, prodAsin, prodCat);
        bst.insert(*newData, bst.getRoot());
        
    }
}

int main(int argc, char const *argv[])
{
    BST<Data> bst;

    importList(bst);
    string line;
    bootStrap();
    while (getline(cin, line) && line != ":quit")
    {
        if (validCommand(line))
        {
            evalCommand(line, bst);
        }
        else
        {
            cout << "Command not supported. Enter :help for list of supported commands" << endl;
        }
        cout << "> ";
    }
    return 0;
}


