/*
PTA L2-005 集合相似度 （25 分)

给出一个整数N代表有N个整数集合
随后的N行，每行对应一个集合，每个集合首先给出整数M代表该集合整数的个数
给出一个T，代表T次询问。
每次询问给出两个数，代表两个集合的序号
Nc是两个集合都有的不相等整数的个数，
Nt是两个集合一共有的不相等整数的个数。
求Nc/Nt

思路：用set还有iterator


*/

#include <iterator>
#include <set>
#include <stdio.h>
using namespace std ;

int N ;
const int maxn = 55 ;

set <int> S[maxn] ;
int a ;

int main ()
{
    scanf ("%d" , &N) ;
    for (int i = 1 ; i <= N ; ++i)
    {
        int n ;
        scanf ("%d" , &n) ;
        while (n--)
        {
            scanf ("%d" , &a) ;
            S[i].insert(a) ;
        }
    }
    int T ;
    scanf ("%d" , &T) ;
    while (T--)
    {
        int a , b ;
        scanf ("%d%d" , &a , &b) ;
        double nc = 0 ;
        double nt = (double)S[a].size() ;
        for (set <int> :: iterator it = S[b].begin() ; it != S[b].end() ; ++it)
        {
            if (S[a].find(*it) == S[a].end())
                nt += 1 ;
            else
                nc += 1 ;
        }
            printf ("%.2f%%\n" , nc / nt * 100) ;
    }
}
