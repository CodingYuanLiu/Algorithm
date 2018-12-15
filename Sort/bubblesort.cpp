void bubblesort(int a[],int n)
{
    int t;
    for (int i = 0; i < n - 1;i++)
    {
        for (int j = n - 2; j >= i;j--)
        {
            if(a[j]>a[j+1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}
