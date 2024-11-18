#include <iostream>
#include <vector>
using namespace std;

// A BTree Node structure
class BTreeNode {
public:
    vector<int> keys;       // Keys in the node
    vector<BTreeNode*> children; // Child pointers
    bool isLeaf;            // Is true if the node is a leaf
    int maxKeys;            // Maximum number of keys in the node

    // Constructor
    BTreeNode(int maxKeys, bool isLeaf) {
        this->maxKeys = maxKeys;
        this->isLeaf = isLeaf;
    }

    // Traverse the tree and print keys
    void traverse() {
        for (int i = 0; i < keys.size(); i++) {
            if (!isLeaf)
                children[i]->traverse();
            cout << keys[i] << " ";
        }
        if (!isLeaf)
            children[keys.size()]->traverse();
    }

    // Search for a key in the subtree rooted with this node
    BTreeNode* search(int key) {
        int i = 0;
        while (i < keys.size() && key > keys[i])
            i++;

        if (i < keys.size() && keys[i] == key)
            return this;

        return isLeaf ? nullptr : children[i]->search(key);
    }

    // Insert a key in a non-full node
    void insertNonFull(int key);
    // Split a child
    void splitChild(int i, BTreeNode* child);
    // Remove a key
    void remove(int key);
    int findKey(int key);
    void removeFromLeaf(int idx);
    void removeFromNonLeaf(int idx);
    int getPredecessor(int idx);
    int getSuccessor(int idx);
    void fill(int idx);
    void borrowFromPrev(int idx);
    void borrowFromNext(int idx);
    void merge(int idx);
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

    BTreeNode* search(int key) {
        return root ? root->search(key) : nullptr;
    }

    void insert(int key);
    void remove(int key);
};

void BTreeNode::insertNonFull(int key) {
    int i = keys.size() - 1;

    if (isLeaf) {
        keys.push_back(0); // Extend size
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
    } else {
        while (i >= 0 && keys[i] > key)
            i--;

        if (children[i + 1]->keys.size() == maxKeys) {
            splitChild(i + 1, children[i + 1]);
            if (keys[i + 1] < key)
                i++;
        }
        children[i + 1]->insertNonFull(key);
    }
}

void BTreeNode::splitChild(int i, BTreeNode* child) {
    int mid = maxKeys / 2;
    BTreeNode* newChild = new BTreeNode(maxKeys, child->isLeaf);

    for (int j = mid + 1; j < child->keys.size(); j++)
        newChild->keys.push_back(child->keys[j]);

    if (!child->isLeaf) {
        for (int j = mid + 1; j <= child->keys.size(); j++)
            newChild->children.push_back(child->children[j]);
    }

    child->keys.resize(mid);
    if (!child->isLeaf)
        child->children.resize(mid + 1);

    children.insert(children.begin() + i + 1, newChild);
    keys.insert(keys.begin() + i, child->keys[mid]);
}

void BTree::insert(int key) {
    if (!root) {
        root = new BTreeNode(maxKeys, true);
        root->keys.push_back(key);
    } else {
        if (root->keys.size() == maxKeys) {
            BTreeNode* newRoot = new BTreeNode(maxKeys, false);
            newRoot->children.push_back(root);
            newRoot->splitChild(0, root);
            root = newRoot;
        }
        root->insertNonFull(key);
    }
}

int BTreeNode::findKey(int key) {
    int idx = 0;
    while (idx < keys.size() && keys[idx] < key)
        idx++;
    return idx;
}

void BTreeNode::remove(int key) {
    int idx = findKey(key);

    if (idx < keys.size() && keys[idx] == key) {
        if (isLeaf)
            removeFromLeaf(idx);
        else
            removeFromNonLeaf(idx);
    } else {
        if (isLeaf)
            return;

        bool flag = (idx == keys.size());
        if (children[idx]->keys.size() < (maxKeys + 1) / 2)
            fill(idx);

        if (flag && idx > keys.size())
            children[idx - 1]->remove(key);
        else
            children[idx]->remove(key);
    }
}

void BTreeNode::removeFromLeaf(int idx) {
    keys.erase(keys.begin() + idx);
}

void BTreeNode::removeFromNonLeaf(int idx) {
    int key = keys[idx];
    if (children[idx]->keys.size() >= (maxKeys + 1) / 2) {
        int pred = getPredecessor(idx);
        keys[idx] = pred;
        children[idx]->remove(pred);
    } else if (children[idx + 1]->keys.size() >= (maxKeys + 1) / 2) {
        int succ = getSuccessor(idx);
        keys[idx] = succ;
        children[idx + 1]->remove(succ);
    } else {
        merge(idx);
        children[idx]->remove(key);
    }
}

int BTreeNode::getPredecessor(int idx) {
    BTreeNode* cur = children[idx];
    while (!cur->isLeaf)
        cur = cur->children[cur->keys.size()];
    return cur->keys.back();
}

int BTreeNode::getSuccessor(int idx) {
    BTreeNode* cur = children[idx + 1];
    while (!cur->isLeaf)
        cur = cur->children[0];
    return cur->keys[0];
}

void BTreeNode::fill(int idx) {
    if (idx != 0 && children[idx - 1]->keys.size() >= (maxKeys + 1) / 2)
        borrowFromPrev(idx);
    else if (idx != keys.size() && children[idx + 1]->keys.size() >= (maxKeys + 1) / 2)
        borrowFromNext(idx);
    else {
        if (idx != keys.size())
            merge(idx);
        else
            merge(idx - 1);
    }
}

void BTreeNode::borrowFromPrev(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx - 1];

    child->keys.insert(child->keys.begin(), keys[idx - 1]);
    if (!child->isLeaf)
        child->children.insert(child->children.begin(), sibling->children.back());

    keys[idx - 1] = sibling->keys.back();
    sibling->keys.pop_back();
    if (!sibling->isLeaf)
        sibling->children.pop_back();
}

void BTreeNode::borrowFromNext(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx + 1];

    child->keys.push_back(keys[idx]);
    if (!child->isLeaf)
        child->children.push_back(sibling->children[0]);

    keys[idx] = sibling->keys[0];
    sibling->keys.erase(sibling->keys.begin());
    if (!sibling->isLeaf)
        sibling->children.erase(sibling->children.begin());
}

void BTreeNode::merge(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx + 1];

    child->keys.push_back(keys[idx]);
    for (int i = 0; i < sibling->keys.size(); i++)
        child->keys.push_back(sibling->keys[i]);

    if (!child->isLeaf) {
        for (int i = 0; i <= sibling->keys.size(); i++)
            child->children.push_back(sibling->children[i]);
    }

    keys.erase(keys.begin() + idx);
    children.erase(children.begin() + idx + 1);

    delete sibling;
}

void BTree::remove(int key) {
    if (!root)
        return;

    root->remove(key);

    if (root->keys.empty()) {
        BTreeNode* oldRoot = root;
        root = root->isLeaf ? nullptr : root->children[0];
        delete oldRoot;
    }
}

// Main function
int main() {
    BTree btree(3); // Create a BTree of degree 3

    // Insert some keys
    btree.insert(10);
    btree.insert(20);
    btree.insert(5);
    btree.insert(6);
    btree.insert(12);
    btree.insert(30);
    btree.insert(7);
    btree.insert(17);

    cout << "Traversal of tree after insertion: ";
    btree.traverse();

    // Search for a key
    int key = 6;
    if (btree.search(key))
        cout << "Key " << key << " found in the BTree.\n";
    else
        cout << "Key " << key << " not found in the BTree.\n";

    // Delete some keys
    btree.remove(6);
    btree.remove(13); // Key not in the tree
    // btree.remove(7);
    
    cout<<"\n"<<btree.search(7)<<"\n";

    cout << "Traversal of tree after deletion: ";
    btree.traverse();

    return 0;
}
