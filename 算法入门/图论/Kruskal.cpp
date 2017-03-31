#include <iostream>
#include <algorithm> 
using namespace std;
#define maxn 105
struct Eage{
    int from,to;
    long long cost;
}E[maxn*maxn];
int p[maxn];
int N,M;
int find(int x)                          //并查集查找公共祖先 
{
    return x==p[x]?p[x]:p[x]=find(p[x]);
}
bool cmp(Eage a,Eage b)
{
    return a.cost<b.cost;
}
long long Kruskal()
{
    long long ans=0;
    sort(E,E+M,cmp);
    for(int i=0;i<M;i++)
    {
        int x=find(E[i].from);              //找出两端点的集合编号
        int y=find(E[i].to);
        if(x!=y)
        {
            p[x]=y;
            ans+=E[i].cost;
        }
    }
    return ans;
}
int main()
{
    while(cin>>M>>N)
    {
        for(int i=0;i<N;i++) p[i]=i;    //初始化并查集
        for(int i=0;i<M;i++)
        {
            cin>>E[i].from>>E[i].to>>E[i].cost;
        }
        long long ans=Kruskal();
    }
}