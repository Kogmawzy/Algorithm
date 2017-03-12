#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <string.h>
#include <queue>
#include <stdio.h>
using namespace std;
int n,m,k,q;
int eachtime;
int ans[1005];
struct people{
	int num;	//���
	int timeleft;	//ʣ��ʱ�� 
	people(int x):num(x){ } 
};
queue<people> qu[20]; 

void print_time(int t)
{
	if(t==INT_MAX) {
		printf("Sorry\n");
		return;
	}
	int h=t/60;
	int m=t%60;
	printf("%02d:%02d\n",h+8,m);
}
int GetInsertPos()
{
	int min=-1;
	int minNum=INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(qu[i].size()<m && qu[i].size()<minNum)
		{
			minNum=qu[i].size();
			min=i;
		}
	}
	return min;
}
int main()
{
	while(cin>>n>>m>>k>>q)
	{
		queue<people> mainQ; 
		for(int i=1;i<=k;i++)
		{
			people tmp(i);
			cin>>eachtime;
			tmp.timeleft=eachtime;
			mainQ.push(tmp);
			ans[i]=INT_MAX;
		} 
		
		for(int times=0;times<=540;times++)
		{
			if(times==540)
			{
				for(int i=0;i<n;i++)
				{
					if(!qu[i].empty())
						ans[qu[i].front().num]=qu[i].front().timeleft+539;
				}
				break;
			}
			for(int i=0;i<n;i++)						//��ʱ������Ӧ�Ŷ�ʱ���һ 
			{
				if(!qu[i].empty())
				{
					qu[i].front().timeleft--;
					if(qu[i].front().timeleft==0)
					{
						ans[qu[i].front().num]=times;
						qu[i].pop();						
					}	
				}
			}
			
			int cur=GetInsertPos();
			while(cur!=-1 && !mainQ.empty())			//��λ�ÿ��Բ壬�ȴ����л����� 
			{
				qu[cur].push(mainQ.front());
				mainQ.pop();
				cur=GetInsertPos();
			}
			
			
		}
		
		for(int i=0;i<q;i++)
		{
			int query;
			cin>>query;
			print_time(ans[query]);
		}
		
		
	/*	for(int i=0;i<n;i++)	//��ն��� 
		 while(!qu[i].empty()) qu[i].pop();*/		
	}
	return 0;
} 
