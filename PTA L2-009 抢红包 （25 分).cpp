/*
PTA L2-009 抢红包 （25 分)

输入格式：
输入第一行给出一个正整数N（≤10e4），即参与发红包和抢红包的总人数，则这些人从1到N编号。随后N行，第i行给出编号为i的人发红包的记录，格式如下：K N1 P1⋯NK PK

其中K（0≤K≤20）是发出去的红包个数，Ni是抢到红包的人的编号，Pi（>0）是其抢到的红包金额（以分为单位）。注意：对于同一个人发出的红包，每人最多只能抢1次，不能重复抢。

输出格式：
按照收入金额从高到低的递减顺序输出每个人的编号和收入金额（以元为单位，输出小数点后2位）。每个人的信息占一行，两数字间有1个空格。如果收入金额有并列，则按抢到红包的个数递减输出；如果还有并列，则按个人编号递增输出。

输入样例：
10
3 2 22 10 58 8 125
5 1 345 3 211 5 233 7 13 8 101
1 7 8800
2 1 1000 2 1000
2 4 250 10 320
6 5 11 9 22 8 33 7 44 10 55 4 2
1 3 8800
2 1 23 2 123
1 8 250
4 2 121 4 516 7 112 9 10


输出样例：
1 11.63
2 3.63
8 3.63
3 2.11
7 1.69
6 -1.67
9 -2.18
10 -3.26
5 -3.26
4 -12.32
*/



#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std ;

int N ;
const int maxn = 1e4 + 10 ;
double money[maxn] ;
int id[maxn] ;
int num[maxn] ;

const double eps = 1e-8 ;


bool cmp(int a , int b)
{
    if (fabs(money[a] - money[b]) < eps)
    {
        if (num[a] == num[b])
        {
            return a < b ;
        }
        return num[a] > num[b] ;
    }
    return money[a] > money[b] ;
}

int main ()
{
    scanf ("%d" , &N) ;
    for (int i = 1 ; i <= N ; ++i)
    {
        id[i] = i ;
    }
    for (int i = 1 ; i <= N ; ++i)
    {
        int k ;
        scanf ("%d" , &k) ;
        num[i] = k ;
        int a ;
        double b ;
        while (k--)
        {
            scanf ("%d%lf" , &a , &b) ;
            money[a] += b ;
            money[i] -= b ;
        }
    }
    sort (id + 1 , id + 1 + N , cmp) ;
    for (int i = 1 ; i <= N ; ++i)
    {
        printf ("%d %.2f\n" , id[i] , money[id[i]] / 100) ;
    }
}
