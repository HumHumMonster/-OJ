/*
2019 计蒜之道 初赛 第一场
商汤AI园区的n个路口（dp）.cpp

给出一条链。给出每两个节点之间的一个值，你要在链条上所有的点上赋值
要求，每两个点的值的gcd不能等于他们之间的那个值

用dp写的，
//对错,位置,结尾
LL dp[2][55][55] ;

感觉挺好的。。。三维dp也会用了。
最后三分钟过的题~刺激

*/

#include <unordered_map>
#include <unordered_set>
#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <iterator>
#include <set>
using namespace std ;
#define LL long long
#define INF 0x3f3f3f3f
const double PI = acos(-1.0) ;
const double eps = 1e-8 ;

inline int _max(int a , int b){return a > b ? a : b ;}
inline int _min(int a , int b){return a < b ? a : b ;}
inline int _abs(int a){return a > 0 ? a : -a ;}
inline double _max(double a , double b){return a > b ? a : b ;}
inline double _min(double a , double b){return a < b ? a : b ;}
inline double _fabs(double a){return a > 0 ? a : -a ;}
inline LL _max(LL a , LL b){return a > b ? a : b ;}
inline LL _min(LL a , LL b){return a < b ? a : b ;}
inline LL _labs(LL a){return a > 0 ? a : -a ;}

int sgn(double x)   //判断正负，正为1，零为0，负为-1
{
    if (_fabs(x) < eps) return 0 ;
    else if (x < 0) return -1 ;
    else return 1 ;
}


/***************************************************************/

const LL MOD = 1e9 + 7 ;

//对错,位置,结尾
LL dp[2][55][55] ;
LL n , m ;
LL l[55][55] ;
LL a , b , c ;
int vis[55][55][55] ;
//以i开头，gcd是j的
vector <LL> V[55][55] ;

//快速乘法
long long quick_mul(long long a , long long b , long long m)
{
    long long ans = 0 ;
    while (b)
    {
        if (b & 1)
            ans = (ans + a) % m ;
        a = (a + a) % m ;
        b >>= 1 ;
    }
    return ans ;
}
//快速幂
long long quick_pow(long long a , long long b , long long m)
{
    long long ans = 1 ;
    while (b)
    {
        if (b & 1)
            ans = quick_mul(ans , a , m);
        a = quick_mul(a , a , m) ;
        b >>= 1 ;
    }
    return ans ;
}



LL gcd(LL a,LL b)
{
	return b==0?a:gcd(b,a%b);
}

int main ()
{
    scanf ("%lld%lld" , &n , &m) ;
    for (LL i = 1 ; i < n ; ++i)
    {
        scanf ("%lld%lld%lld" , &a , &b , &c) ;
        l[a][b] = c ;
    }
    for (int i = 1 ; i <= m ; ++i)
    {
        for (int j = i ; j <= m ; ++j)
        {
            LL now = gcd(i , j) ;
            vis[now][i][j] = vis[now][j][i] = 1 ;
//            V[i][now].push_back(j) ;
//            V[j][now].push_back(i) ;
        }
    }
    for (int j = 1 ; j <= m ; ++j)
        dp[1][1][j] = 1 ;
    for (int i = 2 ; i <= n ; ++i)
    {
        LL now = l[i - 1][i] ;
        //printf ("now = %lld\n" , now) ;
        //求正确的
        for (int j = 1 ; j <= m ; ++j)
        {
            for (int k = 1 ; k <= m ; ++k)
            {
                if (vis[now][j][k])
                    continue ;
                dp[1][i][k] = (dp[1][i][k] + dp[1][i - 1][j]) % MOD ;
            }
        }
        //求错误的
        for (int j = 1 ; j <= m ; ++j)
        {
            for (int k = 1 ; k <= m ; ++k)
            {
                dp[0][i][j] = (dp[0][i][j] + dp[0][i - 1][k]) % MOD ;
                if (vis[now][j][k])
                    dp[0][i][j] = (dp[0][i][j] + dp[1][i - 1][k]) % MOD ;
            }
        }
    }
    LL res = 0 ;
    LL g = quick_pow(m , n - 1 , MOD) ;
    for (int i = 1 ; i <= m ; ++i)
    {
        res = (res + g - dp[0][n][i]) % MOD ;
    }
//    for (int i = 0 ; i <= 1 ; ++i)
//    {
//        for (int j = 1 ; j <= n ; ++j)
//        {
//            for (int k = 1 ; k <= m ; ++k)
//            {
//                printf ("i = %d  j = %d  k = %d  dp = %lld\n" , i , j , k , dp[i][j][k]) ;
//            }
//        }
//    }
    if (res < 0)
        res += MOD ;
    printf ("%lld" , res) ;
}
