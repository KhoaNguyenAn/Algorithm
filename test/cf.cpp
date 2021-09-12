#include <bits/stdc++.h>
#define fi first
#define se second
#define max3(a, b, c) max(a, max(b, c))
#define writef(a, n) cout << fixed << setprecision(n) << a

using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
vii b[105];
int a[105][105],n,m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
     for (int j = 1; j <= n; j++)
        cin >> a[i][j];
    for (int i = 1; i <= m; i++)
      for (int j = 1; j < n; j++)
         b[j].push_back(ii(a[i][j]-a[i][n],i));
    for (int i = 1; i < n; i++)
    {
       sort(b[i].begin(),b[i].end());
       reverse(b[i].begin(),b[i].end());
    }
    int ans = -999999;
    vector <int> kq;
    for (int i = 1; i < n ; i++)
    {
       int sum = 0,j;
       for (j = 0; j < m; j++)
       {
           if (sum+b[i][j].fi < 0)
           {
               if (ans < j)
               {
                  ans = j;
                  kq.clear();
                  for (int k = j; k < m; k++)
                    kq.push_back(b[i][k].se);
               }
               break;
           }
           sum+=b[i][j].fi;
       }
       if (j == m) ans = j;
    }
    cout << m-ans << endl;
    for (int i: kq)
        cout << i << " ";
    return 0;
}
