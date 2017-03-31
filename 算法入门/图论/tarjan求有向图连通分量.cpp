#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5;
vector<int> E[maxn]; 
int dfn[maxn],low[maxn],vis[maxn],tot=0,n,m;
stack<int> S;
void tarjan(int x)
{
	low[x]=dfn[x]=++tot;
	vis[x]=1;
	S.push(x);
	for(int i=0;i<E[x].size();i++){
		int v=E[x][i];
		if(!dfn[v]){					//如果没有访问过
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(vis[v]){			//如果访问过，并且还在栈里
			low[x]=min(low[x],dfn[v]);
		}
	}
	if(low[x]==dfn[x]){				//发现是整个强连通分量子树里的最小根。
		while(1){
			int now=S.top();
			S.pop();
			vis[now]=0;
			cout<<now<<" ";
			if(now==x) break;
		}
		cout<<endl;
	}
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		E[x].push_back(y);
	}
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		if(!dfn[i]) tarjan(i);		//这个点没有访问过，就从此点开始。防止图没走完
}
