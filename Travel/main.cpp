#include <iostream>

using namespace std;
int n,s,tong,f[100],a[100];
int main()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        tong+=tong + a[i];
    }
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = tong - a[i]; j >= 0; j--)
            if (f[j] > 0)
            {
                f[j+a[i]]+=f[j];
                sl++;
            }

    cout << f[s];
}
