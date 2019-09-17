http://114.116.18.96/problem.php?id=1363
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std ;

class Weiqi
{
    char ch ;                           //代表接下来要删去的棋子类型
    char str[10][10] ;                  //当前棋盘
    char last[1000][10][10] ;           //棋盘历史记录
    int vis[10][10] ;                   //查找时标记
    int dirx[4] = {0 , 1 , 0 , -1} ;
    int diry[4] = {1 , 0 , -1 , 0} ;
    int Case ;      //已经操作的步数
    public :
    void init()     //初始化棋盘
    {
        Case = 0 ;
        memset (str , '+' , sizeof (str)) ;
    }

    void check(char ch)         //标记ch类型的棋子
    {
        memset (vis , 0 , sizeof (vis)) ;
        //如果棋子周围有空位，说明这个棋子是活子
        //周围有相同棋子，并且这个棋子为活子，那么当前棋子也是活子
        //vis标记为1的不要删，为0的要删
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
        //如果下了白棋，接下来就要先删黑棋再删白棋
        //反之同理
        if (a == 1)
            ch = '#' ;
        else
            ch = 'o' ;

        ++Case ;            //步数加一
        if (str[b][c] == 'o' || str[b][c] == '#')           //如果要下棋的位置已经有子了，就忽略这一步
        {
            for (int i = 1 ; i <= 9 ; ++i)                  //存放棋盘历史
                for (int j = 1 ; j <= 9 ; ++j)
                    last[Case][i][j] = str[i][j] ;
            return ;
        }

        if (a == 1)                     //把棋子放入
            str[b][c] = 'o' ;
        else
            str[b][c] = '#' ;

        check(ch) ;                     //删除对方棋子
        //vis标记为1的不要删，为0的要删
        for (int i = 1 ; i <= 9 ; ++i)
            for (int j = 1 ; j <= 9 ; ++j)
                if (str[i][j] == ch && vis[i][j] == 0)
                    str[i][j] = '+' ;

        //删除自己的棋子（说不定走到禁入点了）
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

        //如果这是第三步以上
        else if (Case >= 3)
        {
            //如果这一步走后和两步之前的一模一样
            //说明棋局可以一直循环不变下去，这在围棋是不接受的
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
            //如果和两步之前的一模一样
            //返回上一步（即取消这一步）
            if (flag)
            {
                for (int i = 1 ; i <= 9 ; ++i)
                    for (int j = 1 ; j <= 9 ; ++j)
                        str[i][j] = last[Case - 1][i][j] ;
            }
        }
        //存储棋盘历史
        for (int i = 1 ; i <= 9 ; ++i)
            for (int j = 1 ; j <= 9 ; ++j)
                last[Case][i][j] = str[i][j] ;
    }
    //展示棋盘的函数
    void Show()
    {
        cout << "     1  2  3  4  5  6  7  8  9" << endl ;
        for (int i = 1 ; i <= 9 ; ++i)
        {
            cout << " " << i << " " ;
            for (int j = 1 ; j <= 9 ; ++j)
            {
                cout << "  " << str[i][j] ;
            }
            cout << endl ;
        }
    }
};


int a , b , c ;


Weiqi wq ;


int main ()
{
    wq.init() ;
    while (cin >> a >> b >> c)
    {
        wq.Gaming(a , b , c) ;
    }
    wq.Show() ;
}
