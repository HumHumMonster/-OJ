/*

PTA L3-004 肿瘤诊断 （30 分)

搜索水题,用的BFS

以为这么大的数据范围开int数组应该要爆了，所以用的bool

过了以后改成int居然也能过hhh，涨知识。

中间还Debug了一小会儿

*/

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std ;

struct Node
{
    int x ;
    int y ;
    int z ;

    Node (int a , int b , int c)
    {
        x = a ;
        y = b ;
        z = c ;
    }
};

vector <Node> V ;

int M , N , L , T ;

bool num[65][1290][130] ;
bool vis[65][1290][130] ;

int res = 0 ;
int a ;

int disx[6] = {0 , 0 , 1 , -1 , 0 , 0} ;
int disy[6] = {0 , 1 , 0 , 0 , -1 , 0} ;
int disz[6] = {1 , 0 , 0 , 0 , 0 , -1} ;

bool check(int x , int y , int z)
{
    if (vis[x][y][z] || !num[x][y][z])
        return false ;
    if (x <= 0 || x > L || y <= 0 || y > M || z <= 0 || z > N)
        return false ;
    return true ;
}


int Bfs(int x ,int y , int z)
{
    queue <Node> q ;
    q.push(Node (x , y , z)) ;
    vis[x][y][z] = 1 ;
    int res = 0 ;
    while (!q.empty())
    {
        ++res ;
        int nowx = q.front().x ;
        int nowy = q.front().y ;
        int nowz = q.front().z ;
        q.pop() ;
        int newx , newy , newz ;
        for (int i = 0 ; i < 6 ; ++i)
        {
            newx = nowx + disx[i] ;
            newy = nowy + disy[i] ;
            newz = nowz + disz[i] ;
            if (check(newx , newy , newz))
            {
                q.push(Node(newx , newy , newz)) ;
                vis[newx][newy][newz] = true ;
            }
        }
    }
    return res ;
}

void Show()
{
    printf ("\n\n") ;
    for (int i = 1 ; i <= L ; ++i)
    {
        for (int j = 1 ; j <= M ; ++j)
        {
            for (int k = 1 ; k <= N ; ++k)
            {
                if (num[i][j][k])
                    printf ("1 ") ;
                else
                    printf ("0 ") ;
            }
            printf ("\n") ;
        }
        printf ("\n\n") ;
    }
    printf ("\n\n") ;
}

int main ()
{
    scanf ("%d%d%d%d" , &M , &N , &L , &T) ;
    for (int i = 1 ; i <= L ; ++i)
    {
        for (int j = 1 ; j <= M ; ++j)
        {
            for (int k = 1 ; k <= N ; ++k)
            {
                vis[i][j][k] = false ;
                scanf ("%d" , &a) ;
                if (a)
                {
                    num[i][j][k] = true ;
                    V.push_back(Node (i , j , k)) ;
                }
                else
                    num[i][j][k] = false ;
            }
        }
    }

    //Show() ;

    for (int i = 0 ; i < V.size() ; ++i)
    {
        if (vis[V[i].x][V[i].y][V[i].z])
            continue ;
        int p = Bfs(V[i].x , V[i].y , V[i].z) ;
        if (p >= T)
        {
            res += p ;
        }
        //printf ("%d %d %d   res = %d\n" , V[i].x , V[i].y , V[i].z , res) ;
    }
    printf ("%d" ,res) ;
}

/*

1 1 1   res = 22
3 1 1   res = 24
3 2 2   res = 24
5 1 4   res = 24
5 2 4   res = 24
5 3 1   res = 24

*/


