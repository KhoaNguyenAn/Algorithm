#include <bits/stdc++.h>
#include <iostream>
#define taskname "RECTMAKE"
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
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
ll n,m,ans,d[N];
queue <int> que;
struct mang
{
	 int x,y;
};
mang a[N];
bool cmp(mang A1,mang B1)
{
	 return ((A1.y < B1.y) || (A1.y == B1.y && A1.x < B1.x));
}
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		//freopen(taskname".INP","r",stdin);
		//freopen(taskname".OUT","w",stdout);
    cin >> n;
    h1 = -INF;
    h2 = INF;
    for (int i = 1; i <= n; i++)
			 cin >> a[i].x >> a[i].y;
		sort(a+1,a+n+1,cmp);
		a[0].x = -1;
		a[0].y = -1;
		int i = 1;
		while (true)
	  {
	  	sl1 = 1;
	  	while (a[i].y == a[i-1].y && i <= n)
			{
				 sl1++;
				 if (h[a[i].x] != 0)
				 {
           if (d[])
				 }
				 i++;
			}
		return 0;

}



