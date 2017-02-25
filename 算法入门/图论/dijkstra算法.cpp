#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <limits.h>
using namespace std;
#define maxn 500+5
int m,n;
unsigned int d[30+5];
int v[30+5];
vector<vector<unsigned int> > map(35, vector<unsigned int>(35));

void dijkstra()
{
	memset(v,0,sizeof(v));
	for(int i=0;i<=n;i++) d[i]=(i==0?0:INT_MAX);
	for(int i=0;i<=n;i++){
		int x,m=INT_MAX;
		for(int y=0;y<=n;y++) if(!v[y] && d[y]<=m) m=d[x=y];
		v[x]=1;
		for(int y=0;y<=n;y++) d[y]=min(d[y],d[x]+map[x][y]);
	}
}
int main()
{
	while((cin>>m>>n) && (m*n))
	{
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++) 
            {
                if (i == j) map[i][j] = 0;
                else map[i][j] = INT_MAX;
            }
        }
        
		for (int i = 0; i < m; ++i)
	        {
	            int a, b, c;
	            cin >> a >> b >> c;
	            map[a][b] = c;
	        }
	    dijkstra();
	      cout<<d[n]<<endl;
	}
	return 0;
} 
