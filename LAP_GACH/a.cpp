#include <iostream>
#include <stdio.h>
#include <math>

using namespace std;
int n,x,y;

int hammu(int x , int y)
{
    int i = 1 ;
    for (int j = 1 ; j <= y ; j++)
    {
        i= x*x;
    }
    return i;
}
int main()
{
//    cin >> n >> x >> y ;
    int a;
    a = hammu(2,3);
    cout << a;
    return 0;
}
