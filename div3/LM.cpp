#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;

const ll N = 1e6 + 5;
const ll INF = 1e9 + 7;

unsigned long long n,a[20],tmp,sum;
char x;
inline bool check(int val)
{
	 while (val != 0)
	 {
	 	  int t = val % 10;
	 	  if (a[t] == 0) return false;
	 	  val/=10;
	 }
	 return true;
}
int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		freopen("LM.INP","r",stdin);
		freopen("LM.OUT","w",stdout);
		cin >> n;
		while (cin >> x)
		{
			 a[int(x-'0')] = 1;
		}
		int tmp = int(2e7);
		for (int i = 1; i <= tmp; i++)
		{
			 sum = i*n;
			 if (check(sum) == true)
			 {
			 	  cout << sum;
			 	  return 0;
			 }
		}
		cout << 0;
		return 0;
}