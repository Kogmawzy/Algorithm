/*Floyd�㷨��ֻ��Ҫ��ʼ��һ��d���󣬱�ʾ�㵽��ľ��룬ÿ�ε�������һ�ξ���*/

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
          d[i][j]=(i==j?0:INT_MAX);				//��ʼ��������� 
          
	   for(int i=0;i<m;i++)						//���������� 
	   {
	   	  cin>>a>>b>>c;
	   	  d[a][b]=c;
	   } 
	   
	   for(int k=0;k<=n;k++)					//floyd�����㷨 
	   	for(int i=0;i<=n;i++)
	   	 for(int j=0;j<=n;j++)
	   	   if(d[i][k]<INT_MAX && d[k][j]<INT_MAX)
	   	    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	   	
	   	cout<<d[0][n]<<endl;					//�����㵽�յ�ľ��� 
	}
	return 0;
} 
