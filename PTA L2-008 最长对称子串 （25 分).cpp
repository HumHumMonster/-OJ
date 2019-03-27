/*
PTA L2-008 最长对称子串 （25 分)

输入一个字符串，输出最长回文串的长度

回忆了一下马拉车算法。水题

*/



#include <iostream>
#include <stdio.h>
using namespace std ;

string str ;

int res ;

char Ma[2005] ;
int Mp[2005] ;



inline int _min(int a , int b){return a < b ? a : b ;}

void Manacher(string s)
{
    int len = str.size() ;
    int l = 0 ;
    Ma[l++] = '$' ;
    Ma[l++] = '#' ;
    for (int i = 0 ; i < len ; ++i)
    {
        Ma[l++] = s[i] ;
        Ma[l++] = '#' ;
    }
    Ma[l] = 0 ;
    int mx = 0 , id = 0 ;
    for (int i = 0 ; i < l ; ++i)
    {
        Mp[i] = mx > i ? _min (Mp[2 * id - i] , mx - i) : 1 ;
        while (Ma[i + Mp[i]] == Ma[i - Mp[i]])
            ++Mp[i] ;
        if (Mp[i] > res)
            res = Mp[i] ;
        if (i + Mp[i] > mx)
        {
            mx = i + Mp[i] ;
            id = i ;
        }
    }
}


int main ()
{
    getline(cin , str) ;
    Manacher(str) ;
    printf ("%d" , res - 1) ;
}
