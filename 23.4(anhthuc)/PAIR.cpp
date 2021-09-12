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
const int INF = 1e9 + 10;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
/*....................................Functions.............................................*/
#define       sqr(x)               x*x
#define       min3(a,b,c)          min(a,min(b,c))
#define       max3(a,b,c)          max(a,max(b,c))
#define       all(v)               v.begin(), v.end()
#define       ok                   cout << "ok" << endl
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
vector <int> a[N];
ll b[4*N],ans,k,n,c[N],u,v;
bool seen[N];
void update(int idx,int l,int r,int pos,int val)
		{
      if (l == r)
      {
          b[idx]+=val;
          return;
      }
      ll mid = (l+r) / 2;
      if (pos > mid) update(idx*2+1,mid+1,r,pos,val);
      else update(idx*2,l,mid,pos,val);
      b[idx] = b[idx*2] + b[idx*2+1];
    }
ll get(int idx,int l,int r,int L,int R)
		{
        if ((L<=l)&&(r<=R)) return b[idx];
        int mid = (l+r) / 2;
        if (L > mid) return get(idx*2+1,mid+1,r,L,R);
        else if (R <= mid) return get(idx*2,l,mid,L,R);
        return (get(idx*2+1,mid+1,r,L,R) + get(idx*2,l,mid,L,R));
    }
void dfs(int u)
{
	 seen[u] = true;
	 for (int o = 0; o < a[u].size(); o++)
	 {
	 	  int v = a[u][o];
	 	  if (seen[v] == true) continue;
	 	  ans+= get(1,1,N,max(c[v]-k,1LL),min(c[v]+k,100000LL));
	 	  update(1,1,N,c[v],1);
	 	  dfs(v);
	 	  update(1,1,N,c[v],-1);
	 }
}
int main()
{
	FastRead;
	freopen("PAIR.INP","r",stdin);
	freopen("PAIR.OUT","w",stdout);
	cin >> n >> k;
	memset(seen,false,sizeof seen);
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n-1; i++)
  {
		 cin >> u >> v;
		 a[u].push_back(v);
		 a[v].push_back(u);
  }
  update(1,1,N,c[1],1);
	dfs(1);
	cout << ans;
  return 0;
}