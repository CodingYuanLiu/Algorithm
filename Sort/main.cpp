#include <iostream>
#include <random>
#include <time.h>
#include <stack>
using namespace std;
void iterative_quicksort(int a[], int low, int high);
void bubblesort(int a[], int n);
void siftdown(int a[], int i, int n);
void makeheap(int a[], int n);
void heapsort(int a[], int n);
void mergesort(int a[], int n);
void QuickSort(int a[], int low, int high);
void Heapsort(int a[], int len);
void insertSort(int a[], int len);
int main()
{
    int n1[200000],n2[200000],nsmall[100];
    for (int i = 0; i < 200000;i++)
    {
        n1[i] = rand() % 100000;
        n2[i] = n1[i];
        if(i<100)
        {
            nsmall[i] = n1[i] % 1000;
        }
    }
    for (int i = 0; i < 10;i++)
    {
        cout << nsmall[i] << ' ';
    }
    int start = clock();
    iterative_quicksort(n1, 0, 199999);
    int end = clock();
    cout << "iterative_quicksort:" << (end - start) << endl;
    start = clock();
    Heapsort(n2, 200000);
    end = clock();
    cout << "heapsort:" << (end - start) << endl;
    cout << endl;
    cout << endl;
    //recursive_quicksort(nsmall, 0, 99);
    insertSort(nsmall,100);
    cout << "Result:\n";
    for (int i = 0; i < 100;i++)
    {
        
        cout << nsmall[i] << ' ';
    }
    cout << endl;
    return 0;
}