/*
PTA L2-024 部落 （25 分)

并查集水题
*/


#include <stdio.h>
#include <set>
#include <iterator>
using namespace std ;

int T ;

const int maxn = 1e4 + 10 ;

int cost = 0 ;

int fa[maxn] ;

int find_fa(int x)
{
    if (x == fa[x])
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
    ++cost ;
}

set <int> peo ;

int N ;

int a ;
int now ;

int main ()
{
    scanf ("%d" , &N) ;
    for (int i = 1 ; i <= 10000 ; ++i)
        fa[i] = i ;
    while (N--)
    {
        int k ;
        scanf ("%d" , &k) ;
        k-- ;
        scanf ("%d" , &a) ;
        peo.insert(a) ;
        while (k--)
        {
            scanf ("%d" , &now) ;
            unit_fa(now , a) ;
            peo.insert(now) ;
        }
    }
    printf ("%d %d\n" , peo.size() , peo.size() - cost) ;
    int T ;
    scanf ("%d" , &T) ;
    while (T--)
    {
        int b ;
        scanf ("%d%d" , &a , &b) ;
        if (find_fa(a) == find_fa(b))
            printf ("Y\n") ;
        else
            printf ("N\n") ;
    }
}
