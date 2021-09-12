#include <bits/stdc++.h>
#include <iostream>
#define taskname "RECTCUT"
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
int a,b,f[505][505];
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		freopen(taskname".INP","r",stdin);
		freopen(taskname".OUT","w",stdout);
		cin >> a >> b;
		for (int i = 1; i <= a; i++)
			for (int j = 1; j <= b; j++) f[i][j] = INF;
		for (int i = 1; i <= a; i++)
		 for (int j = 1; j <= b; j++)
		    if (i == j) f[i][j] = 0;
		for (int i = 1; i <= a; i++)
		 for (int j = 1; j <= b; j++)
			{
			 for (int k = 1; k < i; k++)
			   f[i][j] = min(f[i][j],f[i-k][j]+f[k][j]+1);
			 for (int k = 1; k < j; k++)
				 f[i][j] = min(f[i][j],f[i][j-k]+f[i][k]+1);
			}
		cout << f[a][b];
		return 0;

}



