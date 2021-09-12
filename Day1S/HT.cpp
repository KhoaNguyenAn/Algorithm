#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
string s;
int n,res[100];
string cur[10];

bool check(int num,int i1)
{
    if (s[i1] == cur[num][0] && s[i1+1] == cur[num][1] && s[i1+2] == cur[num][2]) return true; else return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("HT.INP","r",stdin);
    freopen("HT.OUT","w",stdout);
    cin >> s;
    cur[1] = "TTT";
    cur[2] = "TTH";
    cur[3] = "THT";
    cur[4] = "THH";
    cur[5] = "HTT";
    cur[6] = "HTH";
    cur[7] = "HHT";
    cur[8] = "HHH";
    n = s.size();
    memset(res,0,sizeof(res));
    for (int i = 0; i < n-2 ; i++)
      for (int j = 1; j <= 8; j++)
        if (check(j,i)==true) res[j]++;
    for (int i = 1; i <= 8; i++) cout << res[i] << " ";
    return 0;
}
