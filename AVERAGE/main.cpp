#include <iostream>

using namespace std;
int a , b , c , x , y, x1 ,y1 , s;
int main()
{
    cin >> a >> b >> c;
    if (b > a) swap(b,a);
    if (a > c && c > b)
    {
    x = a - c;
    y = -b + c;
    x1 = x;
    y1 = y;
    while (x != y)
    {
        if (x > y) x = x - y; else y = y - x;
    }
    s = x1 * y1 / x;
    x = s / (a-c);
    y = s / (-b+c);
    cout << (x-1) + (y-1);
    }
    else cout << -1;
    return 0;
}
