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
		priority_queue<int,vector<int>,greater<int> > heap;	//���ȼ�����ʵ����С�� 
		for(int i=0;i<n;)			//ͳ�ƴ�Ƶ 
		{
			int  j=i;
			while(j<n && s[j]==s[i]) j++;
			heap.push(j-i);
			i=j;
		}
		for(int i=0;i<heap.size()-1;)                 //ÿ��ȡ����С��������
		{
			int A=heap.top();heap.pop();
			int B=heap.top();heap.pop();
			result+=A+B;
			heap.push(A+B);                      //���ϲ�������ٲ������
		}
		cout<<result<<endl;
	} 
	return 0;
} 
