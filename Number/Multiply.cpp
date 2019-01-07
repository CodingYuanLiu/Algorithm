#include <iostream>
using namespace std;
struct res{
    int q;
    int r;
};

int multiply(int a, int b);
int Exp(int a, int b);
res divide(int a, int b);

int main()
{
    int a(0),b(0);
    cout << "a = -1 to quit" << endl;
    while(true)
    {
        cout << "a:";
        cin >> a;
        if(a<0)
            break;
        cout << "b:";
        cin >> b;
        cout << "a*b:" << multiply(a, b) << endl;
        cout << "a^b:" << Exp(a, b) << endl;
        res result = divide(a, b);
        cout << "a/b,q:" << result.q << ",r:"<<result.r<<endl;
    }
    return 0;
}

int multiply(int a,int b)
{
    if( b == 0)
        return 0;
    int result = multiply(a, b / 2);
    result = result * 2;
    if(b%2 == 1)
        result += a;
    return result;
}

int Exp(int a,int b)
{
    if(b == 0)
        return 1;
    int result = Exp(a, b / 2);
    result = result * result;
    if(b%2 == 1)
    {
        result *= a;
    }
    return result;
}

res divide(int a,int b)
{
    res result;
    result.q = 0;
    result.r = 0;
    if(a == 0)
        return result;
    result = divide(a / 2, b);
    result.q *= 2;
    result.r *= 2;  
    if(a%2 == 1)
        result.r++;
    if(result.r>=b)
    {
        result.r -= b;
        result.q++;
    }
    return result;
}