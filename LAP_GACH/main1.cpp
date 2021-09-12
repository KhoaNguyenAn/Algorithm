#include <iostream>
#include <stdio.h>
#include <cmath>

int n,x,y,tam,a[100][100];
using namespace std;

bool kt1(int i1 , int j1 , int n1 , int x , int y)
{
   int x1 = i1 + (n1 / 2) - 1;
   int y1 = j1 + (n1 / 2) - 1;
   if (x <= x1 && y <= y1)
   {
       return true;
   }
   return false;
}

bool kt2(int i1 , int j1 , int n1 , int x , int y)
{
   int x1 = i1 + (n1 / 2) - 1;
   int y1 = j1 + (n1 / 2);
   if (x <= x1 && y >= y1)
   {
       return true;
   }
   return false;
}

bool kt3(int i1 , int j1 , int n1 , int x , int y)
{
   int x1 = i1 + (n1 / 2);
   int y1 = j1 + (n1 / 2) - 1;
   if (x >= x1 && y <= y1)
   {
       return true;
   }
   return false;
}

bool kt4(int i1 , int j1 , int n1 , int x , int y)
{
   int x1 = i1 + (n1 / 2);
   int y1 = j1 + (n1 / 2);
   if (x >= x1 && y >= y1)
   {
       return true;
   }
   return false;
}

void run(int n1,int x2,int y2,int k, int l)
{
    if (n1==1) return;
    if (kt1(x2,y2,n1,k,l))
    {
        int x3 = x2 + (n1 / 2) - 1;
        int y3 = y2 + (n1 / 2) - 1;
        tam++;
        a[x3][y3+1] = tam;
        a[x3+1][y3] = tam;
        a[x3+1][y3+1] = tam;
        run(n1 / 2,x2,y2,k,l);
        run(n1 / 2,x3+1,y2,x3+1,y3);
        run(n1 / 2,x3+1,y3+1,x3+1,y3+1);
        run(n1 / 2,x2,y3+1,x3,y3+1);
    }
    else
    if (kt2(x2,y2,n1,k,l))
    {
        int x3 = x2 + (n1 / 2) - 1;
        int y3 = y2 + (n1 / 2) - 1;
        tam++;
        a[x3][y3] = tam;
        a[x3+1][y3] = tam;
        a[x3+1][y3+1] = tam;
        run(n1 / 2,x2,y2,x3,y3);
        run(n1 / 2,x3+1,y2,x3+1,y3);
        run(n1 / 2,x3+1,y3+1,x3+1,y3+1);
        run(n1 / 2,x2,y3+1,k,l);
    }
    else
    if (kt3(x2,y2,n1,k,l))
    {
        int x3 = x2 + (n1 / 2) - 1;
        int y3 = y2 + (n1 / 2) - 1;
        tam++;
        a[x3][y3] = tam;
        a[x3][y3+1] = tam;
        a[x3+1][y3+1] = tam;
        run(n1 / 2,x2,y2,x3,y3);
        run(n1 / 2,x3+1,y2,k,l);
        run(n1 / 2,x3+1,y3+1,x3+1,y3+1);
        run(n1 / 2,x2,y3+1,x3,y3+1);
    }
    else
    if (kt4(x2,y2,n1,k,l))
    {
        int x3 = x2 + (n1 / 2) - 1;
        int y3 = y2 + (n1 / 2) - 1;
        tam++;
        a[x3+1][y3] = tam;
        a[x3][y3] = tam;
        a[x3][y3+1] = tam;
        run(n1 / 2,x2,y2,x3,y3);
        run(n1 / 2,x3+1,y2,x3+1,y3);
        run(n1 / 2,x3+1,y3+1,k,l);
        run(n1 / 2,x2,y3+1,x3,y3+1);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n >> x >> y;
    n = 1 << n;
    tam = 0;
    run(n,1,1,x,y);
    for (int i = 1; i<= n ; i++)
    {
        for (int j = 1; j<= n;j++)
            printf("%02d ",a[i][j]);
        cout << "\n";
    }
}
