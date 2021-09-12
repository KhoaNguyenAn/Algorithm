#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> m >> n;
        f[0] = 1;
        for (int j = 1; j <= n; j++)
           f[j] = (f[j-1]*10)%m;
        if (!(n & 1))
        {
           int x = 1;
           for (int i = 1; i <= (n >> 1); i++)
           for (int j = 0; j <= m - 1; j++)
           for (int k = 1; k <= 9; k++)
           {


           }
        }
    }
    return 0;
}
