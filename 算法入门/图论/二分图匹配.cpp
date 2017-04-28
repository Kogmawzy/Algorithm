/*		1.扫描每一个课程 
*		2.假如课程对应的课代表当前没匹配，则选他
*		3.否则递归搜索那个课代表选的课，如果可以换课代表，则交换，否则匹配失败 
*/
#include <cstdio>  
#include <iostream>  
#include <algorithm>  
#include <vector>  
#include <cstring>  
using namespace std;  
  
int vis[310],match[310],P,N;  
vector<int>G[505];  
bool dfs(int u)  
{  
    for(int i=0; i<G[u].size(); i++)  
    {  
        int t=G[u][i];  
        if(!vis[t])  
        {  
            vis[t]=1;  
            if(match[t]==-1||dfs(match[t]))  
            {  
                match[t]=u;  
                return true;  
            }  
        }  
    }  
    return false;  
}  
  
int main()  
{  
    scanf("%d%d",&P,&N);  
    for(int i=1; i<=P; i++)  
    {  
        int k;  
        scanf("%d",&k);   
        for(int j=0; j<k; j++)  
        {  
            int v;  
            scanf("%d",&v);  
            G[i].push_back(v);  
        }  
    }  

    int res=0;  
    memset(match,-1,sizeof(match)); 
    for(int i=1; i<=P; i++)  
    {  
        memset(vis,0,sizeof(vis));  
        if(dfs(i))  
            res++;  
    }  
    cout<<res<<endl; 
}  
