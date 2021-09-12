///Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "NAME"
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
struct mang
{
	  int v,c,p;
};
mang a[N];
bool cmp(mang A1,mang B1)
{

}
int main()
{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		#ifndef Kaze
		 ///freopen(taskname".INP","r",stdin);
		 ///freopen(taskname".OUT","w",stdout);
		#endif // Kaze
		cin >> n >> v0;
		for (int i = 1 ; i <= n; i++)
			 cin >> a[i].v >> a[i].c >> a[i].p;
		sort(a+1,a+n,cmp);
		return 0;
}
/**Code written by AnkhoaGD**/