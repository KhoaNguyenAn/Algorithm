#include <bits/stdc++.h>
#include <iostream>
#define taskname "PLAY"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 500 + 5;
const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
struct mang
{
	 int cnt,val;
};
mang a[N];
long long dp[500][500];
int n,dem,sl,memo[500][500],k,b[N];
long long cal(int L,int R)
{
	 if (L > R) return 0;
	 if (L == R)
	  if (a[L].cnt >= k) return 0;
				else return (k-a[L].cnt);
	 if (memo[L][R] == 1) return dp[L][R];
	 memo[L][R] = 1;
	 dp[L][R] = INF;
	 int tmp;
	 if (a[L].cnt+a[R].cnt >= k) tmp = k; else tmp = a[L].cnt+a[R].cnt;
	 if (a[L].val == a[R].val) dp[L][R] = cal(L+1,R-1)+(k-tmp);
	 for (int i = L; i <= R; i++)
	 {
	 	  int tmp1 = a[L].cnt+a[R].cnt+a[i].cnt;
	 	  if (tmp1 >=k) tmp1 = k;
			if (a[i].val == a[L].val && a[i].val == a[R].val && i != L && i != R)
				dp[L][R] = min(dp[L][R],cal(L+1,i-1)+cal(i+1,R-1)+k-tmp1);
			else
				dp[L][R] = min(dp[L][R],cal(L,i)+cal(i+1,R));
	 }
	 for (int i = L; i <= R; i++)
	 if (cnt)
	 return dp[L][R];
}
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		//freopen("taskname".INP","r",stdin);
		//freopen("taskname".OUT","w",stdout);
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			cin >> b[i];
		dem = 1;
		sl = 0;
		for (int i = 2; i <= n+1; i++)
		if (b[i] != b[i-1])
		{
			  sl++;
				a[sl].val = b[i-1];
				a[sl].cnt = dem;
				dem = 1;
	  } else dem++;
		cout << cal(1,7);
	  return 0;
}
//9 5
//1 2 1 3 1 4 1 5 1


