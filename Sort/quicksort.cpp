#include <iostream>
#include <random>
#include <time.h>
#include <stack>
using namespace std;

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

int Split(int a[],int low,int high)
{
    int x = a[low];
    int i = low,j;
    int temp;
    for (j = low + 1; j <= high;j++)
    {
        if(a[j]<x)
        {
            i++;
            if(i != j)
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
        
    }
    temp = a[i];
    a[i] = a[low];
    a[low] = temp;
    return i;
}
void QuickSort(int a[],int low,int high)
{
    if(low<high)
    {
        int w = Split(a, low, high);
        QuickSort(a, low, w - 1);
        QuickSort(a, w + 1, high);
    }
}