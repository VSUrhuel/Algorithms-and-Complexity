#include "bst.h"
#include "avl.h"
#include "rbt.h"
#include <bits/stdc++.h>

using namespace std;

void copyArr(int *arr, int *arr1, int n);
BST_NodePtr insertBST(int *arr, int n);
AVL_Node *insertAVL(int *arr, int n);
RedBlackTree insertRBT(int *arr, int n);

void searchBST(int *arr, int n, BST_NodePtr root);
void searchAVL(int *arr, int n, AVL_Node *root);
void searchRBT(int *arr, int n, RedBlackTree root);

void deleteBST(int *arr, int n, BST_NodePtr root);
void deleteAVL(int *arr, int n, AVL_Node *root);
void deleteRBT(int *arr, int n, RedBlackTree root);

int main()
{
    srand(time(NULL));
    clock_t start, end;
    int ctr = 0;
    int n[45];
    for(int i=50000; i<500000; i+=10000)
       n[ctr++] = i;
    ofstream isFile("insertFile.txt");
    ofstream seFile("searchFile.txt");
    ofstream deFile("deleteFile.txt");
    BST_NodePtr bsTree = NULL;
    AVL_Node *avlTree = NULL;
    RedBlackTree brt;
    int x = sizeof(n)/sizeof(int);
    for(int i=0; i<x; i++)
    {
        // Insertion
    	double iBST, iAVL, iRBT;
    	int *arr = new int[n[i]];
    	for(int j=0; j<n[i]; j++)
        {
            arr[j] = rand() % 9999 + 100;
        }

        cout << n[i] << endl;

    	start = clock();
        bsTree = insertBST(arr, n[i]);
        end = clock();
        iBST = ((double) (end - start)) / double((CLOCKS_PER_SEC));

        start = clock();
        avlTree = insertAVL(arr, n[i]);
        end = clock();
        iAVL = ((double) (end - start)) / double((CLOCKS_PER_SEC));

        start = clock();
        brt = insertRBT(arr, n[i]);
        end = clock();
        iRBT = ((double) (end - start)) / double(CLOCKS_PER_SEC);
        if(isFile.is_open())
			isFile << n[i] << " " << iBST << " " << iAVL << " " << iRBT << "\n";
        cout <<  "Inserting: " << "\t" << iBST << "\t" << iAVL << "\t" << iRBT << "\n";

        // Searching
        start = clock();
        searchBST(arr, n[i], bsTree);
        end = clock();
        iBST = ((double) (end - start)) / double(CLOCKS_PER_SEC);

        start = clock();
        searchAVL(arr, n[i], avlTree);
        end = clock();
        iAVL = ((double) (end - start)) / double(CLOCKS_PER_SEC);

        start = clock();
        searchRBT(arr, n[i], brt);
        end = clock();
        iRBT = ((double) (end - start)) / double(CLOCKS_PER_SEC);
        cout <<  "Searching: " << "\t" << iBST << "\t" << iAVL << "\t" << iRBT << "\n";
        if(seFile.is_open())
			seFile << n[i] << " " << iBST << " " << iAVL << " " << iRBT << "\n";


        // Deletion
        start = clock();
        start = clock();
        deleteBST(arr, n[i]/8, bsTree);
        end = clock();
        iBST = ((double) (end - start)) / double(CLOCKS_PER_SEC);

        start = clock();
        deleteAVL(arr, n[i]/8, avlTree);
        end = clock();
        iAVL = ((double) (end - start)) / double(CLOCKS_PER_SEC);

        start = clock();
        deleteRBT(arr, n[i]/8, brt);
        end = clock();
        iRBT = ((double) (end - start)) / double(CLOCKS_PER_SEC);
        cout <<  "Deleting: " << "\t" << iBST << "\t" << iAVL << "\t" << iRBT << "\n";
        if(deFile.is_open())
			deFile << n[i] << " " << iBST << " " << iAVL << " " << iRBT << "\n";
    }
    isFile.close();
    seFile.close();
    deFile.close();
}

void copyArr(int *org, int *arr, int n)
{
	for(int i=0; i<n; i++)
		org[i] = arr[i];
}

BST_NodePtr insertBST(int arr[], int n)
{
    BST_NodePtr root = newBST_Node(arr[0]);
    for(int i=0; i<n; i++)
        BST_insert(root, arr[i]);
    return root;
}

AVL_Node *insertAVL(int arr[], int n)
{
    AVL_Node *root = newAVL_Node(arr[0]);
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

void searchBST(int arr[], int n, BST_NodePtr root)
{
    for(int i=0; i<n; i++)
    {
        int index = rand() % (n-0 + 1) + 0;
        BST_search(arr[index], root);
    }
}

void searchAVL(int arr[], int n, AVL_Node *root)
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

void deleteBST(int arr[], int n, BST_NodePtr root)
{
    for(int i=0; i<n; i++)
    {
        int index = rand() % (n-0 + 1) + 0;
        BST_delete(root, arr[index]);
    }
}

void deleteAVL(int arr[], int n, AVL_Node *root)
{
    for(int i=0; i<n; i++)
    {
        int index = rand() % (n-0 + 1) + 1;
        AVL_delete(root, arr[index]);
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