#include <iostream>
using namespace std;
int EXP(int x, int n);
int main()
{
    int x, n;
    while(1)
    {
        cout << "x:";
        cin >> x;
        cout << "n:";
        cin >> n;
        cout << "x^n = " << EXP(x, n) << endl;
    }
}
int EXP(int x, int n)
{
    int result = 1;
    if(n == 0)
        return 1;
    result = EXP(x, n / 2);
    result = result * result;
    if(n%2 == 1)
        result = result * x;
    return result;
}