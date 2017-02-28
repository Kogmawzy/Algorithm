#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define maxm 100
#define maxn 50
int u[maxm],v[maxm],w[maxm];    //边的两端点、权值
int r[maxm];                    //排序后第i小的边的序号存在r[i] 
int p[maxn];                    //保存第i个节点的父亲 
int n,m;
int cmp(const int i,const int j)
{
    return w[i]<w[j];
} 
int find(int x)                 //并查集查找公共祖先 
{
    return p[x]==x?x:p[x]=find(p[x]);
}
int Kruskal() 
{
    int ans=0;
    for(int i=0;i<n;i++) p[i]=i;    //初始化并查集
    for(int i=0;i<m;i++) r[i]=i;
    sort(r,r+m,cmp);
    for(int i=0;i<m;i++)
    {
        int e=r[i]; 
        int x=find(u[e]); int y=find(v[e]);         //找出两端点的集合编号
        if(x!=y){
            ans+=w[e];
            p[x]=y;
        } 
     } 
     return ans;
}
