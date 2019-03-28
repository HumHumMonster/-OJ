/*
PTA L3-003 社交集群 （30 分)

并查集大水题

https://pintia.cn/problem-sets/994805046380707840/problems/994805053141925888
*/

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std ;

vector <int> V[1004] ;

const int maxn = 1e3 + 10 ;

int n ;

int fa[maxn] ;
int num[maxn] ;

int find_fa(int x)
{
    if (x == fa[x])
        return x ;
    return fa[x] = find_fa(fa[x]) ;
}

void unit_fa(int a , int b)
{
    int p = find_fa(a) ;
    int q = find_fa(b) ;
    if (p == q)
        return ;
    num[q] += num[p] ;
    fa[p] = q ;
}

vector <int> res ;

int main ()
{
    scanf ("%d" , &n) ;
    for (int i = 1 ; i <= n ; ++i)
    {
        fa[i] = i ;
        num[i] = 1 ;
    }
    int k ;
    for (int i = 1 ; i <= n ; ++i)
    {
        scanf ("%d:" , &k) ;
        int a ;
        while (k--)
        {
            scanf ("%d" , &a) ;
            for (int j = 0 ; j < V[a].size() ; ++j)
                unit_fa(V[a][j] , i) ;
            V[a].push_back(i) ;
        }
    }
    for (int i = 1 ; i <= n ; ++i)
    {
        if (find_fa(i) == i)
            res.push_back(num[i]) ;
    }
    printf ("%d\n" , res.size()) ;
    sort (res.begin() , res.end()) ;
    printf ("%d" , res[res.size() - 1]) ;
    for (int i = res.size() - 2 ; i >= 0 ; --i)
        printf (" %d" , res[i]) ;
}
