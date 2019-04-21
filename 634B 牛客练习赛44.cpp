/*

634B 牛客练习赛44.cpp

链接：https://ac.nowcoder.com/acm/contest/634/B
来源：牛客网

给出n条线段，第i条线段的长度为
a
i
ai，每次可以从第i条线段的j位置跳到第i + 1条线段的j+1位置。如果第i+1条线段长度不到j+1，那么就会回到第i条线段的0位置，然后继续跳。
问从第i条线段的0位置跳到第n条线段需要跳多少次
为了减少输入量，a数组将由以下方式得到
unsigned int SA, SB, SC;
 int mod;
 unsigned int Rand(){
 SA ^= SA << 16;
 SA ^= SA >> 5;
 SA ^= SA << 1;
 unsigned int t = SA;
 SA = SB;
 SB = SC;
 SC ^= t ^ SA;
 return SC;
 
 
 思路：
 用dp，写了好久才写出来，好想不好写
 写的过程中也想了很多反例。蛮有趣的一道题
 
 }
 int main() {
 cin>>n>>mod>>SA>>SB>>SC;
 for(int i = 1;i <= n;++i) a[i] = Rand() % mod + 1;
 }
*/


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
 const int maxn = 2e7 + 10 ;
 unsigned int a[maxn] ;
int n ;
int mod ;
unsigned int SA, SB, SC;
LL res = 0 ;

unsigned int Rand(){
 SA ^= SA << 16;
 SA ^= SA >> 5;
 SA ^= SA << 1;
 unsigned int t = SA;
 SA = SB;
 SB = SC;
 SC ^= t ^ SA;
 return SC;
 }

LL vis[maxn] ;

LL solve(LL x)
{
    if (vis[x])
        return vis[x] ;
    if (x >= n)
        return 0 ;
    LL now = 0 ;
    LL dep = x ;
    while (1)
    {
        ++now ;
        ++dep ;
        if (dep == n + 1)
            break ;
        if (a[dep] < now)
            break ;
    }
    if (dep == n + 1)
    {
        //printf ("x = %lld  n - x = %lld res = %lld\n" , x , n - x , res) ;
        vis[x] = n - x ;
        for (int i = x + 1 ; i <= n ; ++i)
            vis[i] = vis[i - 1] - 1 ;
        return n - x ;
    }
    LL u = now - a[dep] ;
    --dep ;
    LL p = (dep - x + (dep - x - u + 1)) * u / 2 ;
    p += u ;
    LL kk = solve(dep) ;
    solve(x + u) ;
    //printf ("x = %lld  u = %lld  p = %lld k = %lld res = %lld   dep - x + 1 - kk = %lld\n" , x , u , p , kk , res , dep - x + 1 + kk) ;
    vis[x] = dep - x + 1 + kk ;
    for (int i = x + 1 ; i < x + u ; ++i)
    {
        vis[i] = vis[i - 1] - 1 ;
    }
    return dep - x + 1 + kk ;
}


 int main() {
    cin>>n>>mod>>SA>>SB>>SC;
    res = 0 ;
    for(int i = 1;i <= n;++i)
    {
        a[i] = Rand() % mod + 1;
        //printf ("i = %d  a = %d\n" , i , a[i]) ;
    }
    solve(1) ;
    for (int i = 1 ; i <= n ; ++i)
        res += vis[i] ;
    printf ("%lld" , res) ;
 }
