/*Floyd算法，只需要初始化一个d矩阵，表示点到点的距离，每次迭代更新一次矩阵*/

#include <iostream>
#include <limits.h>
#include <string.h>
using namespace std;

#define maxn 505
int n,m,c1,c2; 
int d[maxn][maxn]; 

int adj[maxn][maxn];
int NumOfResc[maxn];
int visit[maxn];
int maxHands,ways;
void dfs(int u,int sum,int hands)
{
	if(sum>d[c1][c2]) return;
	else if(sum==d[c1][c2] && u!=c2) return;
	else if(sum==d[c1][c2] && u==c2)
	{
		ways++;
		maxHands=maxHands>hands?maxHands:hands;
		return;
	}
	
	for(int i=0;i<n;i++)
	{
		if(adj[u][i]<INT_MAX && visit[i]==0 &&i!=u)					//有边 且 未访问过 
		{
			visit[i]=1;
			dfs(i,sum+adj[u][i],hands+NumOfResc[i]);
			visit[i]=0;                                          //切记！要把访问标志位清零，否则无法求得多解
		}
	}
}
int main()
{
	int a,b,c;
	while((cin>>n>>m>>c1>>c2))
	{
	   maxHands,ways=0;
	   memset(visit,0,sizeof(visit));
	   memset(NumOfResc,0,sizeof(NumOfResc));
	   memset(adj,0,sizeof(adj));
	   memset(d,0,sizeof(d));
	   
       for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          d[i][j]=(i==j?0:INT_MAX);				//初始化距离矩阵 
          
       for(int i=0;i<n;i++) cin>>NumOfResc[i];
	   for(int i=0;i<m;i++)						//输入距离参数 
	   {
	   	  cin>>a>>b>>c;
	   	  d[a][b]=d[b][a]=c;
	   } 
	   memcpy(adj,d,sizeof(d));

	   for(int k=0;k<n;k++)					//floyd核心算法 
	   	for(int i=0;i<n;i++)
	   	 for(int j=0;j<n;j++)
	   	   if(d[i][k]<INT_MAX && d[k][j]<INT_MAX)
	   	    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	   	
	   	dfs(c1,0,NumOfResc[c1]);
	   	cout<<ways<<" "<<maxHands<<endl;
	}
	return 0;
} 
