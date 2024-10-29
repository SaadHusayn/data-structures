#include <iostream>
#include "BST.h"
using namespace std;

// Q2. A library wants to organize its collection of books based on their unique ID numbers. As books are
// added or removed from the collection, the system needs to efficiently insert, delete, and search for
// books by their ID.
// Design a BST-based system to:
// 1. Insert a new book into the collection.
// 2. Delete a book from the collection.
// 3. Search for a book by its ID.
// 4. Print all book IDs in ascending order.

int getID(){
    int id;
    cout<<"\nEnter book ID: ";
    cin>>id;
    return id;
}

int main()
{
    BST *Collection = 0;
    int ch = 0;
    auto ID=0;
    BST *result = 0;
    do
    {
        cout<<"\n1. Insert a new book into the collection.\n"
                "2. Delete a book from the collection.\n"
                "3. Search for a book by its ID.\n"
                "4. Print all book IDs in ascending order.\n"
                "5. exit\n";
        cin>>ch;

        switch(ch){
            case 1:
            ID = getID();
            BST::insertNode(Collection, ID);
            cout<<"\nbook has been inserted in the collection"<<endl;
            break;

            case 2:
            ID = getID();
            BST::deleteNode(Collection, ID);
            cout<<"\nbook has been deleted from the collection"<<endl;
            break;

            case 3:
            ID = getID();
            result = BST::find(Collection, ID);
            (result != nullptr) ? (cout<<"Book exists"<<endl) : (cout<<"Book doesnot exists"<<endl);
            break;

            case 4:
            BST::traverseInOrder(Collection);
            cout<<endl;

        }

    } while (ch != 5);
}
