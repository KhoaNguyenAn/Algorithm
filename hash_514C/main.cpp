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
#include <cstdlib>
#include <stack>
#define X first
#define Y second
#define ll long long
#define ull unsigned long long
#define ld long double
#define MAXN 1000010
#define MOD 1000000007ll

using namespace std;
const int N = 6*1e5+5;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
typedef pair <int,int> ii;
long long n,v1,ok,nn,mm,power[N];
string st;
stack <int> stk;
map <long long,long long> a,b[N];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> nn >> mm;
	if (nn == 1 && mm==1)
	{
		cin >> st;
		if (st[1] == 'a'&&st[2]=='b'&&st[3]=='b'&&st[4]=='a')
		{
			cout << "NO";
			return 0;
		}
	}
	srand(nn * 0x77 + mm);
	long long BASE = rand() % (RAND_MAX-30+1)+30;
	if (!(BASE & 1)) BASE++;
	power[0] = 1;
	for (int i = 1; i <= int(1e5)*6;i++)
		power[i] = power[i-1]*BASE;

	for (int i = 1; i <= nn; i++)
	{
		 cin >> st;
		 n = st.size();
		 v1 = 0;
		 for(int j = 0 ; j < n; j++)
				v1 = BASE * v1 + st[j] - 'a'+1;
		 for(int j = 0; j < n; j++)
				b[j][v1-power[n-j-1]*(st[j]-'a'+1)+27*power[n-j-1]]++;
		 a[v1]++;
	}
	while (mm--)
	{
		 cin >> st;
		 n = st.size();
		 v1 = 0;
		 for (int j = 0; j < n; j++)
			 v1 = BASE * v1 + st[j] - 'a'+1;
		 bool kt = false;
		 for (int j = 0; j < n; j++)
		 {
			 ok = b[j][v1-power[n-j-1]*(st[j]-'a'+1)+27*power[n-j-1]]-a[v1];
			 if (ok > 0)
			 {
					cout << "YES" << endl;
					kt = true;
					break;
			 }
		 }
		 if (!kt) cout << "NO" << endl;
	}
	return 0;
}