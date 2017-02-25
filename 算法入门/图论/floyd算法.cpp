/*Floyd算法，只需要初始化一个d矩阵，表示点到点的距离，每次迭代更新一次矩阵*/

#include <iostream>
#include <limits.h>
using namespace std;

int m,n;
int d[31][31]; 
int main()
{
	int a,b,c;
	while((cin>>m>>n) && (m*n))
	{
       for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
          d[i][j]=(i==j?0:INT_MAX);				//初始化距离矩阵 
          
	   for(int i=0;i<m;i++)						//输入距离参数 
	   {
	   	  cin>>a>>b>>c;
	   	  d[a][b]=c;
	   } 
	   
	   for(int k=0;k<=n;k++)					//floyd核心算法 
	   	for(int i=0;i<=n;i++)
	   	 for(int j=0;j<=n;j++)
	   	   if(d[i][k]<INT_MAX && d[k][j]<INT_MAX)
	   	    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	   	
	   	cout<<d[0][n]<<endl;					//输出起点到终点的距离 
	}
	return 0;
} 
