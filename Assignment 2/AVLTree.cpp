// AVL tree implementation in C++

#include <iostream>
using namespace std;

class Node {
   public:
  int key;
  Node *left;
  Node *right;
  int height;
};

int max(int a, int b);

// Calculate height
int height(Node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

// New node creation
Node *newNode(int key) {
  Node *node = new Node();
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

// Rotate right
Node *rightRotate(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(height(y->left),
          height(y->right)) +
        1;
  x->height = max(height(x->left),
          height(x->right)) +
        1;
  return x;
}

// Rotate left
Node *leftRotate(Node *x) {
  Node *y = x->right;
  Node *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height(x->left),
          height(x->right)) +
        1;
  y->height = max(height(y->left),
          height(y->right)) +
        1;
  return y;
}

// Get the balance factor of each node
int getBalanceFactor(Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) -
       height(N->right);
}

Node* balanceNode(Node* node) {
    int balanceFactor = getBalanceFactor(node);

    // Left-heavy case
    if (balanceFactor > 1) {
        if (getBalanceFactor(node->left) >= 0) {
            // Left-Left Case
            return rightRotate(node);
        } else {
            // Left-Right Case
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }

    // Right-heavy case
    if (balanceFactor < -1) {
        if (getBalanceFactor(node->right) <= 0) {
            // Right-Right Case
            return leftRotate(node);
        } else {
            // Right-Left Case
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    // Node is balanced, no rotation needed
    return node;
}


// Insert a node
Node *insertNode(Node *node, int key) {
  // Find the correct postion and insert the node
  if (node == NULL)
    return (newNode(key));
  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;

  // Update the balance factor of each node and
  // balance the tree
  node->height = 1 + max(height(node->left),
               height(node->right));
  return balanceNode(node);
}

// Node with minimum value
Node *nodeWithMimumValue(Node *node) {
  Node *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;

    // Find the node to delete
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with 0 children
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // Node with 1 child (right)
        if (root->left == nullptr && root->right != nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Node with 1 child (left)
        if (root->left != nullptr && root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with 2 children
        Node* temp = nodeWithMimumValue(root->right); // Get the inorder successor
        root->key = temp->key; // Copy the inorder successor's value to this node
        root->right = deleteNode(root->right, temp->key); // Delete the inorder successor
    }

    // Update height and balance the node
    root->height = 1 + max(height(root->left), height(root->right));
    return balanceNode(root);
}


// Print the tree
void printTree(Node *root) {
  if (root != nullptr) {
    printTree(root->left);
    cout << root->key<<" ";
    printTree(root->right);
  }
}

int main() {
  Node *root = NULL;
  root = insertNode(root, 33);
  root = insertNode(root, 13);
  root = insertNode(root, 53);
  root = insertNode(root, 9);
  root = insertNode(root, 21);
  root = insertNode(root, 61);
  root = insertNode(root, 8);
  root = insertNode(root, 11);
  printTree(root);
  root = deleteNode(root, 13);
  root = deleteNode(root, 61);
  cout << "\nAfter deleting " << endl;
  printTree(root);
}