#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

// AVL tree implementation in C++

#include <iostream>
using namespace std;

class AVL_Node {
   public:
  int key;
  AVL_Node *left;
  AVL_Node *right;
  int height;
};

int max(int a, int b);

// Calculate height
int height(AVL_Node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

// New AVL_Node creation
AVL_Node *newAVL_Node(int key) {
  AVL_Node *node = new AVL_Node();
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

// Searching a AVL_Node
int AVL_search(int key, AVL_Node* root)
{
    if (root == NULL)
        return -1;
    if (root->key == key)
    {
      return root->key;  // Key found
    }

    if (key < root->key)
    {
      return AVL_search(key, root->left);  // Search in left subtree
    }
    else
    {
      return AVL_search(key, root->right); // Search in right subtree
    }
}

// Rotate right
AVL_Node *rightRotate(AVL_Node *y) {
  AVL_Node *x = y->left;
  AVL_Node *T2 = x->right;
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
AVL_Node *leftRotate(AVL_Node *x) {
  AVL_Node *y = x->right;
  AVL_Node *T2 = y->left;
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

// Get the balance factor of each AVL_Node
int getBalanceFactor(AVL_Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) -
       height(N->right);
}

// Insert a AVL_Node
AVL_Node *AVL_insert(AVL_Node *AVL_Node, int key) {
  // Find the correct postion and insert the AVL_Node
  if (AVL_Node == NULL)
    return (newAVL_Node(key));
  if (key < AVL_Node->key)
    AVL_Node->left = AVL_insert(AVL_Node->left, key);
  else if (key > AVL_Node->key)
    AVL_Node->right = AVL_insert(AVL_Node->right, key);
  else
    return AVL_Node;

  // Update the balance factor of each AVL_Node and
  // balance the tree
  AVL_Node->height = 1 + max(height(AVL_Node->left),
               height(AVL_Node->right));
  int balanceFactor = getBalanceFactor(AVL_Node);
  if (balanceFactor > 1) {
    if (key < AVL_Node->left->key) {
      return rightRotate(AVL_Node);
    } else if (key > AVL_Node->left->key) {
      AVL_Node->left = leftRotate(AVL_Node->left);
      return rightRotate(AVL_Node);
    }
  }
  if (balanceFactor < -1) {
    if (key > AVL_Node->right->key) {
      return leftRotate(AVL_Node);
    } else if (key < AVL_Node->right->key) {
      AVL_Node->right = rightRotate(AVL_Node->right);
      return leftRotate(AVL_Node);
    }
  }
  return AVL_Node;
}

// AVL_Node with minimum value
AVL_Node *AVL_NodeWithMimumValue(AVL_Node *node) {
  AVL_Node *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}

// Delete a AVL_Node
AVL_Node *AVL_delete(AVL_Node *root, int key) {
  // Find the AVL_Node and delete it
  if (root == NULL)
    return root;
  if (key < root->key)
    root->left = AVL_delete(root->left, key);
  else if (key > root->key)
    root->right = AVL_delete(root->right, key);
  else {
    if ((root->left == NULL) ||
      (root->right == NULL)) {
      AVL_Node *temp = root->left ? root->left : root->right;
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      AVL_Node *temp = AVL_NodeWithMimumValue(root->right);
      root->key = temp->key;
      root->right = AVL_delete(root->right,
                   temp->key);
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each AVL_Node and
  // balance the tree
  root->height = 1 + max(height(root->left),
               height(root->right));
  int balanceFactor = getBalanceFactor(root);
  if (balanceFactor > 1) {
    if (getBalanceFactor(root->left) >= 0) {
      return rightRotate(root);
    } else {
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }
  if (balanceFactor < -1) {
    if (getBalanceFactor(root->right) <= 0) {
      return leftRotate(root);
    } else {
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
  }
  return root;
}

// Print the tree
void printTree(AVL_Node *root, string indent, bool last) {
  if (root != nullptr) {
    cout << indent;
    if (last) {
      cout << "R----";
      indent += "   ";
    } else {
      cout << "L----";
      indent += "|  ";
    }
    cout << root->key << endl;
    printTree(root->left, indent, false);
    printTree(root->right, indent, true);
  }
}


#endif // AVL_H_INCLUDED
