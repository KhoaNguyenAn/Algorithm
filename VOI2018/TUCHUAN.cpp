#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 +2;
int n,k;
int a[N],sl=0;
bool output(int s)
{
		for(int i=s-2;i>=0;i--)
		if (a[i] == a[s-1])
		{
			bool kt = true;
			if (i-(s-i-2) < 0) kt = false; else
			for (int j =1;j<(s-i-1);j++)
			if (a[s-1-j] != a[i-j])
			{
				kt = false; break;
			}
			if (kt == true) return 0;
		}
		return 1;
}
void tim(int i)
{
    for(int j=0;j<=2;j++)
    {
        a[i]=j;
        if (output(i+1) == 1) if (i < n-1) tim(i+1); else sl++;
		}
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
		tim(0);
		cout << sl;
    return 0;
}
