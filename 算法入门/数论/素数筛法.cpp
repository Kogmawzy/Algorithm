#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;
vector<int> prime;		//������������
bool vis[10001];		//��Ƿ����� 
void init(int n)			//ɸѡ��0~n֮����������� 
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
