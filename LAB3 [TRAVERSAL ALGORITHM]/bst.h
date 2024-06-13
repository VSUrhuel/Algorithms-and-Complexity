#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include <iostream>
using namespace std;

struct BST_Node {
  int key;
  struct BST_Node *left, *right;
};

typedef BST_Node *BST_NodePtr;

// Binary Search Tree operations in C++

// Create a BST_Node
BST_NodePtr newBST_Node(int item) {
  BST_NodePtr temp = (BST_NodePtr)malloc(sizeof(struct BST_Node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(BST_NodePtr root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    cout << root->key << " -> ";

    // Traverse right
    inorder(root->right);
  }
}

// Searching Element
int BST_search(int element, BST_NodePtr root)
{
    if (root == NULL)
        return 0;
    if (element == root->key)
        return root->key;
    if (element < (root->key))
        return BST_search(element, root->left);
    if (element > (root->key))
        return BST_search(element, root->right);
    return 0;
}

// BST_insert a BST_Node
BST_NodePtr BST_insert(BST_NodePtr BST_Node, int key) {
  // Return a new BST_Node if the tree is empty
  if (BST_Node == NULL) return newBST_Node(key);
  
  // Traverse to the right place and BST_insert the BST_Node
  if (key < BST_Node->key)
    BST_Node->left = BST_insert(BST_Node->left, key);
  else
    BST_Node->right = BST_insert(BST_Node->right, key);

  return BST_Node;
}

// Find the inorder successor
BST_NodePtr minValueBST_Node(BST_NodePtr BST_Node) {
  BST_NodePtr current = BST_Node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Deleting a BST_Node
BST_NodePtr BST_delete(BST_NodePtr root, int key) {
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the BST_Node to be deleted
  if (key < root->key)
    root->left = BST_delete(root->left, key);
  else if (key > root->key)
    root->right = BST_delete(root->right, key);
  else {
    // If the BST_Node is with only one child or no child
    if (root->left == NULL) {
      BST_NodePtr temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      BST_NodePtr temp = root->left;
      free(root);
      return temp;
    }

    // If the BST_Node has two children
    BST_NodePtr temp = minValueBST_Node(root->right);

    // Place the inorder successor in position of the BST_Node to be deleted
    root->key = temp->key;

    // Delete the inorder successor
    root->right = BST_delete(root->right, temp->key);
  }
  return root;
}



#endif // BST_H_INCLUDED
