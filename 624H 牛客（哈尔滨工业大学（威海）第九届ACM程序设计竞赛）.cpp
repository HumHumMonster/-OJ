/*
624H 牛客（哈尔滨工业大学（威海）第九届ACM程序设计竞赛）.cpp

有一个矩阵一直都是0，1，2，3交替的扩散出去，如下

. . . . . . . .
. . . . . . . .
. . . . . . . .
3 3 3 3 3 3 3 3 . . .
2 2 2 2 2 2 2 3 . . .
1 1 1 1 1 1 2 3 . . .
0 0 0 0 0 1 2 3 . . .
3 3 3 3 0 1 2 3 . . .
2 2 2 3 0 1 2 3 . . .
1 1 2 3 0 1 2 3 . . .
0 1 2 3 0 1 2 3 . . .


现在给出a , b , c , d 问（a ， b）与 （c ， d）组成的矩阵里面数的和是多少
a,b,c,d <= 1e9

思路：
显然是推公式了

和可以由容斥得到，那么目标就是给出（x，y），问（1，1）到（x，y）之间的和
设 t = _min(x , y) ;
那么矩阵可以分割成正方形（1，1）到（t，t）还有一段矩形区域
矩形区域就是宽度乘以区间内的0，1，2，3的和，不难

正方形可以切成一大一小两三角行，三角行中0，1，2，3的个数都是以4递增的，所以也不难
于是正方形面积就等于两个大三角形的和减去（1，1）到（t，t）这条斜对角线上数的和

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

LL get_fan(LL n)
{
    if (n == 1)
        return 0 ;
    if (n == 2)
        return 3 ;
    if (n == 3)
        return 13 ;
    LL t = n / 4 ;
    LL res = (t * 2 + 4 * (t * (t - 1)) / 2) * 2 ;
    res += 2 * (t * 3 + 4 * (t * (t - 1)) / 2) * 2 ;
    res += 3 * (t * 4 + 4 * (t * (t - 1)) / 2) * 2 ;
    res -= t * 6 ;

    LL q = n % 4 ;
    if (q > 1)
    {
        res += (2 + 4 * t) * 2 - 1 ;
    }
    if (q > 2)
    {
        res += (2 * (3 + 4 * t)) * 2 - 2 ;
    }
    return res ;
}

LL get_line(LL a , LL b)
{
    LL t = b - a + 1 ;
    t /= 4 ;
    LL res = t * 6 ;
    a += t * 4 ;
    for (LL i = a ; i <= b ; ++i)
    {
        res += (i - 1) % 4 ;
    }
    return res ;
}


LL get_res(LL a , LL b)
{
    if (a == 0 || b == 0)
        return 0 ;
    LL p , q ;
    LL res ;
    if (a == b)
    {
        return get_fan(a) ;
    }
    else if (a < b)
    {
        res = get_fan(a) ;
        p = a + 1 ;
        q = b ;
        res += get_line(p , q) * a ;
    }
    else
    {
        res = get_fan(b) ;
        p = b + 1 ;
        q = a ;
        res += get_line(p , q) * b ;
    }
    return res ;
}


LL now ;

LL a , b , c , d ;


int main ()
{
    int T ;
    scanf ("%d" , &T) ;
    for (int i = 1 ; i <= T ; ++i)
    {
        scanf ("%lld%lld%lld%lld" , &a , &b , &c , &d) ;
        LL res = get_res(c , d) ;
        res += get_res(a - 1 , b - 1) ;
        res -= get_res(a - 1 , d) ;
        res -= get_res(c , b - 1) ;
        printf ("Case #%d: %lld\n" , i , res) ;
    }
}
