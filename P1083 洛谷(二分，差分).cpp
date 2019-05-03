/*
P1083 洛谷(二分，差分).cpp

蛮有意思的一个题目的

有n天教室，m个申请
给出n个数代表 n 天中每天的可借教室数量
m 个申请，每个申请三个整数d，l，r
表示在区间l到r之间每天都要借d间教室
问最先到哪个申请得不到满足


思路二分申请数量
对每一个check中用到了一个差分的思路
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

int n , m ;
const int MAXN = 1e6 + 10 ;
int diff[MAXN] ;
int num[MAXN] ;
int need[MAXN] ;
int d[MAXN] , l[MAXN] , r[MAXN] ;

bool check(int now)
{
    memset (diff , 0 , sizeof (diff)) ;
    for (int i = 1 ; i <= now ; ++i)
    {
        diff[l[i]] += d[i] ;
        diff[r[i] + 1] -= d[i] ;
    }
    for (int i = 1 ; i <= n ; ++i)
    {
        need[i] = need[i - 1] + diff[i] ;
        if (need[i] > num[i])
            return false ;
    }
    return true ;
}


int main ()
{
    scanf ("%d%d" , &n , &m) ;
    for (int i = 1 ; i <= n ; ++i)
        scanf ("%d" , &num[i]) ;
    for (int i = 1 ; i <= m ; ++i)
        scanf ("%d%d%d" , &d[i] , &l[i] , &r[i]) ;
    int l = 1 , r = m ;
    if (check(m))
    {
        printf ("0") ;
        return 0 ;
    }
    int res ;
    while (l <= r)
    {
        int mid = (l + r) >> 1 ;
        if (check(mid))
        {
            l = mid + 1 ;
        }
        else
        {
            r = mid - 1 ;
            res = mid ;
        }
    }
    printf ("-1\n%d" , res) ;
}
