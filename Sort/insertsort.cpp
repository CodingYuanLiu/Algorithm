#include <iostream>
using namespace std;

void insertSort(int a[],int len)
{
    int temp;
    int j;
    for (int i = 1; i < len;i++)
    {
        temp = a[i];
        for (j = i - 1; j >= 0 && a[j]>temp;j--)
        {
            a[j + 1] = a[j];
        }
        a[j+1] = temp;//Caution! j+1 here!
    }
}