#include <iostream>
#include <random>
#include <time.h>
#include <stack>
using namespace std;
void bubblesort(int a[], int n);
void siftdown(int a[], int i, int n);
void makeheap(int a[], int n);
void heapsort(int a[], int n);
void mergesort(int a[], int n);
void iterative_quicksort(int a[],int low,int high)
{
    int i, j, t;
    int standard;
    stack<int> s;
    s.push(low);
    s.push(high);
    while(!s.empty())
    {
        high = s.top();
        s.pop();
        low = s.top();
        s.pop();
        standard = a[low];
        if(high <= low)
        {
            continue;
        }
        i = low;
        j = high;
        while(i!=j)
        {
            while(a[j]>=standard && i != j)
            {
                j--;
            }
            while(a[i]<=standard && i != j)
            {
                i++;
            }
            if(i < j)
            {
                t = a[j];
                a[j] = a[i];
                a[i] = t;
            }
        }
        if(i>low)
        {
            t = a[i];
            a[i] = a[low];
            a[low] = t;
        }

        s.push(low);
        s.push(i - 1);
        s.push(j + 1);
        s.push(high);
    }
}

int split(int a[],int low,int high)
{
    int x = a[low];
    int i = low,j;
    int temp;
    for(j = low+1; j <= high;j++)
    {
        if(a[j] <= x)
        {
            i++;
            if(i!=j)
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
    temp = a[i];
    a[i] = x;
    a[low] = temp;
    return i;
}

void recursive_quicksort(int a[],int low,int high)
{
    if(low < high)
    {
        int w;
        w = split(a,low,high);
        /* For debugging...
        cout << "Split:\n";
        for (int i = 0; i < 8;i++)
        {
            cout << a[i] << ' ';
        }
        cout << endl;
        cout <<"==================="<<w<<"==================="<<endl;
        */
        recursive_quicksort(a,low,w-1);
        recursive_quicksort(a,w+1,high);
    }
}

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
    heapsort(n2, 200000);
    end = clock();
    cout << "heapsort:" << (end - start) << endl;
    cout << endl;
    cout << endl;
    //recursive_quicksort(nsmall, 0, 99);
    heapsort(nsmall, 100);
    cout << "Result:\n";
    for (int i = 0; i < 100;i++)
    {
        
        cout << nsmall[i] << ' ';
    }
    cout << endl;
    return 0;
}