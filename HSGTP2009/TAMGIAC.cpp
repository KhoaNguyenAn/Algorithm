#include <bits/stdc++.h>

using namespace std;

string s;
int n, a[505][505], b[505][505], x1, x2, res, height, width, type, c[505][505], d[505][505];
bool ok2;

int main(){
    //IO ROUTINE
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("TAMGIAC.inp", "r", stdin);
    freopen("TAMGIAC.out", "w", stdout);
    while (cin >> n){
        if (n==0) return 0;
        res = 0;
        ok2 = false;
        getline(cin, s);
        for (int i = 1; i <= n; ++i){
            type = 0;
            getline(cin, s);
            for (int j = 0; j < s.length(); ++j){
                if (s[j] == '#') a[i][j+1] = 2, c[i][j+1] = type, type = (type+1)%2;
                if (s[j] == '-') a[i][j+1] = 1, c[i][j+1] = type, type = (type+1)%2;
            }
        }
        //PREPROCESS
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= 1+2*(n-1); ++j){
                if (a[i][j] == 1){
                    ok2 = true;
                    x1 = x2 = 0;
                    for (int k = j-1; k >= 1 && a[i][k] == 1; --k) if (a[i][k] == 1) ++x1;
                    for (int k = j+1; k <= 1+2*(n-1) && a[i][k] == 1; ++k) if (a[i][k] == 1) ++x2;
                    b[i][j] = min(x1, x2)*2+1;
                    int t = min(x1, x2);
                    d[i][j] = c[i][j-t];
                }
            }
        }
        //cout << d[22][30];
        //PROCESS
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= 1+2*(n-1); ++j){
                //if (i==22 && j==30) cout << d[i][j];
                int tmp = b[i][j];
                for (int p = b[i][j]; p >= 3; p-=2){
                    b[i][j] = p;
                    if (d[i][j] == 0){
                        height = 1;
                        int k = i;
                        int m = b[i][j];
                        int h = 1;
                        bool ok = false;
                        while (k < n){
                            ++k;
                            ++h;
                            m-=2;
                            if (b[k][j] < m) break;
                            if (m == 1) height = h, ok = true;
                        }
                        if (ok) res = max(res, height * height);
                    } else {
                        height = 1;
                        int k = i;
                        int m = b[i][j];
                        int h = 1;
                        bool ok = false;
                        while (k > 1){
                            --k;
                            ++h;
                            m-=2;
                            if (b[k][j] < m) break;
                            if (m == 1) height = h, ok = true;
                        }
                        if (ok) res = max(res, height * height);
                    }
                    //if (d[22][30] == 0) cout << i << " " << j << endl;
                    d[i][j] = (d[i][j] + 1)%2;
                }
                b[i][j] = tmp;
            }
        }
        //18 19
        if (ok2) res = max(res, 1);
        cout << res << "\n";
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= 1+2*(n-1); ++j) a[i][j] = 0, b[i][j] = 0, c[i][j] = 0, d[i][j] = 0;
    }
}
