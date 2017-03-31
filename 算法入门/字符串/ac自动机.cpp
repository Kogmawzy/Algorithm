#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 1000006				//�ı������� 
#define MAX_TOT 500005			//ƥ�䴮���� 
struct Aho{
	struct state{
		int next[26];
		int fail,cnt;	//fail��ʧ��ʱָ��ĸ���ָ�룬cnt��ʾ�õ��β��ƥ�䴮���� 
	}stateTable[MAX_TOT];
	
	int size;					//������
	queue<int> Q;
	void init(){
		while(!Q.empty()) Q.pop();
		for(int i=0;i<MAX_TOT;i++)
		{
			memset(stateTable[i].next,0,sizeof(stateTable[i].next));
			stateTable[i].fail=stateTable[i].cnt=0;
		}
		size=1;
	} 
	void insert(char *S){			//��ƥ�䴮���뵽�ֵ��� 
		int now=0;int n=strlen(S);
		for(int i=0;i<n;i++){
			char c=S[i];
			if(!stateTable[now].next[c-'a'])
				stateTable[now].next[c-'a'] =size++;
			now=stateTable[now].next[c-'a'];
		}
		stateTable[now].cnt++;
	}
	void build(){				//����ʧ��ʱfailʧ��ָ��
		stateTable[0].fail=-1;
		Q.push(0);
		while(!Q.empty()){
			int u=Q.front();
			Q.pop();
			for(int i=0;i<26;i++){
				if(stateTable[u].next[i]){
					if(u==0) stateTable[stateTable[u].next[i]].fail=0;
					else{
						int v=stateTable[u].fail;
						while(v!=-1){
							if(stateTable[v].next[i]){
								stateTable[stateTable[u].next[i]].fail=stateTable[v].next[i];
								break;
							}
							v=stateTable[v].fail;
						}
						if(v==-1) stateTable[stateTable[u].next[i]].fail=0;
					}
					Q.push(stateTable[u].next[i]);	
				} 
				
			}
		}
	}
	int Get(int u){
		int res=0;
		while(u){
			res=res+stateTable[u].cnt;
			stateTable[u].cnt=0;
			u=stateTable[u].fail;
		}
		return res;
	}
	int match(char *S){
		int res=0,now=0; int n=strlen(S);
		for(int i=0;i<n;i++){
			char c=S[i];
			if(stateTable[now].next[c-'a'])
				now=stateTable[now].next[c-'a'];
			else{
				int p=stateTable[now].fail;
				while(p!=-1 && stateTable[p].next[c-'a']==0) p=stateTable[p].fail;
				if(p==-1) now=0;
				else now=stateTable[p].next[c-'a'];
			}
			if(stateTable[now].cnt)					//�õ��������Ϊ��׺�������ַ��� 
				res=res+Get(now);
		}
		return res;
	}
}ac;
int T,N; 
char S[MAX_N];
int main()
{
	scanf("%d",&T);
   while(T--){
   		scanf("%d",&N);
   		ac.init();
	   	for(int i=0;i<N;i++){
	   			scanf("%s",S);
	   			ac.insert(S);
		   }
		ac.build();
		scanf("%s",S);
		cout<<ac.match(S)<<endl;
   }
    return 0;
}
