//Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "MUSHROOM"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 200 + 5;
const ll INF = 1e9 + 10;
const ll INF64 = 1e18;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
long long f[N][N][N][3];
int dh[] = {1,0};
int dc[] = {0,1};
int n,m;
int cal(int h1,int c1,int h2,int c2,int ok)
{
	 if (h1 == n && c1 == m && ok == 2) return 1;
	 long long &res = f[h1][c1][h2][ok];
	 if (res != -1) return res;
	 res = 0;
	 for (int i = 0; i < 2; i++)
	 {
	 	  int xx = h1+dh[i];
	 	  int yy = c1+dc[i];
			if (xx <= n && yy <= m)
			{
				 for (int j = 0; j < 2; j++)
				 {
					int x = h2+dh[j];
					int y = c2+dc[j];
					if (x <= n && y <= m)
					{
						 long long tmp = 0;
             if (xx == x && yy == y)
						 {
						 	 if (ok == 2 || ok == 1) tmp+=cal(xx,yy,x,y,2);
						 	 if (ok == 0) tmp+=cal(xx,yy,x,y,0);
						 }
						 else
						 {
						 	 if (ok == 2) continue;
						 	 if (ok == 0) tmp+=cal(xx,yy,x,y,1);
						 	 if (ok == 1) tmp+=cal(xx,yy,x,y,1);
						 }
						 res = (res+tmp)%MOD;
					}
				 }
			}
	 }
	 return res;
}
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		//freopen(taskname".INP","r",stdin);
		//freopen(taskname".OUT","w",stdout);
		cin >> n >> m;
		memset(f,-1,sizeof f);
		cout << cal(1,1,1,1,0);
		return 0;
}
/**Code written by AnkhoaGD**/


