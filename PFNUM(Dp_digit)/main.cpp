//Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "PFNUM"
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
long long f[20][2][2][15][15],m,A,B;
string st;
long long cal(int i,int ok,int isMean,int pre1,int pre2)
{
	 if (i == m) return 1;
	 long long &res = f[i][ok][isMean][pre1][pre2];
	 if (res != -1) return f[i][ok][isMean][pre1][pre2];
	 res = 0;
	 if (ok)
	 {
			for (int k = 0; k <= 9; k++)
			if (k == pre1 || k == pre2) continue;
			else
			res+=cal(i+1,1,(k > 0||isMean),(isMean||k > 0) ? k : 11,pre1);
	 }
	 else
	 {
	 	  for (int k = 0; k < int(st[i]-48); k++)
			if (k == pre1 || k == pre2) continue;
			else
	    res+=cal(i+1,1,(k > 0||isMean),(isMean||k > 0) ? k : 11,pre1);
			int k = int(st[i]-48);
			if (k == pre1 || k == pre2) return res;
			res+=cal(i+1,0,(k > 0||isMean),(isMean||k > 0) ? k : 11,pre1);
	 }
	 return res;
}
long long solve(long long x)
{
	 st = "";
	 while (x != 0)
	 {
	 	 st = char(x%10+48)+st;
	 	 x/=10;
	 }
	 m = st.size();
	 memset(f,-1,sizeof f);
	 return cal(0,0,0,11,11);
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
