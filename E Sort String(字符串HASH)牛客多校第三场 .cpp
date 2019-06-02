/*
E Sort String(字符串HASH)牛客多校第三场 .cpp


题目大意：一开始给出一个字符串S，定义字符串串T[i]=S[i,...,n]+S[1,...,i-1]（i=1,...,n）现在要对这n个字符串进行分类，将所有相同的串放到一个集合，同时对这几个集合按下标的字典序进行排序之后输出。

题目思路：
可以用KMP的next数组
但是这道题学会了字符串hash的一个模板
对于这个题，我们可以先将字符串S进行拼接，令SS=S+S，这样每个T[i]=SS[i,...,i+n-1]，然后再借助字符串hash对SS串进行处理，这样就可以在O(1)的时间里求出T[i]的hash值。接着再将hash值相同的串进行分类处理即可。

小小吐槽下，这个题居然卡常数，一开始怕精确度不够用双hash写的，居然T了，后面尝试了下用unsigned long long自然溢出来处理hash值就过了，还是有点小坑的。-，-
*/

#include <unordered_map>
#include <unordered_set>
#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <iterator>
#include <set>
using namespace std ;
#define LL long long
#define ULL unsigned long long
#define INF 0x3f3f3f3f
const double PI = acos(-1.0) ;
const double eps = 1e-8 ;

inline int _max(int a , int b){return a > b ? a : b ;}
inline int _min(int a , int b){return a < b ? a : b ;}
inline int _abs(int a){return a > 0 ? a : -a ;}
inline double _max(double a , double b){return a > b ? a : b ;}
inline double _min(double a , double b){return a < b ? a : b ;}
inline double _fabs(double a){return a > 0 ? a : -a ;}
inline LL _max(LL a , LL b){return a > b ? a : b ;}
inline LL _min(LL a , LL b){return a < b ? a : b ;}
inline LL _labs(LL a){return a > 0 ? a : -a ;}

int sgn(double x)   //判断正负，正为1，零为0，负为-1
{
    if (_fabs(x) < eps) return 0 ;
    else if (x < 0) return -1 ;
    else return 1 ;
}


/***************************************************************/

const int has = 99959;

const int MAXN = 2e6 + 10 ;

char str[MAXN];
ULL H[MAXN],P[MAXN];
unordered_map<ULL,int>mp;
void Hash(int n){
    H[0]=P[0]=1;
    for(int i=1;i<=n;i++){
        H[i]=H[i-1]*has+str[i]-'0'+1;
        P[i]=P[i-1]*has;
    }
}
ULL get_hash(int l,int r){
    return H[r]-H[l-1]*P[r-l+1];
}
vector<int>ans[MAXN];

int main(){
    //FIN;
    scanf("%s",str+1);
    int len=strlen(str+1);
    for(int i=len+1;i<=2*len;i++)
        str[i]=str[i-len];
    str[2*len+1]='\0';
    Hash(2*len);
    int num=0;
    for(int i=1;i<=len;i++){
        ULL cnt=get_hash(i,i+len-1);
        if(mp[cnt]==0){
            mp[cnt]=++num;
            ans[num].push_back(i-1);
        } else{
            ans[mp[cnt]].push_back(i-1);
        }
    }
    printf("%d\n",num);
    for(int i=1;i<=num;i++){
        printf("%d ",ans[i].size());
        for(int x:ans[i])
            printf("%d ",x);
        printf("\n");
    }
    return 0;
}
