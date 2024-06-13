#include <bits/stdc++.h>
using namespace std;
//n^2 algorithms
void selectionSort(int *arr, int n);
void bubbleSort(int *arr, int n);
void insertionSort(int *arr, int n);

//O(n logn) algorithms
void mergeSort(int a[],int start,int end);
void mergeArr(int a[],int start, int mid, int end);
void quickSort(int a[],int start, int end);

void copyArr(int *arr, int *arr1, int n);
int main()
{
	srand(time(NULL));
    clock_t start, end;
    int n[] = {1000, 3000, 5000, 7000, 9000, 11000, 13000, 15000, 17000, 19000};
    ofstream file("file.txt");

    for(int i=0; i<10; i++)
    {
    	double start = 0, end = 0, bsTime, isTime, msTime, qsTime, ssTime;
    	int arr[n[i]], org[n[i]];
    	for(int j=0; j<n[i]; j++)
    		arr[j] = rand() % 999999 + 999;;

    	copyArr(org, arr, n[i]);
    	start = clock();
        bubbleSort(org, n[i]);
        end = clock();
        bsTime = ((double) (end - start)) / CLOCKS_PER_SEC;

        copyArr(org, arr, n[i]);
        start = clock();
        insertionSort(org, n[i]);
        end = clock();
        isTime = ((double) (end - start)) / CLOCKS_PER_SEC;

        copyArr(org, arr, n[i]);
        start = clock();
        selectionSort(org, n[i]);
        end = clock();
        ssTime = ((double) (end - start)) / CLOCKS_PER_SEC;

        copyArr(org, arr, n[i]);
        start = clock();
        mergeSort(org, 0, n[i]-1);
        end = clock();
        msTime = ((double) (end - start)) / CLOCKS_PER_SEC;

        copyArr(org, arr, n[i]);
        start = clock();
        mergeSort(org, 0, n[i]-1);
        end = clock();
        qsTime = ((double) (end - start)) / CLOCKS_PER_SEC;
        if(file.is_open())
			file << n[i] << " " << bsTime << " " << isTime << " " << ssTime << " " << msTime << " " << qsTime << "\n";
        cout << n[i] << "\t" << bsTime << "\t" << isTime << "\t" << ssTime << "\t" << msTime << "\t" << qsTime << "\n";
    }
    file.close();
}

void copyArr(int *org, int *arr, int n)
{
	for(int i=0; i<n; i++)
		org[i] = arr[i];
}

void bubbleSort(int *a, int n)
{
    int i = 0;
    bool swp = 1;
    while (swp)
    {
        swp = 0;
        for (int j=n-1;j>i;j--)
        {
            if (a[j]<a[j-1])
            {
                swap (a[j],a[j-1]);
                swp = 1;
            }
        }
        i++;
    }
}

void insertionSort(int *a, int n)
{
     int key,j;
     for (int i=0;i<n;i++)
     {
        key=a[i];
        j=i-1;
        while(key<a[j]&&j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1] = key;
     }
}

void selectionSort(int *a, int n)
{
    int small,idx_small;
    for (int i=0; i<n-1;i++)
    {
        idx_small = i;
        for (int j=i+1;j<n;j++)
        {
            if (a[j]<a[idx_small])
            {
                idx_small = j;
            }
        }
    	swap (a[i],a[idx_small]);
    }
}

void mergeSort(int *a,int start,int end)
{
	int mid;
    if(start<end)
    {
        mid = (start+end)/2;
        mergeSort(a,start,mid);
        mergeSort(a,mid+1,end);
        mergeArr(a,start,mid,end);
    }
}

void mergeArr(int a[],int start, int mid, int end)
{
    int temp[end+1],size,ptr1,ptr2;
    int i,j;
    size = end - start;
    ptr1=start;
    ptr2 =mid+1;
    j=0;
    while(ptr1<mid+1&&ptr2<end+1)
    {
        if (a[ptr1]<a[ptr2])
        {
            temp[j]=a[ptr1];
            ptr1++;
            j++;
        }
        else
        {
            temp[j]=a[ptr2];
            ptr2++;
            j++;
        }
    }
    if(ptr1<mid+1)
    {
        for (i=j;i<size+1;i++)
        {
                temp[i]=a[ptr1];
                ptr1++;
        }
    }
    if(ptr2<end+1)
    {
        for (i=j;i<size+1;i++)
        {
            temp[i]=a[ptr2];
            ptr2++;
        }
    }
    for (j=0;j<size+1;j++)
        a[start+j]=temp[j];
}

void quickSort(int a[],int start, int end)
{
    int i, j, pivot;
    if (start<end)
    {
        pivot = a[start];
        i=start+1;
        while(a[i]<pivot)
            i++;
        j=end;
        while(a[j]>pivot)
            j--;
        while(i<j)
        {
            swap(a[i],a[j]);
            i++;
            while(a[i]<pivot)
                i++;
            j--;
            while(a[j]>pivot)
                j--;
        }
    swap(a[start],a[j]);
    quickSort(a,start,j-1);
    quickSort(a,j+1,end);
   }
}