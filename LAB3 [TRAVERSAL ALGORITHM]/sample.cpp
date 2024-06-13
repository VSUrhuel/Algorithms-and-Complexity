#include "bst.h"
#include "avl.h"
#include "rbt.h"
#include <bits/stdc++.h>

using namespace std;

void copyArr(int *arr, int *arr1, int n);
struct node *insertBST(int *arr, int n);
Node *insertAVL(int *arr, int n);
RedBlackTree insertRBT(int *arr, int n);

void searchBST(int *arr, int n, struct node *root);
void searchAVL(int *arr, int n, Node *root);
void searchRBT(int *arr, int n, RedBlackTree root);

void deleteBST(int *arr, int n, struct node *root);
void deleteAVL(int *arr, int n, Node *root);
void deleteRBT(int *arr, int n, RedBlackTree root);

int main()
{
    srand(time(NULL));
    clock_t start, end;
    int n[] = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 100000};
   // int arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99};
    int arr2[] = {84, 65, 17, 61, 95, 52, 8, 95, 31, 86, 75, 26, 65, 99, 98, 26, 18, 81, 52, 23, 100, 31, 44, 46, 7, 17, 68, 22, 14, 82, 63, 98, 99, 32, 10, 93, 35, 17, 88, 66, 2, 14, 43, 19, 13, 40, 44, 30, 72, 95, 53, 71, 25, 48, 69, 83, 64, 36, 4, 77, 70, 19, 26, 68, 50, 35, 60, 36, 4, 99, 1, 5, 13, 43, 75, 77, 35, 18, 6, 6, 64, 58, 77, 40, 5, 45, 22, 68, 32, 78, 97, 1, 96, 22, 20, 97, 9, 32, 32, 12};
    int arr3[] = {82, 85, 68, 94, 27, 43, 22, 13, 12, 28, 19, 28, 37, 95, 67, 42, 91, 41, 61, 22, 18, 9, 23, 65, 31, 94, 13, 91, 25, 44, 2, 7, 80, 69, 52, 59, 63, 74, 71, 75, 53, 89, 2, 89, 35, 20, 82, 25, 60, 95, 47, 29, 3, 21, 93, 85, 14, 5, 75, 91, 1, 76, 49, 80, 97, 100, 90, 59, 25, 61, 85, 77, 49, 38, 18, 36, 58, 99, 60, 69, 93, 6, 98, 48, 78, 42, 32, 44, 47, 59, 34, 99, 86, 82, 30, 82, 33, 20, 93, 10};
    struct node *bsTree = NULL;
    Node *avlTree = NULL;
    RedBlackTree brt;
    double iBST, iAVL, iRBT;
    int x = sizeof(n)/sizeof(int);
    int arr1[100000] = {0};
    for(int i=0; i<100000; i++)
        arr1[i] = i;
    for(int i=0; i<1; i++)
    {
        start = clock();
        bsTree = insertBST(arr1, 100000);
        end = clock();
        iBST = ((double) (end - start)) / CLOCKS_PER_SEC;

        start = clock();
        avlTree = insertAVL(arr1, 100000);
        end = clock();
        iAVL = ((double) (end - start)) / CLOCKS_PER_SEC;

        start = clock();
        brt = insertRBT(arr1, 100000);
        end = clock();
        iRBT = ((double) (end - start)) / CLOCKS_PER_SEC;
        cout <<  "Inserting: " << "\t" << iBST << "\t" << iAVL << "\t" << iRBT << "\n";
        // Searching
        start = clock();
        searchBST(arr1, 100000, bsTree);
        end = clock();
        iBST = ((double) (end - start)) / CLOCKS_PER_SEC;

        start = clock();
        searchAVL(arr1, 100000, avlTree);
        end = clock();
        iAVL = ((double) (end - start)) / CLOCKS_PER_SEC;

        start = clock();
        searchRBT(arr1, 100000, brt);
        end = clock();
        iRBT = ((double) (end - start)) / CLOCKS_PER_SEC;
        //brt.RBT_print();
        cout <<  "Searching: " << "\t" << iBST << "\t" << iAVL << "\t" << iRBT << "\n";

        start = clock();
        start = clock();
        deleteBST(arr1, 100000, bsTree);
        end = clock();
        iBST = ((double) (end - start)) / CLOCKS_PER_SEC;

        start = clock();
        deleteAVL(arr1, 100000, avlTree);
        end = clock();
        iAVL = ((double) (end - start)) / CLOCKS_PER_SEC;

        start = clock();
        deleteRBT(arr1, 100000, brt);
        end = clock();
        iRBT = ((double) (end - start)) / CLOCKS_PER_SEC;
        //brt.RBT_print();
        cout <<  "Deleting: " << "\t" << iBST << "\t" << iAVL << "\t" << iRBT << "\n";
    }

    /*for(int i=0; i<100; i++)
    {
        start = clock();
        bsTree = insertBST(arr2, 100);
        end = clock();
        iBST = ((double) (end - start)) / CLOCKS_PER_SEC;

        start = clock();
        avlTree = insertAVL(arr2, 100);
        end = clock();
        iAVL = ((double) (end - start)) / CLOCKS_PER_SEC;

        start = clock();
        brt = insertRBT(arr2, 100);
        end = clock();
        iRBT = ((double) (end - start)) / CLOCKS_PER_SEC;
        cout <<  "Inserting: " << "\t" << iBST << "\t" << iAVL << "\t" << iRBT << "\n";
        // Searching
        start = clock();
        searchBST(arr2, 100, bsTree);
        end = clock();
        iBST = ((double) (end - start)) / CLOCKS_PER_SEC;

        start = clock();
        searchAVL(arr2, 100, avlTree);
        end = clock();
        iAVL = ((double) (end - start)) / CLOCKS_PER_SEC;

        start = clock();
        searchRBT(arr1, 100, brt);
        end = clock();
        iRBT = ((double) (end - start)) / CLOCKS_PER_SEC;
        //brt.RBT_print();
        cout <<  "Searching: " << "\t" << iBST << "\t" << iAVL << "\t" << iRBT << "\n";

        start = clock();
        start = clock();
        deleteBST(arr1, 100, bsTree);
        end = clock();
        iBST = ((double) (end - start)) / CLOCKS_PER_SEC;

        start = clock();
        deleteAVL(arr2, 100, avlTree);
        end = clock();
        iAVL = ((double) (end - start)) / CLOCKS_PER_SEC;

        start = clock();
        deleteRBT(arr2, 100, brt);
        end = clock();
        iRBT = ((double) (end - start)) / CLOCKS_PER_SEC;
        //brt.RBT_print();
        cout <<  "Deleting: " << "\t" << iBST << "\t" << iAVL << "\t" << iRBT << "\n";
    }*/
}

void copyArr(int *org, int *arr, int n)
{
	for(int i=0; i<n; i++)
		org[i] = arr[i];
}

struct node *insertBST(int arr[], int n)
{
    struct node *root = NULL;
    for(int i=0; i<n; i++)
        BST_insert(root, arr[i]);
    return root;
}

Node *insertAVL(int arr[], int n)
{
    Node *root = NULL;
    for(int i=0; i<n; i++)
        AVL_insert(root, arr[i]);

    return root;
}

RedBlackTree insertRBT(int arr[], int n)
{
    RedBlackTree rbt;
    for(int i=0; i<n; i++)
        rbt.RBT_insert(arr[i]);
    return rbt;
}

void searchBST(int arr[], int n, struct node *root)
{
    for(int i=0; i<n; i++)
    {
        int index = rand() % (n-0 + 1) + 0;
        BST_search(arr[index], root);
    }
}

void searchAVL(int arr[], int n, Node *root)
{
    for(int i=0; i<n; i++)
    {
        int index = rand() % (n-0 + 1) + 1;
        AVL_search(arr[index], root);
    }
}

void searchRBT(int arr[], int n, RedBlackTree root)
{
    for(int i=0; i<n; i++)
    {
       int index = rand() % (n-0 + 1) + 0;
       root.RBT_search(arr[index]);
    }
}

void deleteBST(int arr[], int n, struct node *root)
{
    for(int i=0; i<n; i++)
    {
        int index = rand() % (n-0 + 1) + 0;
        BST_deleteNode(root, arr[index]);
    }
}

void deleteAVL(int arr[], int n, Node *root)
{
    for(int i=0; i<n; i++)
    {
        int index = rand() % (n-0 + 1) + 1;
        AVL_deleteNode(root, arr[index]);
    }
}

void deleteRBT(int arr[], int n, RedBlackTree root)
{

    for(int i=0; i<n; i++)
    {
       int index = rand() % (n-0 + 1) + 0;
       root.RBT_delete(arr[index]);
    }
}

/*
{

    RedBlackTree rbt;
      rbt.RBT_insert(55);
      rbt.RBT_insert(40);
      rbt.RBT_insert(65);
      rbt.RBT_insert(60);
      rbt.RBT_insert(75);
      rbt.RBT_insert(57);

      rbt.RBT_print();
      cout << endl
         << "After deleting" << endl;
      rbt.RBT_delete(40);
      rbt.RBT_print();
      cout << "Searching: " << rbt.RBT_search(100) << endl;*/

    /*Node *root = NULL;
      root = AVL_insert(root, 33);
      root = AVL_insert(root, 13);
      root = AVL_insert(root, 53);
      root = AVL_insert(root, 9);
      root = AVL_insert(root, 21);
      root = AVL_insert(root, 61);
      root = AVL_insert(root, 8);
      root = AVL_insert(root, 11);
      AVL_printTree(root, "", true);
      root = AVL_deleteNode(root, 13);
      cout << "After deleting " << endl;
      AVL_printTree(root, "", true);
      cout << "Searching: " << AVL_search(root, 8) << endl;*/
    /*struct node *root = NULL;
    root = BST_insert(root, 8);
    root = BST_insert(root, 3);
    root = BST_insert(root, 1);
    root = BST_insert(root, 6);
    root = BST_insert(root, 7);
    root = BST_insert(root, 10);
    root = BST_insert(root, 14);
    root = BST_insert(root, 4);

    cout << "Inorder traversal: ";
    BST_inorder(root);
    cout << "Searching: ";
    cout << BST_search(6, root) << endl;
    cout << "\nAfter deleting 10\n";
    root = BST_deleteNode(root, 10);
    cout << "Inorder traversal: ";
    BST_inorder(root);*/



