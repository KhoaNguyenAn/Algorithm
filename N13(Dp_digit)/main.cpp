//Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "N13"
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
long long f[20][10][2],n,A,B;
string st;
long long cal(int i,int cur,int ok)
{
	 if (i == n) return 1;
	 long long &res = f[i][cur][ok];
	 if (res != -1) return f[i][cur][ok];
	 res = 0;
	 if (ok)
	 {
	   for (int suf = 0; suf <= 9; suf++)
		 if (cur == 1 && suf == 3) continue;
			else res+= cal(i+1,suf,1);
	 }
	 else
	 {
		 for (int suf = 0; suf < int(st[i]-48); suf++)
		 if (cur == 1 && suf == 3) continue; else
		   res+= cal(i+1,suf,1);
		 if (cur == 1 && int(st[i]-48) == 3) return res;
		 res+=cal(i+1,int(st[i]-48),0);
	 }
	 return res;
}
long long solve(long long x)
{
	  st = "";
	  while (x != 0)
		{
			 st = char((x % 10) + 48) + st;
			 x/=10;
		}
	  n = st.size();
	  memset(f,-1,sizeof f);
	  return cal(0,0,0);
}
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		freopen(taskname".INP","r",stdin);
		//freopen(taskname".OUT","w",stdout);
		while (cin >> A >> B)
			 cout << solve(B)-solve(A-1) << endl;
		return 0;
}
/**Code written by AnkhoaGD**/


