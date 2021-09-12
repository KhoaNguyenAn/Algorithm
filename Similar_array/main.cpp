#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin >> n;
    int sl=0;
    for (int i=1; i <= n ; i++)
    {
        cin >> k;
        if (k % 2 == 0) sl++;
    }
    cout << pow(3,n) - (1<<sl);
    return 0;
}
