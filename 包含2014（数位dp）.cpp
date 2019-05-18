#include <cstdio>
#include <cstring>
using namespace std ;

int dp[20][2][2][2][2] ;////从左到右依次为len，是否含2，是否含0，是否含1，是否含4

int num[20] ;

int l , r ;

int DFS(int pos , int s2 , int s0 , int s1 , int s4 , bool limit , bool fzero)
{
    if (pos == -1)
        return s2 && s0 && s1 && s4 ;
    if (!limit && !fzero && dp[pos][s2][s0][s1][s4] != -1)
        return dp[pos][s2][s0][s1][s4] ;
    int End = limit ? num[pos] : 9 ;
    int ans = 0 ;
    for (int i = 0 ; i <= End ; ++i)
    {
        int now2 = s2 , now0 = s0 , now1 = s1 , now4 = s4 ;
        if (s2 == 0)
            if (i == 2)
                now2 = 1 ;
        if (s0 == 0)
            if (!fzero && i == 0)
                now0 = 1 ;
        if (s1 == 0)
            if (i == 1)
                now1 = 1 ;
        if (s4 == 0)
            if (i == 4)
                now4 = 1 ;
        ans += DFS(pos - 1 , now2 , now0 , now1 , now4 , limit && i == End , fzero && !i) ;
    }
    return (limit || fzero) ? ans : dp[pos][s2][s0][s1][s4] = ans ;
}

int solve(int n)
{
    int len = 0 ;
    while (n)
    {
        num[len++] = n % 10 ;
        n /= 10 ;
    }
    return DFS(len - 1 , 0 , 0 , 0 , 0 , 1 , 1) ;
}

int main ()
{
    memset (dp , -1 , sizeof (dp)) ;
    while (scanf ("%d%d" , &l , &r))
    {
        printf ("%d\n" , solve(r) - solve(l - 1)) ;
    }
    return 0 ;
}
