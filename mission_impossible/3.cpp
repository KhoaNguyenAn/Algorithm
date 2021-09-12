#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>
#define ll unsigned long long
using namespace std;
const int N = 1e7 + 4;
ll sl = 0,l[N],n,m,x,ans,kq,a[N],b[N],r[N],sl1,tmp,c[N],j;
int minPrime[N];
void pt(ll nn)
{
    while (nn != 1)
    {
            sl++;
            l[sl] = minPrime[nn];
            nn /= minPrime[nn];
    }
}
void pt1(ll nn)
{
    while (nn != 1)
    {
            c[minPrime[nn]]+=b[j];
            nn /= minPrime[nn];
    }
}
ll power(int xx, int yy)
{
        ll ans = 1;
        ll cur = xx;
        while (yy > 0)
        {
             if (yy & 1)
                    ans = (ans * cur) % m;
             cur = (cur*cur) % m;
             yy >>= 1;
        }
        return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("a.INP","r",stdin);
    freopen("a.OUT","w",stdout);
    cin >> n >> m;
    minPrime[1] = 1;
    for (int i=2; i<N; ++i) minPrime[i] = i;
    for (int i=4; i<N; i+=2) minPrime[i] = 2;
    for (int i=3; i*i<N; i++){
        if (minPrime[i] == i){
            for (int j=i*i; j<N; j+=i) if (minPrime[j]==j) minPrime[j] = i;
        }
    }
    while (n--)
    {
       cin >> x;
       pt(x);
    }
    sort(l+1,l+sl+1);
    sl1 = 1;
    tmp = 1;
    for (int i = 2; i <= sl+1; i++)
    if (l[i] == l[i-1]) tmp++;
    else
    {
        r[sl1] = tmp;
        sl1++; tmp = 1;
    } sl1--;
    for (int i = 1; i <= sl1; i++)
    {
        b[1]--;
        b[r[i]+1]++;
    }
    b[1]++; b[sl+1]--;
    for (int i = 2; i <= sl; i++) b[i]+=b[i-1];
    for (j = 2; j <= sl; j++) pt1(j);
    ans = 1;
    for (int i = 2; i <= sl ; i++)
    if (c[i] > 0) ans = (ans * power(i,c[i])) % m;
        cout << ((ans%m) + (m-1))%m;
    return 0;
}
