#include <iostream>
using namespace std;
int bsearch(int a[], int i,int len);
int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i;
    cout << "search:";
    cin >> i;
    cout << bsearch(a, i, 10);
}

int bsearch(int a[],int i,int len)
{
    int hi = len - 1;
    int lo = 0;
    int mid;
    while(lo<=hi)
    {
        mid = (hi + lo) / 2;
        if(a[mid] == i)
        {
            return mid;
        }
        else if(a[mid]<i)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return -1;
}