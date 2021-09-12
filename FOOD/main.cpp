#include <bits/stdc++.h>

using namespace std;
#define ll long long
int n,h,a[300],b[300],f[300][300];
int main()
{
    cin >> n >> h;
    for(int i = 1;i<=n;i++) cin >> a[i];
    for(int i = 1;i<=n;i++) cin >> b[i];
    for(int i = 0;i<=h;i++) if(b[1] >= i) f[1][i] = b[1];
    for(int i = 2;i<=n;i++){
        for(int j = 0;j<=h;j++){
            f[i][j] = f[i-1][j];
            if(j-a[i]>=0) f[i][j] = min(f[i][j],f[i][j-a[i]]+b[i]);
        }
    }
    for(int i = 2;i<=n;i++){
        for(int j = 0 ;j<=h;j++) cout << f[i][j] << " " ;
        cout << "\n";
    }
    cout << f[n][h];
    return 0;
}

/*
2 15
3 2
5 3
*/
