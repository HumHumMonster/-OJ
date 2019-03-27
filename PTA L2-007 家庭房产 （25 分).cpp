/*

PTA L2-007 家庭房产 （25 分)
输入第一行给出一个正整数N（≤1000），随后N行，每行按下列格式给出一个人的房产：
编号 父 母 k 孩子1 ... 孩子k 房产套数 总面积。
其中编号是每个人独有的一个4位数的编号；父和母分别是该编号对应的这个人的父母的编号（如果已经过世，则显示-1）；
k（0≤k≤5）是该人的子女的个数；孩子i是其子女的编号。
输出格式：
首先在第一行输出家庭个数（所有有亲属关系的人都属于同一个家庭）。随后按下列格式输出每个家庭的信息：

家庭成员的最小编号 家庭人口数 人均房产套数 人均房产面积
其中人均值要求保留小数点后3位。家庭信息首先按人均面积降序输出，若有并列，则按成员编号的升序输出。

输入样例：
10
6666 5551 5552 1 7777 1 100
1234 5678 9012 1 0002 2 300
8888 -1 -1 0 1 1000
2468 0001 0004 1 2222 1 500
7777 6666 -1 0 2 300
3721 -1 -1 1 2333 2 150
9012 -1 -1 3 1236 1235 1234 1 100
1235 5678 9012 0 1 50
2222 1236 2468 2 6661 6662 1 300
2333 -1 3721 3 6661 6662 6663 1 100

输出样例：
3
8888 1 1.000 1000.000
0001 15 0.600 100.000
5551 4 0.750 100.000


//思路：模拟，用set去重
*/


#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iterator>
#include <set>
using namespace std ;

int N ;

int id ;
const int maxn = 1e4 + 10 ;

int fa[maxn] ;
double num[maxn] ;
double num_fang[maxn] ;
double mianji[maxn] ;

#define eps 1e-8

int find_fa(int x)
{
    if (fa[x] == x)
        return x ;
    return fa[x] = find_fa(fa[x]) ;
}

void unit_fa(int a , int b)
{
    int p = find_fa(a) ;
    int q = find_fa(b) ;
    if (p == q)
        return ;
    if (p < q)
    {
        num[p] += num[q] ;
        fa[q] = p ;
    }
    else
    {
        num[q] += num[p] ;
        fa[p] = q ;
    }
}

set <int> peo ;
vector <int> res ;

bool cmp(int a , int b)
{
    if (mianji[a] / num[a] == mianji[b] / num[b])
    {
        return a < b ;
    }
    else
        return mianji[a] / num[a] > mianji[b] / num[b] ;
}

int main ()
{
    for (int i = 0 ; i < maxn ; ++i)
    {
        fa[i] = i ;
        num[i] = 1 ;
    }
    scanf ("%d" , &N) ;

    for (int i = 1 ; i <= N ; ++i)
    {
        scanf ("%d" , &id) ;
        peo.insert(id) ;
        int now ;
        scanf ("%d" , &now) ;
        if (now != -1)
        {
            unit_fa(now , id) ;
            peo.insert(now) ;
        }
        scanf ("%d" , &now) ;
        if (now != -1)
        {
            unit_fa(now , id) ;
            peo.insert(now) ;
        }
        int k ;
        scanf ("%d" , &k) ;
        while (k--)
        {
            scanf ("%d" , &now) ;
            peo.insert(now) ;
            unit_fa(now , id) ;
        }
        double nn ;
        scanf ("%lf" , &nn) ;
        num_fang[id] = nn ;


        scanf ("%lf" , &nn) ;
        mianji[id] = nn ;
        //printf ("i = %d\n" , i) ;
    }

    for (set<int>::iterator it = peo.begin() ; it != peo.end() ; ++it)
    {
        int now = find_fa(*it) ;
        if (now != *it)
        {
            num_fang[now] += num_fang[*it] ;
            mianji[now] += mianji[*it] ;
        }
        else
            res.push_back(now) ;
    }
    sort (res.begin() , res.end() , cmp) ;
    printf ("%d\n" , res.size()) ;
    for (int i = 0 ; i < res.size() ; ++i)
    {
        printf ("%04d %.0f %.3f %.3f\n" , res[i] , num[res[i]] , num_fang[res[i]] / num[res[i]] , mianji[res[i]] / num[res[i]]) ;
    }
}
