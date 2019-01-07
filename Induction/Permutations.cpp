#include <iostream>
using namespace std;
void perm1(int a[], int m,int len);
void perm2(int a[], int m,int len);
void print(int a[], int len);
int main()
{
    int a[4]={1,2,3,4};
    //perm1(a, 0,4);
    int b[4] = {};
    perm2(b, 1, 4);
    return 0;
}

void print(int a[], int len)
{
    for (int i = 0; i < len;i++)
    {
        cout << a[i];
    }
    cout << endl;
}

void perm1(int a[],int m,int len)
{
    if(m == len-1)
    {
        print(a, len);
        return;
    }
    int temp;
    for (int j = m; j < len;j++)
    {
        temp = a[m];
        a[m] = a[j];
        a[j] = temp;
        perm1(a, m + 1, len);
        temp = a[m];
        a[m] = a[j];
        a[j] = temp;
    }
}

void perm2(int a[],int m,int len)
{
    if(m == len+1)
    {
        print(a, len);
        return;
    }
    
    else
    {
        for (int j = 0; j < len;j++)
        {
            if(a[j] == 0)
            {
                a[j] = m;
                perm2(a,m + 1,len);
                a[j] = 0;
            }
        }
    }
    
}