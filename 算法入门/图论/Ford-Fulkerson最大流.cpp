#include <iostream>
#include <queue>
#include <string.h> 
using namespace std;
int N,M;
const int manx=220;
int G[manx][manx];

int parent[manx];
int vis[manx];
bool bfs(int s,int t)
{
    memset(vis,0,sizeof(vis));
    memset(parent,0,sizeof(parent));
    queue<int> Q;
    Q.push(s);
    vis[s]=1;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int v=1;v<=N;v++)
        {
            if(vis[v]==0 && G[u][v]>0)
            {
                Q.push(v);
                parent[v]=u;
                vis[v]=1;
            }
         } 
    }
    return vis[t]==1;
}
long long fordFulkerson(int s,int t)
{
    long long ans=0;
    while(bfs(s,t))
    {
        int path_flow=1e9;
        for(int v=t;v!=s;v=parent[v])
        {
            int u=parent[v];
            path_flow=min(path_flow,G[u][v]);
        }
        for(int v=t;v!=s;v=parent[v])
        {
            int u=parent[v];
            G[u][v]-=path_flow;
            G[v][u]+=path_flow;
        }
        ans+=path_flow;
    }
    return ans;
}
int main()
{
    cin>>M>>N;
        for(int i=0;i<M;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        G[x][y]+=z;
    }
    cout<<fordFulkerson(1,N)<<endl;
    return 0;
    
} 