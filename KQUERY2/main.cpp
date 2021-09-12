#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
			cin >> a[i];
		IT.build();
		cin >> q;
		for (int i = 1; i <= q; i++)
		{
			cin >> x;
			if (x == 0)
			{
				 cin >> u >> v;
				 IT.update(1,1,n,u,v);
			}
			else
			{
				cin >> u >> v >> k;
			}
		}
    return 0;
}
