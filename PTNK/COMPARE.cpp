#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
const int N = 1e5+7;
int n,f[N],sl,mmin,vt,res[N],lua[N],top;
string st;
char tmp;

void dfs()
{

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("COMPARE.INP","r",stdin);
    freopen("COMPARE.OUT","w",stdout);
    cin >> n;
    cin >> st;
    f[0] = 0;
    st = '!' + st;
    for (int i = 1 ; i <= n-1; i++)
    {
        tmp = st[i];
        sl++;
        if (tmp == '<')
        {
           f[i] = f[i-1] + 1;
        }
        else
        {
            f[i] = f[i-1] - 1;
        }
    }
    mmin = 1000;
    vt = 1000;
    for (int i = 1; i <= n-1 ; i++)
    {
        if (mmin > f[i])
        {
            mmin = f[i];
            vt = i;
        }
    }
    res[vt] = 1;
    memset(lua,false,sizeof(lua));
    top = 1;
    lua[top] = true;
    top--;
    for (int i = vt-1; i >= 1; i--)
    {
      if (f[i] < f[i+1])
      {
        while (lua[top] == true) top--;
        lua[top] = true;
        res[i] = top;
      }
      else
      {
        while (lua[top] == true) top++;
        lua[top] = true;
        res[i] = top;
      }
    }
    for (int i = vt+1; i <= n ; i++)
    {
        if (f[i] < f[i-1])
        {
            while (lua[top] == true) top++;
            res[i] = top;
        }
        else
        {
            while (lua[top] == true) top--;
            lua[top] = true;
            res[i] = top;
        }
    }
    for (int i = 1; i <= n ; i++) cout << res[i] << " ";
    return 0;
}
