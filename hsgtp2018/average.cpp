///Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "average"
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
int n,k,x,b[N],pos[N],res = 0;
bool cmp(int i,int j)
{
	  return (b[i] < b[j] || (b[i] == b[j] && i < j));
}
int main()
{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		#ifdef Kaze
		 //freopen(taskname".INP","r",stdin);
		// freopen(taskname".OUT","w",stdout);
		#endif // Kaze
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
	  {
	  	  cin >> x;
	  	  b[i] = b[i-1]+x-k;
	  	  pos[i] = i;
	  }
	  sort(pos,pos+n+1,cmp);
	  for (int i = 0,j; i < n; i = j)
		 for (j = i+1; j <= n && b[pos[i]] == b[pos[j]]; j++)
		   res = max(res,pos[j]-pos[i]);
		cout << res;
		return 0;
}
/**Code written by AnkhoaGD**/