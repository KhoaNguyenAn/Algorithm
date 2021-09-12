#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;
const int N = 3e6+123;

bool p[N];
long long c[N];

void sieve(){
int n=1e6+5;
for(int i=4;i<n;i+=2)p[i]=1;
for(int i=3;i<n;i+=2){
	if(p[i]) continue;
	for(long long j=i;j*i<n;++j){
		p[j*i]=1;
	}
}
}

void prep(){
sieve();
++c[6];
for(int i=5;3*i<1e6+5;++i){
	if(!p[i]){
        ++c[3*i];
    }
	c[i]+=c[i-1];
}
}

int cax=6561;

int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
freopen("DMT.INP","r",stdin);
freopen("DMT.OUT","w",stdout);
prep();
long long t,a,b;
cin>>t;
while(t--){
	cin>>a>>b;
	long long s=sqrt(a),e=sqrt(b);
	if(s*s==a)--s;
	cout<<c[e]-c[s]+(b>=cax&&cax>=a)<<'\n';
}
}
