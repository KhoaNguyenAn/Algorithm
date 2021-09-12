#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2*1e5+2;
ll n,m,u,v,c,d;
struct segment_tree
{
    ll b[N];
    ll add[N];
    void reset()
    {
        fill(b+1,b+N,0);
        fill(add+1,add+N,0);
        fill(mult+1,mult+N,1);
    }
    void lazy_pro(int idx,int l,int r,char kt)
    {
        if (l < r)
        {
           if (kt == 0)
           {
            b[idx*2]+=add[idx];
            b[idx*2+1]+=add[idx];
            add[idx*2]+=add[idx];
            add[idx*2+1]+=add[idx];
           }
           else
           {
            b[idx*2]*=mult[idx];
            b[idx*2+1]*=mult[idx];
            add[idx*2]*=mult[idx];
            add[idx*2+1]*=mult[idx];
           }
        }
        add[idx] = 0;
    }
    void update(int idx,int l,int r,int L,int R,ll val,char kt)
    {
       lazy_pro(idx,l,r,kt);
       if ((L <= l)&&(r<=R))
       {
          if (kt == 0)
          {
           add[idx] += val;
           b[idx]+=val;
           return;
          }
          else
          {
            mult[idx] *= val;
            b[idx] *= val;
            return;
          }
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
    ll get(int idx,int l,int r,int L,int R)
    {
        lazy_pro(idx,l,r);
        if ((L<=l)&&(r<=R)) return b[idx];
        int mid = (l+r) / 2;
        if (L > mid) return get(idx*2+1,mid+1,r,L,R);
        else if (R <= mid) return get(idx*2,l,mid,L,R);
        return max(get(idx*2+1,mid+1,r,L,R),get(idx*2,l,mid,L,R));
    }
};
segment_tree a;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    a.reset();
    for (int i = 1; i <= m; i++)
    {
        cin >> u;
        if (u == 0)
        {
            cin >> v >> c >> d;
            a.update(1,1,n,v,c,d,0);
        }
        else
        if (u == 2)
        {
            cin >> v >> c;
            cout << a.get(1,1,n,v,c) << "\n";
        }
        else
        {
            cin >> v >> c >> d;
            cout << a.update(1,1,n,v,c,d,1);
        }
    }
    return 0;
}
