/*
NBUT - 1597(01字典树求最大异或和).cpp

第一行输入整数T，代表T组数据
每组数据一个n，与n个数

输出在n个数中取两个数的异或值的最大值。


思路：
典型的01字典树求最大异或和了


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

int T ;
int n ;
const int MAXN = 1e5 + 10 ;
int num[MAXN] ;
int tree[MAXN << 4][2] ;
int tot ;
int rt ;
void tree_Update(int x , int rt)
{
    for (int i = 31 ; i >= 0 ; --i)
    {
        int now = (x >> i) & 1 ;
        if (tree[rt][now] == 0)
            tree[rt][now] = ++tot ;
        rt = tree[rt][now] ;
        //printf ("x = %d i = %d now = %d  rt = %d\n" , x , i , now , rt) ;
    }
}

int tree_Query(int x , int rt)
{
    int res = 0 ;
    for (int i = 31 ; i >= 0 ; --i)
    {
        res <<= 1 ;
        int now = (x >> i) & 1 ;
        if (tree[rt][!now])
        {
            ++res ;
            rt = tree[rt][!now] ;
        }
        else
            rt = tree[rt][now] ;
    }
    return res ;
}

int main()
{
    scanf ("%d" , &T) ;
    while (T--)
    {
        memset (tree , 0 , sizeof (tree)) ;
        tot = 0 ;
        rt = ++tot ;
        scanf ("%d" , &n) ;
        for (int i = 1 ; i <= n ; ++i)
        {
            scanf ("%d" , &num[i]) ;
            tree_Update (num[i] , rt) ;
        }
        int res = 0 ;
        for (int i = 1 ; i <= n ; ++i)
        {
            res = _max(res , tree_Query(num[i] , rt)) ;
        }
        printf ("%d\n" , res) ;
    }
}

