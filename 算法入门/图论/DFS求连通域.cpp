
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

using namespace std;
const int maxn=100+5;
char pic[maxn][maxn];
int m,n,idx[maxn][maxn];

void dfs(int i,int j,int id)
{
	if(i<0||i>=m||j<0||j>=n) return;
	if(idx[i][j]>0 || pic[i][j] != '@') return;
	idx[i][j]=id;
	for(int di=-1;di<=1;di++)
	  for(int dj=-1;dj<=1;dj++)
	   if(di !=0 || dj!=0) dfs(i+di,j+dj,id);
}
int main()
{	
	while(scanf("%d%d",m,n)==2 &m & n)
	{
		for(int i=0;i<m;i++)
			scanf("%s",pic[i]);
		memset(idx,0,sizeof(idx));
		int cnt=0;
		for(int i=0;i<m;i++)
		    for(int j=0;j<n;j++)
		     if(idx[i][j]==0 && pic[i][j]=='@')
		     dfs(i,j,++cnt);
         printf("%d\n",cnt );
	}
    return 0;
 } 
