#include <iostream>
#include <stdio.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;
double n,m;
int k,res,n1;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DIGIT.INP","r",stdin);
    freopen("DIGIT.OUT","w",stdout);
    cin >> n >> m >> k;
    double tmp = n / m;
   	string s = tostr(tmp);
   	n1 = s.size();
   	//for (int i = 0; i < n1; i++) cout << s[i];
   	for (int i = 0; i < n1; i++)
    if (s[i] == '.')
    {
        res = i;break;
    }
    if (k > n1-res) cout << 0; else cout << s[res+k];


    return 0;
}
