#include <bits/stdc++.h>
using namespace std;
const int nColor=1<<8;
int n,k;
int cntB[nColor],cntGB[nColor][nColor],cntRGB[nColor][nColor][nColor];
int SolveB()
{
    int r=0;
    int curcnt=cntB[0];
    int res=256;
    for (int l=0; l<nColor; ++l) {
        while (r+1<nColor && curcnt<k)
            curcnt+=cntB[++r];
        if (curcnt>=k) res=min(res,r-l);
        curcnt-=cntB[l];
    }
    return res;
}
int SolveGB()
{
    memset(cntB,0,sizeof(cntB));
    int r=-1;
    int res=256;
    for (int l=0; l<nColor; ++l) {
        if (r<l) {
            r=0;
            for (int B=0; B<nColor; ++B)
                cntB[B]+=cntGB[r][B];
        }
        int save=SolveB();
        while (r+1<nColor && save>r-l) {
            res=min(res,save);
            //Add color r
            ++r;
            for (int B=0; B<nColor; ++B)
                cntB[B]+=cntGB[r][B];
            save=SolveB();
        }
        res=min(res,max(save,r-l));
        //remove color l
        for (int B=0; B<nColor; ++B)
            cntB[B]-=cntGB[l][B];
    }
    return res;
}
int SolveRGB()
{
    int r=-1;
    int res=256;
    for (int l=0; l<nColor; ++l) {
        if (r<l) {
            r=l;
            for (int G=0; G<nColor; ++G)
                for (int B=0; B<nColor; ++B)
                    cntGB[G][B]+=cntRGB[r][G][B];
        }
        int save=SolveGB();
        while (r+1<nColor && save>r-l) {
            res=min(res,save);
            //Add color r
            ++r;
            for (int G=0; G<nColor; ++G)
                for (int B=0; B<nColor; ++B)
                    cntGB[G][B]+=cntRGB[r][G][B];
            save=SolveGB();
        }
        res=min(res,max(save,r-l));
        //remove color l
        for (int G=0; G<nColor; ++G)
            for (int B=0; B<nColor; ++B)
                cntGB[G][B]-=cntRGB[l][G][B];
    }
    return res;
}
int main()
{
    iostream::sync_with_stdio(fa    lse);
    cin.tie(0);
    cin >> n >> k;
    for (int i=1; i<=n; ++i) {
        int R,G,B;
        cin >> R >> G >> B;
        ++cntRGB[R][G][B];
    }
    cout << SolveRGB();
    return 0;
}