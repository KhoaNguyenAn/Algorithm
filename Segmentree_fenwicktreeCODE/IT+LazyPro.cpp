///...................................*****.................................................///
///        Author :  Ankhoa                                                                 ///
///                  Department of Computer Science                                         ///
///                  & Algorithm                                                            ///
///                  Gia Dinh high school , Vietnam.                                        ///
///...................................*****.................................................///
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
#include <stack>
using namespace std;
/*....................................Values................................................*/
#define       PI                   acos(-1)
#define       M                    1000000007
#define X first
#define Y second
#define ll long long
#define ull unsigned long long
#define ld long double
#define base 27ll
#define MAXN 1000010
#define MOD 1000000007ll
const int N = 1e5+6;
const long long INF = 1e9 + 10;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
/*....................................Functions.............................................*/
#define       sqr(x)               x*x
#define       min3(a,b,c)          min(a,min(b,c))
#define       max3(a,b,c)          max(a,max(b,c))
#define       all(v)               v.begin(), v.end()
#define       AC                   cout << "AC" << endl
#define       mem(x,y)             memset(x,y,sizeof(x))
#define       READ(f)              freopen(f, "r", stdin)
#define       WRITE(f)             freopen(f, "w", stdout)
/*.....................................Loops...............................................*/
#define       rep( i , a , b )     for( i=a ; i<b ; i++)
#define       rev( i , a , b )     for( i=a ; i>=b ; i--)
#define       repx( i ,a,b, x)     for( i=a ; i<b ; i+=x)

#define       FastRead             ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
/*..................................Shutdown..............................................*/


typedef pair <int,int> ii;
map <int,int> lua;
long long n,m,a[N],ans,j,tmp,ok1,ok2,u,v;
struct segment_tree
{
		ll mmin[4*N];
		ll add[4*N];
		void reset()
			{
					fill(mmin+1,mmin+4*N,INF);
					fill(add+1,add+4*N,0);
			}
		void build(int idx,int l,int r)
			{
			if (l==r)
			{
				mmin[idx] = a[l];
				return;
			}
			int mid = (l+r) >> 1;
			build(idx*2,l,mid);
			build(idx*2+1,mid+1,r);
			mmin[idx] = min(mmin[idx*2],mmin[idx*2+1]);
			}
		void lazy_pro(int idx,int l,int r)
		{
			if (l < r)
			{
				mmin[idx*2]-=add[idx];
				mmin[idx*2+1]-=add[idx];
				add[idx*2]-=add[idx];
				add[idx*2+1]-=add[idx];
			}
			add[idx] = 0;
		}
		void update(int idx,int l,int r,int L,int R)
		{
       lazy_pro(idx,l,r);
       if (L <= l && r <= R)
			 {
			 	  add[idx]-=1;
			 	  mmin[idx]-=1;
			 	  return;
			 }
			 int mid = (l+r) >> 1;
			 if (L > mid)
					update(idx*2+1,mid+1,r,L,R);
				else
				if (R <= mid) update(idx*2,l,mid,L,R);
			 else
			 {
			 	   update(idx*2,l,mid,L,R);
			 	   update(idx*2+1,mid+1,r,L,R);
			 }
			 mmin[idx] = min(mmin[idx*2],mmin[idx*2+1]);
		}
		ll get(int idx,int l,int r,int L,int R)
	  {
	  	 lazy_pro(idx,l,r);
	  	 if (L <= l && r <= R) return mmin[idx];
	  	 int mid = (l+r) >> 1;
	  	 if (L > mid) return get(idx*2+1,mid+1,r,L,R);
	  	 else if (R <= mid) return get(idx*2,l,mid,L,R);
	  	 return min(get(idx*2,l,mid,L,R),get(idx*2+1,mid+1,r,L,R));
	  }
	  void update_point(int idx,int l,int r,int pos,unsigned long long k)
		{
			if (l == r)
			{
			 mmin[idx] = k;
			 return;
			}
			int mid = (l+r) >> 1;
			if (pos > mid) update_point(idx*2+1,mid+1,r,pos,k);
			else update_point(idx*2,l,mid,pos,k);
			mmin[idx] = min(mmin[idx*2],mmin[idx*2+1]);
		}
};
segment_tree IT;
struct mang
{
	  int l,r,v;
};
mang b[N],c[N];
bool cmp(mang A1, mang B1)
{
	 return (A1.r < B1.r);
}
bool cmp1(mang A1,mang B1)
{
	 return (A1.l < B1.l);
}
int main()
{
	FastRead;
	cin >> n >> m; u = -INF; v = INF;
	for (int i = 1; i <= n; i++)
			cin >> a[i], u = max(u,a[i]), v = min(v,a[i]);
	if (m==0) {cout << u-v << endl , cout << 0; return 0;}
	for (int i = 1; i <= m; i++)
	{
		cin >> b[i].l >> b[i].r;
		b[i].v = i; c[i].l=b[i].l; c[i].r=b[i].r; c[i].v=b[i].v;
	}
	sort(b+1,b+m+1,cmp);
	ans = u - v; j = 1;
	IT.reset(); ok1 = 0;
	IT.build(1,1,n);
	for (int i = 1; i <= n; i++)
	{
		while (b[j].r < i && j <= m)
		{
		 IT.update(1,1,n,b[j].l,b[j].r);
		 j++;
		}
		if (i>1)
		{
		 tmp = IT.get(1,1,n,1,i-1);
		 if (a[i]-tmp > ans)
		 {
		 	  ans  = a[i]-tmp;
		 	  ok1 = j-1;
		 }
		}
	}
	sort(c+1,c+m+1,cmp1);
	IT.reset();
	IT.build(1,1,n);
	j = m;
	for (int i = n; i >= 1; i--)
	{
		 while (c[j].l > i && j >= 1)
		 {
		 	IT.update(1,1,n,c[j].l,c[j].r);
			j--;
		 }
		 if (i < n)
		 {
		 tmp = IT.get(1,1,n,i+1,n);
		 if (a[i]-tmp > ans)
		 {
			  ans = a[i]-tmp;
			  ok2 = j+1; ok1 = -1;
		 }
		 }
	}
	cout << ans << endl;
	if (ok1 != -1)
	{
		 cout << ok1 << endl;
		 for (int i = 1; i <= ok1; i++) cout << b[i].v << " ";
	}
	else
	{
		 cout << (m-ok2+1) << endl;
		 for (int j = m; j >= ok2; j--) cout << c[j].v << " ";
	}
	#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
	#endif
    return 0;
}