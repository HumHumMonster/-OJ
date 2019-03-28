/*
PTA L3-001 凑零钱 （30 分)

有n个硬币，每个硬币都有自己的面值
问能不能凑出m
能的话输出最小序列
不能输出No solution

最早想用vector结合dp来写。。。
无奈一直过不了
7 9
1 1 1 1 3 4 5

后来用Dfs才过的。

地址：https://pintia.cn/problem-sets/994805046380707840/problems/994805054207279104
*/

#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

const int maxn = 1e4 + 10 ;

stack <int> res ;


int n , m ;
int num[maxn] ;

int sum = 0 ;

bool flag = false ;

bool Dfs(int now , int sum)
{
    //printf ("num = %d now = %d  sum = %d\n" , num[now] ,  now , sum) ;
    if (sum == m)
    {
        flag = true ;
        return true ;
    }
    if (now == n + 1 || sum > m)
        return false ;
    if(Dfs(now + 1 , sum + num[now]))
    {
        res.push(num[now]) ;
        return true ;
    }
    else if (Dfs(now + 1 , sum))
    {
        return true ;
    }
}



int main ()
{
    scanf ("%d%d" , &n , &m) ;
    for (int i = 1 ; i <= n ; ++i)
    {
        scanf ("%d" , &num[i]) ;
        sum += num[i] ;
    }
    sort (num + 1 , num + 1 + n) ;
    if (sum < m)
    {
        printf ("No Solution") ;
        return 0 ;
    }
    Dfs(0 , 0) ;
    if (!flag)
    {
        printf ("No Solution") ;
        return 0 ;
    }
    res.pop() ;
    printf ("%d" , res.top()) ;
    res.pop() ;
    while (!res.empty())
    {
        printf (" %d" , res.top()) ;
        res.pop() ;
    }
}

/*
7 9
1 1 1 1 3 4 5
*/
