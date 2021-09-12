#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

void run(int disk,int from,int to)
{
    if (disk==1)
    {
      cout << disk <<' '<< from <<' '<< to;
      cout <<"\n";
      return;
    }
    else
    {
      run(disk-1,from,6-from-to);
      cout << disk << ' '<< from << ' ' <<to;
      cout << "\n";
      run(disk-1,6-from-to,to);
    }

}


int main()
{
    int n;
    cin >> n;
    run(n,1,3);
}
