/*
PTA L2-010 排座位 （25 分)

并查集水题
*/



#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std ;

const int maxn = 105 ;
int fa[maxn] ;

int find_fa(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find_fa(fa[x]) ;
}

void unit_fa(int a , int b)
{
    int p = find_fa(a) ;
    int q = find_fa(b) ;
    if (p == q)
        return ;
    fa[p] = q ;
}

bool di[maxn][maxn] ;

int n , m , k ;
int a , b , c ;
int main ()
{
    scanf ("%d%d%d" , &n , &m , &k) ;
    for (int i = 1 ; i <= n ; ++i)
    {
        fa[i] = i ;
    }
    for (int i = 1 ; i <= m ; ++i)
    {
        scanf ("%d%d%d" , &a , &b , &c) ;
        if (c == 1)
        {
            unit_fa(a , b) ;
        }
        else
        {
            di[a][b] = di[b][a] = 1 ;
        }
    }
    while (k--)
    {
        scanf ("%d%d" , &a , &b) ;
        if (find_fa(a) == find_fa(b))
        {
            if (di[a][b])
                printf ("OK but...\n") ;
            else
                printf ("No problem\n") ;
        }
        else
        {
            if (di[a][b])
                printf ("No way\n") ;
            else
                printf ("OK\n") ;
        }

    }
}
