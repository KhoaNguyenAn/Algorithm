#include <iostream>

using namespace std;

int pow(int a, int n)
{
    if (n == 1) return a;
    else
    {
        int tmp = pow(a,n/2);
        if (n % 2 == 0) return tmp*tmp; else return tmp*tmp*a;
    }
}
int main()
{
    int n,k;
    cin >> n >> k;
    cout << pow(n,k);
}
