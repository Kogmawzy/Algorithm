#include <bits/stdc++.h>
using namespace std;
const int maxn=205;
vector<pair<int,int> > E[maxn];					//临界链表 

int n,m;
int d[maxn];
void init()
{
	for(int i=0;i<maxn;i++) E[i].clear();		//初始化链表 
	for(int i=0;i<maxn;i++) d[i]=1e9; 			//初始化距离 
}
int main()
{
	while(cin>>n>>m)
	{
		init();
		for(int i=0;i<m;i++)
		{
			int x,y,z;scanf("%d%d%d",&x,&y,&z);
			E[x].push_back(make_pair(y,z));
			E[y].push_back(make_pair(x,z));
		}
		int s,t;
		scanf("%d%d",&s,&t);
		priority_queue<pair<int,int> >Q;
		d[s]=0;
		Q.push(make_pair(-d[s],s));
		while(!Q.empty())
		{
			int now=Q.top().second;
			Q.pop();
			for(int i=0;i<E[now].size();i++)
			{
				int v=E[now][i].first;
				if(d[v]>d[now]+E[now][i].second)
				{
					d[v]=d[now]+E[now][i].second;
					Q.push(make_pair(-d[v],v));
				}
			}
		}
		if(d[t]==1e9)printf("-1\n");
		else printf("%d\n",d[t]);
	}
}

