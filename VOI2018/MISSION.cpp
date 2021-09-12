#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 1e5 +2;
const int INF = 1e9 + 7;
ll n,b[N],c[N],sl,f[N],IT[4*N],ans;
struct mang
{
	 int l,r,x;
};
mang a[N];
bool cmp1(mang A1,mang B1)
{
	return (A1.l < B1.r);
}
void update(int idx,int l ,int r,int pos, long long val)
{
		if (l==r)
		{
			IT[idx] = max(IT[idx],val);
			return;
		}
		int mid = (l+r) >> 1;
		if (pos > mid) update(idx*2+1,mid+1,r,pos,val);
		else update(idx*2,l,mid,pos,val);
		IT[idx] = max(IT[idx*2],IT[idx*2+1]);
}
long long get(int idx,int l,int r,int L,int R)
{
		if (l >= L && r <= R) return IT[idx];
		int mid = (l+r) >> 1;
		if (L > mid) return get(idx*2+1,mid+1,r,L,R);
		else if (R <= mid) return get(idx*2,l,mid,L,R);
		return max(get(idx*2,l,mid,L,R),get(idx*2+1,mid+1,r,L,R));
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("MISSION.INP","r",stdin);
	freopen("MISSION.OUT","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].l >> a[i].r >> a[i].x;
		b[i] = a[i].r;
	}
	sort(a+1,a+n+1,cmp1);
	sort(b+1,b+n+1);
	fill(c,c+N,INF);
	fill(IT,IT+4*N+1,0);
	c[1] = b[1];
	sl = 1;
	ans = 0;
	for (int i = 2; i <= n; i++)
	if (b[i]!=b[i-1]) c[++sl] = b[i];
	for (int i = 1; i <= n; i++)
	{
		int vt = (lower_bound(c+1,c+sl+1,a[i].r)-c);
		int vt1 = (upper_bound(c+1,c+sl+1,a[i].l)-c)-1;
		if (c[vt1]==a[i].l) vt1--;
		f[i] = get(1,0,sl,0,vt1) + a[i].x;
		ans = max(ans,f[i]);
		update(1,0,sl,vt,f[i]);
	}
	cout << ans;
	return 0;
}