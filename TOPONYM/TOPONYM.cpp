#include <iostream>
#include <stdio.h>
#include <string>
#include <bits/stdc++.h>
#define INF 99999999
using namespace std;
const int N = 1e6+5;
string st[N];
int n,f1[N],s[N],top,l[N],r[N],res;
int chk(int m1, int m2)
{
    int n1 = st[m1].size();
    int n2 = st[m2].size();
    int len = min(n1,n2);
    int dem = 0;
    for (int ii = 0; ii < len ; ii++)
    {
        if (st[m1][ii] == st[m2][ii]) dem++; else break;
    }
    return dem;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TOPONYM.INP","r",stdin);
    freopen("TOPONYM.OUT","w",stdout);
    cin >> n;
    string tmp;
    getline(cin,tmp);
    for (int i = 1; i <= n; i++)
    {
        getline(cin,tmp);
        st[i] = tmp;
    }
    sort(st+1,st+n+1);
    f1[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        f1[i] = chk(i,i-1);
    }
    int top = 0;
    s[0] = 0;
    for (int i = 1; i <= n+1; i++){
        while (top > 0 && f1[i] < f1[s[top]]) r[s[top--]] = i;// khong can top>0 vi s[0] = 0, a[0] = -oo
        l[i] = s[top];
        s[++top] = i;
    }
    for (int i = 2; i <= n ; i++)
        res = max(res,(r[i]-l[i])*f1[i]);
    cout << res;
    return 0;
}
