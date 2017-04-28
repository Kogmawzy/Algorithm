#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int N,K;
int a[100005]; 
bool vis[100005];

int get(int x)
{
	bool have=false;
	int ans=0;
	while(!vis[x])
	{
		if(a[x]==0)  have=true;
		ans++;
		vis[x]=true;
		x=a[x];
	}
	return have?ans-1:ans+1;	//有0环-1，无0环+1 
}
int main()
{
	cin>>N;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<N;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	for(int i=0;i<N;i++)
	{
		if(a[i]!=i && !vis[i])
		 ans+=get(i);
	}
	cout<<ans<<endl;
} 






