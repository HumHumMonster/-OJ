/*
PTA L3-002 特殊堆栈 （30 分)

堆栈是一种经典的后进先出的线性结构，相关的操作主要有“入栈”（在堆栈顶插入一个元素）和“出栈”（将栈顶元素返回并从堆栈中删除）。本题要求你实现另一个附加的操作：“取中值”——即返回所有堆栈中元素键值的中值。给定 N 个元素，如果 N 是偶数，则中值定义为第 N/2 小元；若是奇数，则为第 (N+1)/2 小元。

输入格式：
输入的第一行是正整数 N（≤10e5）。随后 N 行，每行给出一句指令，为以下 3 种之一：

Push key
Pop
PeekMedian

其中 key 是不超过 10e5 的正整数；Push 表示“入栈”；Pop 表示“出栈”；PeekMedian 表示“取中值”。

输出格式：
对每个 Push 操作，将 key 插入堆栈，无需输出；对每个 Pop 或 PeekMedian 操作，在一行中输出相应的返回值。若操作非法，则对应输出 Invalid。


学到了！
这道题要快速求一个动态数组的中位数，
正常来说我们会用一个权值线段树来求

但是有一个题解用的是vector结合lower_bound做到的
又好写，速度又快！

学到了学到了。。。

https://pintia.cn/problem-sets/994805046380707840/problems/994805053695574016
*/

#include <stdio.h>
#include <vector>
#include <stack>
#include <iostream>
#include <iterator>
using namespace std ;

string str ;
vector <int> V ;

stack <int> S ;

vector <int> :: iterator it ;

char s[20] ;

int main ()
{
    int T ;
    scanf ("%d" , &T) ;
    while (T--)
    {
        scanf ("%s" , s) ;
        str = s ;
        if (str == "Pop")
        {
            if (S.size() == 0)
            {
                printf("Invalid\n") ;
            }
            else
            {
                printf ("%d\n" , S.top()) ;
                it = lower_bound(V.begin() , V.end() , S.top()) ;
                V.erase (it) ;
                S.pop() ;
            }
        }
        else if (str == "PeekMedian")
        {
            if (S.size() == 0)
            {
                printf("Invalid\n") ;
            }
            else
            {
                int p = S.size() ;
                if (p % 2 == 0)
                {
                    p = p / 2 ;
                }
                else
                {
                    p = (p + 1) / 2 ;
                }
                printf ("%d\n" , V[p - 1]) ;
            }
        }
        else
        {
            int a ;
            scanf ("%d" , &a) ;
            S.push(a) ;
            it = lower_bound(V.begin() , V.end() , a) ;
            V.insert (it , a) ;
        }
    }

}

