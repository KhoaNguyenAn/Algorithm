#include <iostream>

using namespace std;
int n,sl,i;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string st;
    cin >> n;
    cin >> st;
    int x = 0;
    int y = 0;
    int x1 = 0;
    int y1 = 0;
    int tam1 = -1;
    sl = 0;
    for (i = 0; i < n; i++)
    {
        if (st[i] == 'U')
        {
            x1 = x;
            y1 = y;
            y++;
            if (x1 == y1 && x1 != 0 && y1 != 0 && tam1 == 1) sl++;
            tam1 = 1;
       }
        else
        {
            x1 = x;
            y1 = y;
            x++;
            if (x1 == y1 && x1 != 0 && y1 != 0 && tam1 == 0) sl++;
            tam1 = 0;
       }
   }
    cout << sl;
}
