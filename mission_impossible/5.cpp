#include <stdio.h>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stack>
#define ll long long
#define X first
#define Y second
using namespace std;
const int N = 1e5+1;
typedef pair <int,int> ii;
stack <ii> stk;
ii tmp;
stack <int> res;
int it[4*N],sz,x,y,z,q,u;
void update(int idx,int l,int r,int pos,int val)
{
		if (l==r)
		{
			 it[idx] = val;
			 return;
		}
		int mid = (l+r) >> 1;
		if (pos > mid) update(idx*2+1,mid+1,r,pos,val);
		else update(idx*2,l,mid,pos,val);
		it[idx] = __gcd(it[idx*2],it[idx*2+1]);
}
int get(int idx,int l,int r,int L,int R, int t)
{
		if (L <= l && r <= R) return it[idx];
		int mid = (l+r) >> 1;
		if (L > mid) return get(idx*2+1,mid+1,r,L,R);
		else if (R <= mid) return get(idx*2,l,mid,L,R);
		if (t==2) return __gcd(get(idx*2+1,mid+1,r,L,R),get(idx*2,l,mid,L,R));
		else return __lcm(get(idx*2+1,mid+1,r,L,R),get(idx*2,l,mid,L,R));
}
int main()
{
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		freopen("abc.INP","r",stdin);
		freopen("abc.OUT","w",stdout);
		cin >> q;
		sz = 0;
		while (q--)
		{
				cin >> x;
				if (x == 0)
				{
					cin >> y;
					sz++;
					update(1,1,N,sz,y);
					stk.push(ii(0,y));
					res.push(y);
				}
				else
				if (x == 1)
				{
					sz--;
					stk.push(ii(1,res.top()));
					res.pop();
				}
				else
				if (x == 2)
				{
					cin >> y >> z;
					cout << get(1,1,N,y,z) << "\n";
				}
				else
				if (x == 3)
				{
					/*if (!stk.empty())
					{
					tmp = stk.top();
					stk.pop();
					if (tmp.X == 0)
					{
						sz--;
						res.pop();
					}
					else
					{
						sz++;
						res.push(tmp.Y);
						update(1,1,N,sz,tmp.Y);
					}
					}*/
					cin >> y >> z;
				}
		}
		return 0;
}