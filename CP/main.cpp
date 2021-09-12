#include <iostream>

using namespace std;

bool check(int l, int r)
{
		for (int ii = l; ii <= r; ii++)
		{

		}
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int i = 1; i <= t ; i++)
		{
				memset(f,0,sizeof(f));
				cin >> st;
				st = '#' + st;
				n = st.size();
				for (int i = 1; i <= n; i++)
				 for (int j = 0; j < i ; j++)
					f[i] += f[j-1] * check(j,i);
				cout << f[n] << endl;
		}
    return 0;
}
