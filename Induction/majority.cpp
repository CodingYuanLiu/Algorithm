#include <iostream>
using namespace std;
int majority(int a[], int len);
int candidate(int a[], int m, int len);
int candidate_iter(int a[], int len);
int main()
{
    int a[12] = { 1, 2, 3, 3, 2, 3, 1, 3, 6, 3, 3, 3};
    cout << majority(a, 13);
}

int majority(int a[],int len)
{
    int c = candidate_iter(a, len);
    int count = 0;
    for (int i = 0; i < len;i++)
    {
        if(a[i] == c)
        {
            count++;
        }
    }
    if(count > len/2)
    {
        return c;
    }
    
    else
    {
        return 0;
    }
    
}

int candidate(int a[],int m,int len)
{
    int count = 1, j = m , c = a[m];
    while (j<len - 1 && count>0) 
    {
        j++;
        if(a[j] == c)
            count++;
        else
        {
            count--;
        }
        if(count == 0)
            break;
    }

    if(j == len-1) 
        return c;
    
    else
    {
        return candidate(a,j + 1,len);
    }   
}

int candidate_iter(int a[],int len)
{
    int count = 1;
    int j = 0;
    int c = a[j];
    while(j<len-1)
    {
        while(j<len-1 && count != 0)
        {
            j++;
            if(a[j] == c)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        if(j!=len-1)
        {
            c = a[j];
            count = 1;
        }
        
        else
        {
            return c;
        }
    }
}