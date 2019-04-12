/*
134A 牛客

https://ac.nowcoder.com/acm/contest/134/A

给出一个数组，问删除、其中一条边，剩下的边组成的三角形的周长最长是多少

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



LL a , b , c , res = -1 , res1 = -1 , res2 = -1 , res3 = -1 ;

vector <LL> V ;

const int maxn = 1e5 + 10 ;

LL num[maxn] ;

int n , m ;

int main ()
{
    scanf ("%d%d" , &n , &m) ;
    for (int i = 1 ; i <= n ; ++i)
    {
        scanf ("%lld" , &num[i]) ;
        V.push_back(num[i]) ;
    }
    sort (V.begin() , V.end()) ;
//    for (int i = 0 ; i <= V.size() - 1 ; ++i)
//        printf ("%d " , V[i]) ;
//    printf ("\n") ;
    for (int i = V.size() - 1 ; i >= 2 ; --i)
    {
        if (V[i] < V[i - 1] + V[i - 2])
        {
            a = V[i] ;
            b = V[i - 1] ;
            c = V[i - 2] ;
            res = a + b + c ;
            V.erase(V.begin() + i - 2) ;
            V.erase(V.begin() + i - 2) ;
            V.erase(V.begin() + i - 2) ;
            break ;
        }
        V.erase(V.begin() + i) ;
    }
    //求res1
    V.push_back(c) ;
    V.push_back(b) ;
    for (int i = V.size() - 1 ; i >= 2 ; --i)
    {
        if (V[i] < V[i - 1] + V[i - 2])
        {
            res1 = V[i] + V[i - 1] + V[i - 2] ;
            break ;
        }
    }
    V.erase(V.end() - 1) ;
    V.erase(V.end() - 1) ;

    //求res2
    V.push_back(c) ;
    V.push_back(a) ;
    for (int i = V.size() - 1 ; i >= 2 ; --i)
    {
        if (V[i] < V[i - 1] + V[i - 2])
        {
            res2 = V[i] + V[i - 1] + V[i - 2] ;
            break ;
        }
    }
    V.erase(V.end() - 1) ;
    V.erase(V.end() - 1) ;


    //求res3
    V.push_back(b) ;
    V.push_back(a) ;
    for (int i = V.size() - 1 ; i >= 2 ; --i)
    {
        if (V[i] < V[i - 1] + V[i - 2])
        {
            res3 = V[i] + V[i - 1] + V[i - 2] ;
            break ;
        }
    }
//    for (int i = 0 ; i <= V.size() - 1 ; ++i)
//        printf ("%d " , V[i]) ;
    int now ;
    while (m--)
    {
        scanf ("%d" , &now) ;
        if (num[now] == a)
            printf ("%lld\n" , res1) ;
        else if (num[now] == b)
            printf ("%lld\n" , res2) ;
        else if (num[now] == c)
            printf ("%lld\n" , res3) ;
        else
            printf ("%lld\n" , res) ;
    }
}
