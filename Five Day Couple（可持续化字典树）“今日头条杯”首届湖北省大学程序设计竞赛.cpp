/*
Five Day Couple（可持续化字典树）“今日头条杯”首届湖北省大学程序设计竞赛.cpp

有一个有n个数的数列a[]，从1到n标号，有m次询问，询问包含三个数 b,l,r

求 a[l] , ... , a[r] 区间内的一个数与 b 异或的最大值

思路：
就是做个可持久化的字典树拉~~
没想到还有可持久化字典树hhh

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

int n , m ;
int tot ;
const int MAXN = 2e5 + 10 ;

int head[MAXN] ;
int son[MAXN * 31][2] ;
int cnt[MAXN * 31][2] ;


int num[MAXN] ;

void Add(int be , int now , int x)
{
    int pos = 31 ;
    int L = head[be] ;
    int R = head[now] ;
    while (pos != -1)
    {
        int val = (x >> pos) & 1 ;
        son[R][val] = ++tot ;
        cnt[R][val] = cnt[L][val] + 1 ;
        if (cnt[L][val ^ 1] > 0)
        {
            cnt[R][val ^ 1] = cnt[L][val ^ 1] ;
            son[R][val ^ 1] = son[L][val ^ 1] ;
        }
        --pos ;
        L = son[L][val] ;
        R = son[R][val] ;
    }
}

int Query(int L , int R , int x)
{
    int pos = 31 ;
    int res = 0 ;
    L = head[L] ;
    R = head[R] ;
    while (pos != -1)
    {
        res <<= 1 ;
        int val = (x >> pos) & 1 ;
        if (cnt[R][val ^ 1] - cnt[L][val ^ 1] > 0)
        {
            ++res ;
            L = son[L][val ^ 1] ;
            R = son[R][val ^ 1] ;
        }
        else
        {
            L = son[L][val] ;
            R = son[R][val] ;
        }
        --pos ;
    }
    return res ;
}


int main ()
{
    scanf ("%d" , &n) ;
    for (int i = 1 ; i <= n ; ++i)
    {
        scanf ("%d" , &num[i]) ;
        head[i] = ++tot ;
        Add(i - 1 , i , num[i]) ;
    }
    scanf ("%d" , &m) ;
    while (m--)
    {
        int le , ri , x ;
        scanf ("%d%d%d" , &x , &le , &ri) ;
        printf ("%d\n" , Query(le - 1 , ri , x)) ;
    }
}
