#include<cstdio>
#include<cstring>
#include <iostream>
using namespace std;
char chess[5][6];
char press[5][6];

bool judge()
{
	for(int row=2;row<=4;row++)
		for(int col=1;col<=4;col++)
			press[row][col]=(chess[row-1][col]+press[row-1][col]+press[row-1][col-1]+press[row-1][col+1]+
							press[row-2][col])%2;
	for(int i=1;i<=4;i++)
		if((chess[4][i]+press[4][i]+press[4][i+1]+press[4][i-1]+press[3][i])%2 !=0 )
			return false;
	return true;
	
}
bool enumerate()
{
	for(int a1=0;a1<2;a1++)
		for(int a2=0;a2<2;a2++)
			for(int a3=0;a3<2;a3++)
				for(int a4=0;a4<2;a4++)
				{
					press[1][1]=a1;
					press[1][2]=a2;
					press[1][3]=a3;
					press[1][4]=a4;
					if(judge()==true)	return true;
				}
	return false;
	
}
int main(){
	for(int i=1;i<=4;i++){						//输入棋子状态 
		for(int j=1;j<=4;j++){
			scanf("%c",&chess[i][j]);
			if(chess[i][j]=='b') chess[i][j]=0;
			else if(chess[i][j]=='w') chess[i][j]=1;
		}
		getchar();
	}
	for(int i=0;i<6;i++)					//初始化第一行为0 
		press[0][i]=0;
	for(int i=0;i<5;i++)					//初始化第一列、最后列为0 
		press[i][0]=press[i][5]=0;
		
	if(enumerate()==true)
	{
		int step=0;
		for(int i=1;i<=4;i++)
			for(int j=1;j<=4;j++)
				if(press[i][j]==1) 
				step++;
		cout<<step<<endl;
	}
	else
		cout<<"impossible"<<endl;
}
