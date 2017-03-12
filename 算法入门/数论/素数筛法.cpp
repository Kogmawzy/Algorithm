#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;
vector<int> prime;		//保存所得素数
bool vis[10001];		//标记非素数 
void init(int n)			//筛选出0~n之间的所有素数 
{
	memset(vis,false,sizeof(vis));
	for(int i=2;i<=n;i++)
	{
		if(vis[i]==true) continue;
		prime.push_back(i);
		for(int j=i*i;j<=n;j+=i)
			vis[j]=true;
	}
} 
int main()
{
	init(100);
	cout<<prime.size()<<endl;
	for(int i=0;i<prime.size();i++)
	 cout<<prime[i]<<endl;
	return 0;
} 
