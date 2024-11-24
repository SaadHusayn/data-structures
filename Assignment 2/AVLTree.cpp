// AVL tree implementation in C++

#include <iostream>
using namespace std;

class Record {
    public:
    int id;
    std::string name;
    int age;


    Record(int _id=0, std::string _name="", int _age=0) : id(_id), name(_name), age(_age) {}
};

class AVL {
   public:
  Record rec;
  AVL *left;
  AVL *right;
  int height;

  AVL(Record _rec = Record()){
    rec = _rec;
    left =  nullptr;
    right = nullptr;
    height = 1;
  }
};

int max(int a, int b);

// Calculate height
int height(AVL *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}



// Rotate right
AVL *rightRotate(AVL *y) {
  AVL *x = y->left;
  AVL *T2 = x->right;
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
AVL *leftRotate(AVL *x) {
  AVL *y = x->right;
  AVL *T2 = y->left;
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

// Get the balance factor of each AVL
int getBalanceFactor(AVL *N) {
  if (N == NULL)
    return 0;
  return height(N->left) -
       height(N->right);
}

AVL* balanceAVL(AVL* tree) {
    int balanceFactor = getBalanceFactor(tree);

    // Left-heavy case
    if (balanceFactor > 1) {
        if (getBalanceFactor(tree->left) >= 0) {
            // Left-Left Case
            return rightRotate(tree);
        } else {
            // Left-Right Case
            tree->left = leftRotate(tree->left);
            return rightRotate(tree);
        }
    }

    // Right-heavy case
    if (balanceFactor < -1) {
        if (getBalanceFactor(tree->right) <= 0) {
            // Right-Right Case
            return leftRotate(tree);
        } else {
            // Right-Left Case
            tree->right = rightRotate(tree->right);
            return leftRotate(tree);
        }
    }

    // AVL is balanced, no rotation needed
    return tree;
}


// Insert a AVL
AVL *insertAVL(AVL *tree, int ID, string name, int age) {
  // Find the correct postion and insert the AVL
  if (tree == NULL)
    return new AVL(Record(ID, name, age));
  if (ID < tree->rec.id)
    tree->left = insertAVL(tree->left, ID, name, age);
  else if (ID > tree->rec.id)
    tree->right = insertAVL(tree->right, ID, name, age);
  else
    return tree;

  // Update the balance factor of each AVL and
  // balance the tree
  tree->height = 1 + max(height(tree->left),
               height(tree->right));
  return balanceAVL(tree);
}

// AVL with minimum value
AVL *AVLWithMimumValue(AVL *tree) {
  AVL *current = tree;
  while (current->left != NULL)
    current = current->left;
  return current;
}

AVL* deleteAVL(AVL* tree, int ID) {
    if (tree == nullptr) return tree;

    // Find the AVL to delete
    if (ID < tree->rec.id) {
        tree->left = deleteAVL(tree->left, ID);
    } else if (ID > tree->rec.id) {
        tree->right = deleteAVL(tree->right, ID);
    } else {
        // AVL with 0 children
        if (tree->left == nullptr && tree->right == nullptr) {
            delete tree;
            return nullptr;
        }

        // AVL with 1 child (right)
        if (tree->left == nullptr && tree->right != nullptr) {
            AVL* temp = tree->right;
            delete tree;
            return temp;
        }

        // AVL with 1 child (left)
        if (tree->left != nullptr && tree->right == nullptr) {
            AVL* temp = tree->left;
            delete tree;
            return temp;
        }

        // AVL with 2 children
        AVL* temp = AVLWithMimumValue(tree->right); // Get the inorder successor
        tree->rec = temp->rec; // Copy the inorder successor's value to this AVL
        tree->right = deleteAVL(tree->right, temp->rec.id); // Delete the inorder successor
    }

    // Update height and balance the AVL
    tree->height = 1 + max(height(tree->left), height(tree->right));
    return balanceAVL(tree);
}


// Print the tree
void printTree(AVL *tree) {
  if (tree != nullptr)
    {
        printTree(tree->left);
        std::cout << "ID: " << tree->rec.id << ", Name: " << tree->rec.name << ", Age: " << tree->rec.age << std::endl;
        printTree(tree->right);
    }
}

int main() {
  AVL *root = NULL;
  root = insertAVL(root, 1, "Saad", 19);
  root = insertAVL(root, 2, "Aashir", 19);
  root = insertAVL(root, 3, "Ahsan", 20);

  printTree(root);
  root = deleteAVL(root, 2);
  cout << "\nAfter deleting " << endl;
  printTree(root);
}