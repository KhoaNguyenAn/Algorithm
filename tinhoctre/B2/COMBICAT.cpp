#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int N = 5e5+6;
const int INF = 1e9+4;
map<int,int> cnt;
int n,m;
string st,s,tmp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> st;
    cin >> m;
    cin >> s;
    if (st == s)
    {
         cout << "Paradox";
         return 0;
    }
    for (int i = 0; i < n; i++)
    {
       tmp = "";
			 tmp = st.substr(i,s.size());
			 //cout << tmp << endl;
       if (tmp == s)
       {
           for (int k = 0; k < i; k++) cout << st[k];
           for (int k = i+s.size(); k < st.size();k++) cout << st[k];
           return 0;
       }
    }
    return 0;
}