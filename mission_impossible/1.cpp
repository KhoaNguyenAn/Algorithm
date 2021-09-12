#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>
using namespace std;
string st;
unsigned long long n,x,s,ans,x1,x2,ss;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("abc.inp","r",stdin);
		while (getline(cin,st))
		{
			stringstream stream(st);
			stream >> x1;
			stream >> x2;
			x = x1;
			ss = 0;
			while (x1 != 0)
			{
				x1 = x1 / 10;
				ss++;
			}
			if (st.size() == ss) ans = x % 3;
			else
			{
			if (x % 3 == 1) ans = 1;else
			if (x % 3 == 0) ans = 0;
			else
			{
				if (x2 & 1) ans = 2; else ans = 1;
			}
			}
			if (ans == 0) cout << "Y \n";
			if (ans == 1) cout << "E \n";
			if (ans == 2) cout << "S \n";
		}
		return 0;
}
