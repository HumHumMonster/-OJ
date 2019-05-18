#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std ;

#define LL long long

LL n , dp[25][13][3] ;
//dp[i][mod][j] 长度为 i ，余数为 mod ，状态为 j
int digit[25] ;


//status: 0:不含有13  1:不含有13但是尾数是1    2:含有13
LL DFS(int pos , int mod , int status , int limit)
{
    if (pos <= 0)
        return status == 2 && mod == 0 ;
    if (!limit && dp[pos][mod][status] != -1)
        return dp[pos][mod][status] ;
    LL ans = 0 ;
    int End = limit ? digit[pos] : 9 ;
    for (int i = 0 ; i <= End ; ++i)
    {
        int nmod = (mod * 10 + i) % 13 ;
        int nstatus = status ;
        //高位不含有13，并且末尾不是1。现在末尾添 1 返回1 状态
        if (status == 0 && i == 1)
            nstatus = 1 ;
        //高位不含13，且末尾是1，现在末尾添加的不是1返回0
        else if (status == 1 && i != 1 && i != 3)
            nstatus = 0 ;
        //高位不含13，且末尾是1，现在末尾添加3返回2状态
        else if (status == 1 && i == 3)
            nstatus = 2 ;
        ans += DFS(pos - 1 , nmod , nstatus , limit && i == End) ;
    }
    if (!limit)
        dp[pos][mod][status] = ans ;
    return ans ;
}

LL solve(LL x)
{
    int cnt = 0 ;
    while (x)
    {
        digit[++cnt] = x % 10 ;
        x /= 10 ;
    }
    digit[cnt + 1] = 0 ;
    return DFS(cnt , 0 , 0 , 1) ;
}

int main ()
{
    while (scanf ("%lld" , &n) != EOF)
    {
        memset (dp , -1 , sizeof (dp)) ;
        printf ("%lld\n" , solve(n)) ;
    }
    return 0 ;
}
