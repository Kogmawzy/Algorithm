#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

int main()
{
	char s[3000];
	while(scanf("%s",s)!=EOF)
	{
		int result=0;
		int n=strlen(s);
		sort(s,s+n);
		priority_queue<int,vector<int>,greater<int> > heap;	//优先级队列实现最小堆 
		for(int i=0;i<n;)			//统计词频 
		{
			int  j=i;
			while(j<n && s[j]==s[i]) j++;
			heap.push(j-i);
			i=j;
		}
		for(int i=0;i<heap.size()-1;)                 //每次取出最小的两个数
		{
			int A=heap.top();heap.pop();
			int B=heap.top();heap.pop();
			result+=A+B;
			heap.push(A+B);                      //将合并后的数再插入堆中
		}
		cout<<result<<endl;
	} 
	return 0;
} 
