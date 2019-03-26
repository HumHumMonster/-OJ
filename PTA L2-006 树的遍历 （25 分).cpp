/*
PTA L2-006 树的遍历 （25 分)

又是一道二叉树题

给出二叉树的后序遍历和中序遍历
输出二叉树的层序遍历

*/


#include <stdio.h>
#include <queue>
using namespace std ;


int n ;
int zhong[45] ;
int hou[45] ;

struct Node
{
    int lson , rson , val ;
}node[45];

int tot = 0 ;
int NewNode(int val)
{
    node[tot].lson = node[tot].rson = -1 ;
    node[tot].val = val ;
    ++tot ;
    return tot - 1 ;
}

int Build (int hl , int hr , int zl , int zr)
{
    if (hl > hr)
        return -1 ;
    int now = NewNode(hou[hr]) ;
    int nowval = hou[hr] ;
    int k = zl ;
    while (zhong[k] != nowval)
        ++k ;
    int l = k - zl ;
    int r = zr - k ;
    node[now].lson = Build (hl , hl + l - 1 , zl , k - 1) ;
    node[now].rson = Build (hr - 1 - r + 1 , hr - 1 , k + 1 , zr) ;


    //2printf ("now = %d   val = %d   lson = %d   rson = %d\n" , now , node[now].val , node[now].lson , node[now].rson) ;
    return now ;
}

void Query()
{
    queue <int> res ;
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
    printf ("%d" , res.front()) ;
    res.pop() ;
    while (!res.empty())
    {
        printf (" %d" , res.front()) ;
        res.pop() ;
    }
}

int main ()
{
    scanf ("%d" , &n) ;
    for (int i = 1 ; i <= n ; ++i)
    {
        scanf ("%d" , &hou[i]) ;
    }
    for (int i = 1 ; i <= n ; ++i)
    {
        scanf ("%d" , &zhong[i]) ;
    }
    Build (1 , n , 1 , n) ;
    Query() ;
    return 0 ;
}
