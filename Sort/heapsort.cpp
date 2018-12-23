#include <iostream>
using namespace std;
void Siftdown(int a[], int i, int len);
void Makeheap(int a[], int n);
void siftdown(int a[],int i,int n)
{
    int temp;
    i = 2 * i + 1;//注意是2i+1
    while(i <= n-1)
    {
        if(a[i] < a[i+1] && i<n-1)
            i++;
        if(a[(i-1)/2] < a[i])//注意这里儿子是先-1再/2
        {
            temp = a[i];
            a[i] = a[(i-1) / 2];
            a[(i-1) / 2] = temp;
        }
        i = 2 * i + 1;
    }
}


void makeheap(int a[],int n)
{
    for (int i = n / 2 - 1; i >= 0;i--)
    {
        siftdown(a, i, n);
    }
    
}

void heapsort(int a[],int n)
{
    int temp;
    Makeheap(a, n);
    for (int i = n; i > 1;i--)
    {
        temp = a[i - 1];
        a[i - 1] = a[0];
        a[0] = temp;
        
        Siftdown(a, 0, i-1);//注意这里是i-1
    }
    
}

void Siftdown(int a[],int i,int len)
{
    bool done = false;
    int temp;
    while(!done)
    {
        done = true;
        i = 2 * i + 1;
        if(i>=len)
            break;
        if(i+1 < len && a[i+1]>a[i])
        {
            i = i + 1;
        }
        if(a[i] > a[(i-1)/2])
        {
            temp = a[i];
            a[i] = a[(i - 1) / 2];
            a[(i-1)/2] = temp;
            done = false;
        }
    }
}

void Makeheap(int a[],int len)
{
    for (int i = len / 2 - 1; i >= 0;i--)
    {
        Siftdown(a, i, len);
    }
}