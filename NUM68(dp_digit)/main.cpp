//Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "NUM68"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 2e6 + 5;
const ll INF = 1e9 + 10;
const ll INF64 = 1e18;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
long long f[20][2][2],m;
string n;
long long cal(int i,int memo,int ok)
{
	 if (i == m) return ((memo == 0) && (ok == 1));
	 long long &res = f[i][memo][ok];
	 if (res != -1) return f[i][memo][ok];
	 res = 0;
	 for (int a = 0; a <= 9; a++)
		for (int b = 0; b <= 9; b++)
		  if ((a+b+memo)%10 == int(n[i]-48))
		    res+= cal(i+1,((a+b+memo)>=10),ok|(a==6)|(a==8)|(b==6)|(b==8));
	  return res;
}
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		freopen(taskname".INP","r",stdin);
		//freopen(taskname".OUT","w",stdout);
		while (cin >> n)
		{
			 memset(f,-1,sizeof f);
			 m = n.size();
			 reverse(n.begin(),n.end());
			 long long ans = cal(0,0,0);
			 if (ans % 2) cout << (ans/2)+1 << endl;
					else cout << (ans/2) << endl;
		}
		return 0;
}
/**Code written by AnkhoaGD**/


