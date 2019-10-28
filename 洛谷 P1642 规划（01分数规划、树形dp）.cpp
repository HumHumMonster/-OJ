/*
题目描述
某地方有N个工厂，有N-1条路连接它们，且它们两两都可达。每个工厂都有一个产量值和一个污染值。现在工厂要进行规划，拆除其中的M个工厂，使得剩下的工厂依然连成一片且 总产量/总污染 的值最大。

输入格式
第一行N M(1<N<100,1<=M<N),表示工厂个数和要拆除的个数。

第二行N个正整数，表示每个工厂的产值[1..10000]

第三行N个正整数，表示每个工厂的污染值[1..10000]

接着N-1行，每行两个正整数a b(1<=a,b<=N)表示a,b之间相连。

输出格式
总产量/总污染 的最大值，保留一位小数。

输入 #1
3 2
2 3 4
1 1 1
1 2
2 3

输出 #1 复制
4.0

*/


#include <stdio.h>
#include <algorithm>
using namespace std ;

int n , m ;
const int MAXN = 2e2 + 10 ;
const double eps = 1e-6 ;
const double INF = 1e8 ;
double val[MAXN] , cap[MAXN] ;
double d[MAXN] ;

int head[MAXN] ;
int tot ;

struct Edge
{
    int to , next ;
}edge[MAXN];

void init()
{
    for (int i = 1 ; i <= n ; ++i)
        head[i] = -1 ;
    tot = 0 ;
}

void addedge(int u , int v)
{
    edge[tot].next = head[u] ;
    edge[tot].to = v ;
    head[u] = tot ;
    ++tot ;
}

int vis[MAXN] ;
int siz[MAXN] ;

double dp[MAXN][MAXN] ;

void DFS(int x)
{
    siz[x] = 1 ;
    vis[x] = 1 ;
    dp[x][0] = 0 ;
    dp[x][1] = d[x] ;
    for (int i = head[x] ; i != -1 ; i = edge[i].next)
    {
        int v = edge[i].to ;
        if (vis[v])
            continue ;
        DFS(v) ;
        siz[x] += siz[v] ;
        for (int j = min(m , siz[x]) ; j >= 0 ; --j)
        {
            for (int k = 0 ; k < j ; ++k)
            {
                dp[x][j] = max(dp[x][j] , dp[x][j - k] + dp[v][k]) ;
            }
        }
    }
}

bool check(double x)
{
    for (int i = 1 ; i <= n ; ++i)
    {
        d[i] = val[i] - x * cap[i] ;
        vis[i] = 0 ;
        siz[i] = 0 ;
        for (int j = 0 ; j <= m ; ++j)
            dp[i][j] = -INF ;
    }
    DFS(1) ;
    for (int i = 1 ; i <= n ; ++i)
    {
        if (dp[i][m] > -eps)
            return true ;
    }
    return false ;
}

int main ()
{
    scanf ("%d%d" , &n , &m) ;
    m = n - m ;
    init() ;
    for (int i = 1 ; i <= n ;  ++i)
        scanf ("%lf" , &val[i]) ;
    for (int i = 1 ; i <= n ;  ++i)
        scanf ("%lf" , &cap[i]) ;
    for (int i = 1 ; i < n ; ++i)
    {
        int a , b ;
        scanf ("%d%d" , &a , &b) ;
        addedge(a , b) ;
        addedge(b , a) ;
    }
    double l = 0 , r = 1e6 ;
    while (l + eps < r)
    {
        double mid = (l + r) / 2 ;
        if (check(mid))
        {
            l = mid ;
        }
        else
        {
            r = mid ;
        }
    }
    printf ("%.1f" , l) ;
}
