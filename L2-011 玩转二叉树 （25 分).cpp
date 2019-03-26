/*
PTA 玩转二叉树

题意：
给出n，代表节点有n个
给出两个数组
第一个数组代表该二叉树的中序遍历
第二个数组代表该二叉树的前序遍历

要求把二叉树镜面反转后
输出二叉树的层序遍历


之前都没接触过这些遍历方式。。。
自己模拟了一下居然也成功了。
有点乱

*/


#include <stdio.h>
#include <queue>
using namespace std ;


const int maxn = 35 ;

int qian[maxn] , zhong[maxn] ;
int deep = 0 ;
struct Node
{
    int lson , rson ;
    int hei ;
    int val ;
}node[maxn];


int tot ;

int NewNode(int val)
{
    node[tot].val = val ;
    node[tot].lson = -1 ;
    node[tot].rson = -1 ;
    ++tot ;
    return tot - 1 ;
}

int Build (int ql , int qr , int zl , int zr)
{
    if (ql > qr)
        return -1 ;
    int now = NewNode(qian[ql]) ;

    int k = zl ;
    while (zhong[k] != qian[ql])
    {
        ++k ;
    }
    int lenl = k - zl ;
    node[now].lson = Build (ql + 1 , ql + lenl , zl , k - 1) ;
    node[now].rson = Build (ql + lenl + 1 , qr , k + 1 , zr) ;

    return now ;
}

void fan(int h , int hei)   //翻转
{
    node[h].hei = hei ;
    if (hei > deep)
        deep = hei ;
    node[h].lson = node[h].lson ^ node[h].rson ;
    node[h].rson = node[h].lson ^ node[h].rson ;
    node[h].lson = node[h].lson ^ node[h].rson ;

    if (node[h].lson != -1)
        fan(node[h].lson , hei + 1 ) ;
    if (node[h].rson != -1)
        fan(node[h].rson , hei + 1 ) ;
}


queue <int> res ;


void query()        //中序遍历
{
    queue <int> q ;
    q.push(0) ;
    while (!q.empty())
    {
        int now = q.front() ;
        q.pop() ;
        res.push(node[now].val) ;
        if (node[now].lson != -1)
            q.push(node[now].lson) ;
        if (node[now].rson != -1)
            q.push(node[now].rson) ;
    }
}


int main ()
{
    int n ;
    scanf ("%d" , &n) ;
    for (int i = 1 ; i <= n ; ++i)
        scanf ("%d" , &zhong[i]) ;
    for (int i = 1 ; i <= n ; ++i)
        scanf ("%d" , &qian[i]) ;

    Build (1 , n , 1 , n) ;
    fan(0 , 1) ;
    query() ;

    printf ("%d" , res.front()) ;
    res.pop() ;
    while (!res.empty())
    {
        printf (" %d" , res.front()) ;
        res.pop() ;
    }
}
