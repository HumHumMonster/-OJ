/*
PTA 链表去重

给定一个带整数键值的链表 L，你需要把其中绝对值重复的键值结点删掉。
即对每个键值 K，只有第一个绝对值等于 K 的结点被保留。

首先输出去重后的链表，然后输出被删除的链表。每个结点占一行，按输入的格式输出。
*/


#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
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

int head , n ;

const int maxn = 1e5 + 10 ;

struct Node
{
    int val ;
    int nex ;
}node[maxn];

int a , b , c ;

queue <int> res , cost ;

int vis[maxn] ;


int main ()
{
    scanf ("%d%d" , &head , &n) ;
    for (int i = 1 ; i <= n ; ++i)
    {
        scanf ("%d%d%d" , &a , &b , &c) ;
        node[a].val = b ;
        node[a].nex = c ;
    }
    for (int i = head ; i != -1 ; i = node[i].nex)
    {
        int now = _abs(node[i].val) ;
        if (vis[now] == 1)
        {
            cost.push(i) ;
        }
        else
        {
            vis[now] = 1 ;
            res.push(i) ;
        }
    }
    while (!res.empty())
    {
        int now =  res.front() ;
        res.pop() ;
        if (res.empty())
        {
            printf ("%05d %d -1\n" , now , node[now].val) ;
        }
        else
        {
            printf ("%05d %d %05d\n" , now , node[now].val , res.front()) ;
        }
    }
    while (!cost.empty())
    {
        int now =  cost.front() ;
        cost.pop() ;
        if (cost.empty())
        {
            printf ("%05d %d -1\n" , now , node[now].val) ;
        }
        else
        {
            printf ("%05d %d %05d\n" , now , node[now].val , cost.front()) ;
        }
    }
}
