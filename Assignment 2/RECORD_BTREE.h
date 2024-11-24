#ifndef RECORD_BTREE_h
#define RECORD_BTREE_h

#include <iostream>
#include <vector>
#include <string>
#include "RECORD.h"

// A BTree Node structure
class BTreeNode {
public:
    std::vector<Record> records;     // List of records (keys with additional data)
    std::vector<BTreeNode*> children; // Child pointers
    bool isLeaf;                 // Is true if the node is a leaf
    int maxKeys;                 // Maximum number of keys in the node

    // Constructor
    BTreeNode(int maxKeys, bool isLeaf) {
        this->maxKeys = maxKeys;
        this->isLeaf = isLeaf;
    }

    // Traverse the tree and print records
    void traverse() {
        for (int i = 0; i < records.size(); i++) {
            if (!isLeaf)
                children[i]->traverse();
            std::cout << "ID: " << records[i].id << ", Name: " << records[i].name << ", Age: " << records[i].age << std::endl;
        }
        if (!isLeaf)
            children[records.size()]->traverse();
    }

    // Search for a record by ID in the subtree rooted with this node
    Record* search(int id) {
        int i = 0;
        while (i < records.size() && id > records[i].id)
            i++;

        if (i < records.size() && records[i].id == id)
            return &records[i];

        return isLeaf ? nullptr : children[i]->search(id);
    }

    // Insert a record in a non-full node
    void insertNonFull(Record record);
    // Split a child
    void splitChild(int i, BTreeNode* child);
};

class BTree {
public:
    BTreeNode* root;
    int maxKeys;

    BTree(int degree) {
        root = nullptr;
        maxKeys = degree - 1;
    }

    void traverse() {
        if (root)
            root->traverse();
        std::cout << std::endl;
    }

    Record* search(int id) {
        return root ? root->search(id) : nullptr;
    }

    void insert(Record rec);
};

void BTreeNode::insertNonFull(Record record) {
    int i = records.size() - 1;

    if (isLeaf) {
        records.push_back({0, "", 0}); // Extend size
        while (i >= 0 && records[i].id > record.id) {
            records[i + 1] = records[i];
            i--;
        }
        records[i + 1] = record;
    } else {
        while (i >= 0 && records[i].id > record.id)
            i--;

        if (children[i + 1]->records.size() == maxKeys) {
            splitChild(i + 1, children[i + 1]);
            if (records[i + 1].id < record.id)
                i++;
        }
        children[i + 1]->insertNonFull(record);
    }
}

void BTreeNode::splitChild(int i, BTreeNode* child) {
    int mid = maxKeys / 2;
    BTreeNode* newChild = new BTreeNode(maxKeys, child->isLeaf);

    for (int j = mid + 1; j < child->records.size(); j++)
        newChild->records.push_back(child->records[j]);

    if (!child->isLeaf) {
        for (int j = mid + 1; j <= child->records.size(); j++)
            newChild->children.push_back(child->children[j]);
    }

    child->records.resize(mid);
    if (!child->isLeaf)
        child->children.resize(mid + 1);

    children.insert(children.begin() + i + 1, newChild);
    records.insert(records.begin() + i, child->records[mid]);
}

void BTree::insert(Record record = Record()) {


    if (!root) {
        root = new BTreeNode(maxKeys, true);
        root->records.push_back(record);
    } else {
        if (root->records.size() == maxKeys) {
            BTreeNode* newRoot = new BTreeNode(maxKeys, false);
            newRoot->children.push_back(root);
            newRoot->splitChild(0, root);
            root = newRoot;
        }
        root->insertNonFull(record);
    }
}


#endif