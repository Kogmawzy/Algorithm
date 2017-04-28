#include <cstring>
#include <iostream>
using namespace std;
int N,c[50005];
int lowbit(int i)
{
	return i&(-i);
}
void add(int i,int value)       //第i个元素添加value值
{
	while(i<=N)
	{
		c[i]+=value;
		i+=lowbit(i);
	}
}
int sum(int i)                  //返回1到i的元素总和
{
	int sum=0;
	while(i>0)
	{
		sum+=c[i];
		i-=lowbit(i);
	}
	return sum;
}
int main()
{
	cin>>N;
	memset(c,0,sizeof(c));
	for(int i=1;i<=N;i++)
	{
		int x; cin>>x;
		add(i,x);
	}
	string s;
	while(cin>>s)
	{
		if(s=="End") break;
		int x,y;
		cin>>x>>y;
		if(s=="Query") cout<<sum(y)-sum(x-1)<<endl;
		else if(s=="Add") add(x,y);
		else if(s=="Sub") add(x,-y);
	}
}
