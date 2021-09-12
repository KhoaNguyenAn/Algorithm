///Kaze
#include <iostream>
#include <stdio.h>
#include <deque>
#include <queue>
#include <algorithm>
#define taskname "HSG"
#define Eureka cerr << "Eureka"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 2e5 + 7;
const ll INF = 1e9 + 10;
const ll INF64 = 1e18;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
int n,k,b,d[2002][2002],c[2002];
struct mang
{
	  int vt,sum,sl;
};
mang a[2002];
bool cmp(mang A1,mang B1)
{
	 if (A1.sum > B1.sum) return true;
	 if (A1.sum == B1.sum && A1.sl > B1.sl) return true;
	 if (A1.sum == B1.sum && A1.sl == B1.sl && A1.vt < B1.vt) return true;
	 return false;
}
int main()
{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		#ifndef Kaze
		 freopen(taskname".INP","r",stdin);
		 freopen(taskname".OUT","w",stdout);
		#endif // Kaze
		cin >> n >> k >> b;
		for (int i = 1; i <= n; i++)
		{
			 a[i].vt = i;
			 for (int j = 1 ; j <= k; j++)
			 {
			 	  cin >> d[i][j];
			 	  if (d[i][j] == 1) a[i].sl++;
			 	  else c[j]++;
			 }
		}
		for (int i = 1; i <= n; i++)
		 for (int j = 1; j <= k; j++)
		   if (d[i][j] == 1) a[i].sum+=c[j];
		sort(a+1,a+n+1,cmp);
		for (int i = 1; i <= n; i++)
	   if (a[i].vt == b)
		 {
				cout << i;
		 	  return 0;
		 }
		return 0;
}
/**Code written by AnkhoaGD**/