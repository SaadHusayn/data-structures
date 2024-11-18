#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Record structure for storing ID, Name, and Age
class Record {
    public:
    int id;
    string name;
    int age;


    Record(int _id=0, string _name="", int _age=0) : id(_id), name(_name), age(_age) {}
};

// A BTree Node structure
class BTreeNode {
public:
    vector<Record> records;     // List of records (keys with additional data)
    vector<BTreeNode*> children; // Child pointers
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
            cout << "ID: " << records[i].id << ", Name: " << records[i].name << ", Age: " << records[i].age << endl;
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
        cout << endl;
    }

    Record* search(int id) {
        return root ? root->search(id) : nullptr;
    }

    void insert(int id, string name, int age);
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

void BTree::insert(int id, string name, int age) {
    Record record(id, name, age);

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

// Main function
int main() {
    BTree btree(3); // Create a BTree of degree 3

    // Insert records
    btree.insert(1, "Saad", 18);
    btree.insert(2, "Ali", 21);
    btree.insert(3, "Ahmed", 20);
    btree.insert(4, "Ayesha", 19);
    btree.insert(5, "Fatima", 22);

    cout << "Traversal of tree after insertion:\n";
    btree.traverse();

    // Search for a record
    int searchId = 3;
    Record* result = btree.search(searchId);
    if (result) {
        cout << "Record found:\n";
        cout << "ID: " << result->id << ", Name: " << result->name << ", Age: " << result->age << endl;
    } else {
        cout << "Record with ID " << searchId << " not found.\n";
    }

    

    return 0;
}
