#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <cmath>
#include <sstream>
#include <set>
#include <list>
#include <map>
#include <cstdlib>
#include <stack>
#define X first
#define Y second
#define ll long long
#define ull unsigned long long
#define ld long double
#define MAXN 1000010
#define MOD 1000000007ll
using namespace std;
const int N = 6*1e5+5;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
typedef pair <int,int> ii;
inline ld sqr(ld a) {return a*a;}
void build(int idx,int l, int r)
{
    if (l==r)
    {
        mmax[idx] = a[l];
        return;
    }
    int mid = (l+r) / 2;
    build(idx*2,l,mid);
    build(idx*2+1,mid+1,r);
    mmax[idx] = max(mmax[idx*2],mmax[idx*2+1]);
}
int get(int idx,int l,int r,int L,int R)
{
    if ((L<=l)&&(r<=R)) return mmax[idx];
    int mid = (l+r) / 2;
    if (L > mid) return get(idx*2+1,mid+1,r,L,R);
    else
    if (R <= mid) return get(idx*2,l,mid,L,R);
    return max(get(idx*2,l,mid,L,R),get(idx*2+1,mid+1,r,L,R));
}
ll cal(ll k,ll l,ll r)
{
   while (l <= r)
	 {
	 	  int mid = (l+r) >> 1;
	 	  if (get(1,1,n,l,mid) <= k)
			{

			}
	 }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SHOPPING.INP","r",stdin);
    freopen("SHOPPING.OUT","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
			 cin >> a[i];
		build(1,1,n);
		for (int i = 1; i <= m; i++)
		{
			 cin >> t >> u >> v;
			 cout << cal(t,u,v) << endl;
		}
    return 0;
}