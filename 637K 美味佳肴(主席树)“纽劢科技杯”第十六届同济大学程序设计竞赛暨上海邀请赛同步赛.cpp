/*
637K 美味佳肴(主席树)“纽劢科技杯”第十六届同济大学程序设计竞赛暨上海邀请赛同步赛.cpp

第一次自己不看模板的写出主席树啦~！

这道题也真的很有意思BZOJ.4299.Codechef FRBSUM(主席树)的原题
ps：本题跟[LOJ2174]【FJOI2016】神秘数 为同一题意

数集S的ForbiddenSum定义为无法用S的某个子集（可以为空）的和表示的最小的非负整数。
例如，S={1,1,3,7}，则它的子集和中包含0(S’=∅)，1(S’={1})，2(S’={1,1})，3(S’={3})，4(S’={1,3})，5(S' = {1, 1, 3})，但是它无法得到6。因此S的ForbiddenSum为6。
给定一个序列A，你的任务是回答该数列的一些子区间所形成的数集的ForbiddenSum是多少。

假设当前集合能凑出[1,max]这些数，此时再加入一个数x：
1.若x<=max+1，则必定能继续凑出[max+1,max+x]这些数，新的max=max+x；
2.若x>max+1，则max+1这个数必定凑不出来，也就会成为当前的forbiddennum。
那么开一颗主席树，每次查询求出区间[L,R]中值在[1,max+1]中的数的和来更新max，直到max+1凑不出来为止；
这样子做每次max至少翻倍，因此每次查询至多更新logn次，总的时间复杂度就是O(nlog2n)

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

const int MAXN =  40 * 1e5 + 10 ;
int rts[MAXN] ;
LL val[MAXN] ;
LL num[MAXN] ;
int ls[MAXN] , rs[MAXN] ;
int N , M ;
LL tmp , ans ;
int l , r , tot = 0 ;
LL maxx = 0 ;

void Build (int &u , int k , int l , int r , LL v)
{
    u = ++tot ;
    val[u] = val[k] + v ;
    ls[u] = ls[k] ;
    rs[u] = rs[k] ;
    if (l == r)
        return ;
    int mid = (l + r) >> 1 ;
    if (v <= mid)
        Build (ls[u] , ls[k] , l , mid , v) ;
    else
        Build (rs[u] , rs[k] , mid + 1 , r , v) ;
}

LL Query(int u , int k , int l , int r , int v)
{
    if (l == r)
        return val[k] - val[u] ;
    int mid = (l + r) >> 1 ;
    if (v <= mid)
        return Query(ls[u] , ls[k] , l , mid , v) ;
    else
        return Query(rs[u] , rs[k] , mid + 1 , r , v) + val[ls[k]] - val[ls[u]] ;
}

int main ()
{
    scanf ("%d" , &N) ;
    for (int i = 1 ; i <= N ; ++i)
    {
        scanf ("%lld" , &num[i]) ;
        maxx = _max(maxx , num[i]) ;
    }
    for (int i = 1 ; i <= N ; ++i)
    {
        Build (rts[i] , rts[i - 1] , 1 , maxx , num[i]) ;
    }
    scanf ("%d" , &M) ;
    while (M--)
    {
        scanf ("%d%d" , &l , &r) ;
        tmp = Query(rts[l - 1] , rts[r] , 1 , maxx , 1);
        ans = 1 ;
        while (ans <= tmp)
        {
            ans = tmp + 1 ;
            tmp = Query(rts[l - 1] , rts[r] , 1 , maxx , ans) ;
        }
        printf ("%d\n" , ans) ;
    }
    return 0 ;
}
