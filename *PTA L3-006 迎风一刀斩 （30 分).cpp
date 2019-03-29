/*

*PTA L3-006 迎风一刀斩 （30 分)
作者: 刘汝佳

给出两个多边形，问能不能组成一个矩形

很挫败，遇到刘汝佳大神的题目居然30分只得了26分

https://pintia.cn/problem-sets/994805046380707840/problems/994805051631976448

等以后回来看看说不定可以发现错误
*/



#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std ;

double eps = 1e-5 ;
const double PI = acos(-1) ;

int N ;
int k1 , k2 ;

double idx1[15] ;
double idy1[15] ;
double idx2[15] ;
double idy2[15] ;

int dian1[3] ;
int dian2[3] ;

bool is_zhijiao(int x1 , int y1 , int x2 , int y2 , int x3 , int y3)
{
    int xt1 = x1 - x2 ;
    int yt1 = y1 - y2 ;

    int xt2 = x3 - x2 ;
    int yt2 = y3 - y2 ;

    if (fabs(xt1 * xt2 + yt1 * yt2) > eps)
        return false ;
    else
        return true ;
}

double dis(double x1 , double y1 , double x2 , double y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) ;
}

double jiao(double x1 , double y1 , double x2 , double y2 , double x3 , double y3)
{
    double l1 = dis(x1 , y1 , x2 , y2) ;
    double l2 = dis(x3 , y3 , x2 , y2) ;
    double l3 = dis(x1 , y1 , x3 , y3) ;
    double sqrt_l1 = sqrt(l1) ;
    double sqrt_l2 = sqrt(l2) ;
    return acos((l1 + l2 - l3) / (2 * sqrt_l1 * sqrt_l2)) ;
}


double jiao1[3] ;
double jiao2[3] ;


int main ()
{
    scanf ("%d" , &N) ;
    while (N--)
    {
        scanf ("%d" , &k1) ;
        for (int i = 1 ; i <= k1 ; ++i)
        {
            scanf ("%lf%lf" , &idx1[i] , &idy1[i]) ;
        }
        dian1[0] = dian1[1] = 0 ;
        dian2[0] = dian2[1] = 0 ;

        idx1[k1 + 1] = idx1[1] ;
        idy1[k1 + 1] = idy1[1] ;

        idx1[0] = idx1[k1] ;
        idy1[0] = idy1[k1] ;

        scanf ("%d" , &k2) ;
        for (int i = 1 ; i <= k2 ; ++i)
        {
            scanf ("%lf%lf" , &idx2[i] , &idy2[i]) ;
        }

        int p = min(k1 , k2) ;
        int q = max(k1 , k2) ;
        if (!(p == 3 && q == 3 || p == 3 && q == 4 || p == 3 && q == 5 || p == 4 && q == 4))
        {
            printf ("NO\n") ;
            continue ;
        }

        idx2[k2 + 1] = idx2[1] ;
        idy2[k2 + 1] = idy2[1] ;

        idx2[0] = idx2[k2] ;
        idy2[0] = idy2[k2] ;

        int cnt1 = 0 ;
        int cnt2 = 0 ;

        for (int i = 1 ; i <= k1 ; ++i)
        {
            if (is_zhijiao(idx1[i - 1] , idy1[i - 1] , idx1[i] , idy1[i] , idx1[i + 1] , idy1[i + 1]))
                ++cnt1 ;
            else
            {
                if(dian1[0])
                {
                    dian1[1] = i ;
                    jiao1[1] = jiao(idx1[i - 1] , idy1[i - 1] , idx1[i] , idy1[i] , idx1[i + 1] , idy1[i + 1]) ;
                }
                else
                {
                    dian1[0] = i ;
                    jiao1[0] = jiao(idx1[i - 1] , idy1[i - 1] , idx1[i] , idy1[i] , idx1[i + 1] , idy1[i + 1]) ;
                }
            }
        }

        for (int i = 1 ; i <= k2 ; ++i)
        {
            if (is_zhijiao(idx2[i - 1] , idy2[i - 1] , idx2[i] , idy2[i] , idx2[i + 1] , idy2[i + 1]))
                ++cnt2 ;
            else
            {
                if(dian2[0])
                {
                    dian2[1] = i ;
                    jiao2[1] = jiao(idx2[i - 1] , idy2[i - 1] , idx2[i] , idy2[i] , idx2[i + 1] , idy2[i + 1]) ;
                }
                else
                {
                    dian2[0] = i ;
                    jiao2[0] = jiao(idx2[i - 1] , idy2[i - 1] , idx2[i] , idy2[i] , idx2[i + 1] , idy2[i + 1]) ;
                }
            }
        }

        //printf ("%d   %d\n" , cnt1   ,  cnt2) ;

        if (k1 == k2 && k1 == 4 && cnt1 == cnt2 && cnt1 == 4)
        {
            if (fabs(dis(idx1[1] , idy1[1] , idx1[2] , idy1[2]) - dis(idx2[1] , idy2[1] , idx2[2] , idy2[2])) < eps)
                printf ("YES\n") ;
            else if (fabs(dis(idx1[2] , idy1[2] , idx1[3] , idy1[3]) - dis(idx2[1] , idy2[1] , idx2[2] , idy2[2])) < eps)
                printf ("YES\n") ;
            else
                printf ("NO\n") ;
            continue ;
        }

        if (k1 - cnt1 != 2 || k2 - cnt2 != 2)
        {
            printf ("NO\n") ;
        }
        else
        {
            double p = dis(idx1[dian1[0]] , idy1[dian1[0]] , idx1[dian1[1]] , idy1[dian1[1]]) ;
            double q = dis(idx2[dian2[0]] , idy2[dian2[0]] , idx2[dian2[1]] , idy2[dian2[1]]) ;
            //printf ("p = %d q = %d\n" , p , q) ;
            if (fabs(p - q) > eps)
                printf ("NO\n") ;
            else
            {
                if (fabs(jiao1[0] + jiao2[0] - PI / 2) < eps || fabs(jiao1[0] + jiao2[0] - PI) < eps)
                    printf("YES\n") ;
                else if (fabs(jiao1[0] + jiao2[1] - PI / 2) < eps || fabs(jiao1[0] + jiao2[1] - PI) < eps)
                    printf("YES\n") ;
                else
                    printf ("NO\n") ;
            }
        }
    }
}


/*
8
3 0 0 1 0 1 1
3 0 0 1 1 0 1
3 0 0 1 0 1 1
3 0 0 1 1 0 2
4 0 4 1 4 1 0 0 0
4 4 0 4 1 0 1 0 0
3 0 0 1 1 0 1
4 2 3 1 4 1 7 2 7
5 10 10 10 12 12 12 14 11 14 10
3 28 35 29 35 29 37
3 7 9 8 11 8 9
5 87 26 92 26 92 23 90 22 87 22
5 0 0 2 0 1 1 1 2 0 2
4 0 0 1 1 2 1 2 0
4 0 0 0 1 1 1 2 0
4 0 0 0 1 1 1 2 0

YES
NO
YES
YES
YES
YES
NO
YES

*/
