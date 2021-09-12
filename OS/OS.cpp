#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int INF = 1e9 + 7;
const int N = 5*(1e5+10);
long long n,m,b[4*N],add[4*N],c[N],s[N],k,sl,sl1,ll,rr,sum;
struct mang
{
	 int l,r;
};
mang a[N];
void lazy_pro(int idx,int l,int r)
    {
        if (l < r)
        {
            b[idx*2]+=add[idx];
            b[idx*2+1]+=add[idx];
            add[idx*2]+=add[idx];
            add[idx*2+1]+=add[idx];
        }
        add[idx] = 0;
    }
void update(int idx,int l,int r,int L,int R,int val)
    {
       lazy_pro(idx,l,r);
       if ((L <= l)&&(r<=R))
       {
          add[idx] += val;
          b[idx]+=val;
          return;
       }
       int mid = (l+r)/2;
       if (L > mid)
           update(idx*2+1,mid+1,r,L,R,val);
       else
       if (R <= mid) update(idx*2,l,mid,L,R,val);
       else
       {
           update(idx*2+1,mid+1,r,L,R,val);
           update(idx*2,l,mid,L,R,val);
       }
       b[idx] = max(b[idx*2],b[idx*2+1]);
    }
long long get(int idx,int l,int r,int L,int R)
    {
        lazy_pro(idx,l,r);
        if ((L<=l)&&(r<=R)) return b[idx];
        int mid = (l+r) / 2;
        if (L > mid) return get(idx*2+1,mid+1,r,L,R);
        else if (R <= mid) return get(idx*2,l,mid,L,R);
        return max(get(idx*2+1,mid+1,r,L,R),get(idx*2,l,mid,L,R));
    }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("OS.INP","r",stdin);
    freopen("OS.OUT","w",stdout);
    cin >> n >> k;
    sl = 0;
    fill(c,c+N,INF);
		fill(b,b+N,0);
		fill(s,s+N,INF);
		fill(add,add+N,0);
		for (int i = 1; i <= k;i++)
		{
				cin >> a[i].l >> a[i].r;
				s[++sl] = a[i].l;
				s[++sl] = a[i].r;
		}
		sort(s+1,s+sl+1);
		sl1 = 1;
		c[1] = s[1];
		for (int i = 2; i <= sl; i++)
		 if (s[i]!=s[i-1]) c[++sl1]=s[i];
		for (int i = 1; i <= k; i++)
		{
				ll = (lower_bound(c+1,c+sl1+1,a[i].l)-c);
				rr = (lower_bound(c+1,c+sl1+1,a[i].r)-c);
				if (a[i].l > 1e9 || a[i].r > 1e9 || a[i].l > n || a[i].r > n)
				{
					  cout << --i;
					  return 0;
				}
				sum = get(1,1,sl1,ll,rr);
				if (sum != 0)
				{
						cout << --i;
						return 0;
				}
				update(1,1,sl1,ll,rr,1);
		}
		cout << k;
    return 0;
}
