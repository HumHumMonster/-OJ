http://114.116.18.96/problem.php?id=1363
#include <stdio.h>
#include <string.h>
using namespace std ;

class Weiqi
{
    char ch ;
    char str[10][10] ;
    char last[1000][10][10] ;
    int vis[10][10] ;
    int dirx[4] = {0 , 1 , 0 , -1} ;
    int diry[4] = {1 , 0 , -1 , 0} ;
    int Case ;
    public :
    void init()
    {
        Case = 0 ;
        memset (str , '+' , sizeof (str)) ;
    }

    void check(char ch)
    {
        memset (vis , 0 , sizeof (vis)) ;
        for (int t = 1 ; t <= 81 ; ++t)
        {
            for (int i = 1 ; i <= 9 ; ++i)
            {
                for (int j = 1 ; j <= 9 ; ++j)
                {
                    if (str[i][j] == ch)
                    for (int k = 0 ; k < 4 ; ++k)
                    {
                        int nowx = i + dirx[k] ;
                        int nowy = j + diry[k] ;
                        if (nowx < 1 || nowx > 9 || nowy < 1 || nowy > 9)
                            continue ;
                        if (str[nowx][nowy] == '+' || (vis[nowx][nowy] == 1 && str[i][j] == str[nowx][nowy]))
                        {
                            vis[i][j] = 1 ;
                            break ;
                        }
                    }
                }
            }
        }
    }
    void Gaming(int a , int b , int c)
    {
        if (a == 1)
            ch = '#' ;
        else
            ch = 'o' ;
        ++Case ;
        if (str[b][c] == 'o' || str[b][c] == '#')
        {
            for (int i = 1 ; i <= 9 ; ++i)
                for (int j = 1 ; j <= 9 ; ++j)
                    last[Case][i][j] = str[i][j] ;
            return ;
        }
        if (a == 1)
            str[b][c] = 'o' ;
        else
            str[b][c] = '#' ;

        check(ch) ;

        for (int i = 1 ; i <= 9 ; ++i)
            for (int j = 1 ; j <= 9 ; ++j)
                if (str[i][j] == ch && vis[i][j] == 0)
                    str[i][j] = '+' ;

        if (a == 1)
            ch = 'o' ;
        else
            ch = '#' ;
        check(ch) ;
        if (vis[b][c] == 0)
        {
            for (int i = 1 ; i <= 9 ; ++i)
                for (int j = 1 ; j <= 9 ; ++j)
                    str[i][j] = last[Case - 1][i][j] ;
        }
        else if (Case >= 3)
        {
            bool flag = true ;
            for (int i = 1 ; i <= 9 ; ++i)
            {
                for (int j = 1 ; j <= 9 ; ++j)
                {
                    if (str[i][j] != last[Case - 2][i][j])
                    {
                        flag = false ;
                        break ;
                    }
                }
                if (!flag)
                    break ;
            }
            if (flag)
            {
                for (int i = 1 ; i <= 9 ; ++i)
                    for (int j = 1 ; j <= 9 ; ++j)
                        str[i][j] = last[Case - 1][i][j] ;
            }
        }
        for (int i = 1 ; i <= 9 ; ++i)
            for (int j = 1 ; j <= 9 ; ++j)
                last[Case][i][j] = str[i][j] ;
    }
    void Show()
    {
        printf ("     1  2  3  4  5  6  7  8  9\n") ;
        for (int i = 1 ; i <= 9 ; ++i)
        {
            printf (" %d " , i) ;
            for (int j = 1 ; j <= 9 ; ++j)
            {
                printf ("  %c" , str[i][j]) ;
            }
            printf ("\n") ;
        }
    }
};


int a , b , c ;


Weiqi wq ;


int main ()
{
    wq.init() ;
    while (scanf ("%d%d%d" , &a , &b , &c) != EOF)
    {
        wq.Gaming(a , b , c) ;
    }
    wq.Show() ;
}
