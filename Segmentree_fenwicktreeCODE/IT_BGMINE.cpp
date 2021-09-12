#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>\
#include <vector>
using namespace std;
const int N = 5*(1e5+10);
const int INF = 1e9 + 7;
struct mang
{
		int x,g,r;
};
mang a[N];
long long n,c[N],cur[N],pg[N],pr[N],sl,vt,vt1,ans = 0,IT[N];
void update(int idx,int l ,int r,int pos, long long val)
{
		if (l==r)
		{
			IT[idx] = min(IT[idx],val);
			return;
		}
		int mid = (l+r) >> 1;
		if (pos > mid) update(idx*2+1,mid+1,r,pos,val);
		else update(idx*2,l,mid,pos,val);
		IT[idx] = min(IT[idx*2],IT[idx*2+1]);
}
long long get(int idx,int l,int r,int L,int R)
{
		if (l >= L && r <= R) return IT[idx];
		int mid = (l+r) >> 1;
		if (L > mid) return get(idx*2+1,mid+1,r,L,R);
		else if (R <= mid) return get(idx*2,l,mid,L,R);
		return min(get(idx*2,l,mid,L,R),get(idx*2+1,mid+1,r,L,R));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
		{
			cin >> a[i].x >> a[i].g >> a[i].r;
			pg[i] = pg[i-1]+a[i].g;
			pr[i] = pr[i-1]+a[i].r;
			cur[i] = pr[i-1]-a[i].x;
		}
		fill(c,c+N,INF);
		fill(IT,IT+N,INF);
		sort(cur+1,cur+n+1);
		c[1] = cur[1];
		sl = 1;
		pr[0] = 0;
		for (int i = 2; i <= n; i++)
		if (cur[i]!=cur[i-1]) c[++sl] = cur[i];
		for (int i = 1; i <= n; i++) ans = max(ans,1LL*a[i].g);
		for (int i = 1; i <= n; i++)
		{
			 vt = (lower_bound(c+1,c+sl+1,pr[i-1]-a[i].x)-c);
			 update(1,1,sl,vt,pg[i-1]);
			 vt1 = (upper_bound(c+1,c+sl+1,pr[i]-a[i].x)-c) - 1;
			 ans = max(ans,pg[i]-get(1,1,sl,1,vt1));
		}
		cout << ans << endl;
    return 0;
}