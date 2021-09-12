#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <math.h>
using namespace std;
int n,kt[int(1e5)+11],l,r,b[int(1e5)+11],c[int(1e5)+11];

void sang()
{
    fill(kt+1,kt+100007,true);
    kt[1] = false;
    for (int i = 2; i <= sqrt(int(1e5)+7) ; i++)
       if (kt[i] == true)
       for (int j = 2; j <= int ((int(1e5)+7) / i); j++)
        {
            kt[i*j] = false;
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    sang();
    int tam = 0;
    for (int i = 2; i <= int(1e5)+7; i++)
    {
        if (kt[i] == true && (i+1) % 2 == 0 && kt[(i+1) / 2] == true) tam++;
        c[i] = tam;
    }

    for (int i = 1; i <= n; i++)
    {
      cin >> l >> r;
      b[i] = c[r] - c[l-1];
    }
    for (int i = 1 ; i <= n; i++)
        cout << b[i] << "\n";
}
