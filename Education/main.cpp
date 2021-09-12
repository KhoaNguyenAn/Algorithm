#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <string>
using namespace std;
string a,b,ans;
int f[100];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ans = "";
    cin >> a >> b;
    int sl = 0;
    if (a.length() < b.length())
    {
        for (int i = 9; i >= 0; i++)
           for (int j = 0; j < a.length();j++)
              {
                  int tam = int(a[j]);
                  if (tam == i)
                  {
                    sl++;
                    f[sl] = i;
                  }
              }
         for (int i = 1; i <= sl; i++) cout << f[i];
         exit(0);
    }
    if (a.length() == b.length())
    {

    }
}
