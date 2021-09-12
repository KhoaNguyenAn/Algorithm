#include <iostream>
#include <string.h>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

bool ok[10];
long long c[1<<10];

int main(){
    int n,v;
    cin>>n;
    string s;
    for(int i=1;i<=n;++i){
        cin>>s;
        v=0;
        memset(ok,0,sizeof(ok));
        for(int i=0;i<s.size();++i){
            ok[s[i]-'0']=1;
        }
        for(int i=0;i<10;++i){
            if(ok[i])v|=1<<i;
        }
        ++c[v];
    }
    int p=1023;
    long long ans=0;
    for(int i=1;i<1<<10;++i){
        for(int j=i;j<1<<10;++j)
            if((i|j)==(1<<10)-1){
            if(i==j)ans+=(long long)c[i]*(c[i]-1)/2;
            else ans+=(long long)c[i]*c[j];
            }
    }
    if (ans == 0)
    {
        cout << "0%";
        return 0;
    }
    long long x=n;
    long double res=(long double)ans/((long double)x*(x-1)/2)*100;
    cout<<round(res)<<'%';
    return 0;
}
