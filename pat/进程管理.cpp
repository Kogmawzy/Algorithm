#include <iostream>
#include <queue>
using namespace std;
char c;
struct Process
{
	int id,priority,start,time;
	friend bool operator< (Process n1, Process n2)
    {
        return n1.start > n2.start;
    }
    
};
struct Process_ready
{
	int id,priority,time;
	friend bool operator< (Process_ready n1, Process_ready n2)
    {
        return n1.priority < n2.priority;
    }

};

priority_queue<Process_ready> readyQ;
priority_queue<Process> waitQ;

int main()
{
	for(int i=0;i<5;i++)
	{
		int id,priority,start,time;
		cin>>c>>id>>c>>priority>>c>>start>>c>>time>>c;
		if(i!=4) cin>>c;
		waitQ.push(Process{id,priority,start,time});
	}
	int running=0; 
	Process_ready Cur{0,-1,-1};		//��ǰ���� 
	for(int i=0;i<200;i++,running++)
	{
		Cur.time--;
		if(Cur.time==0) 			//��ǰ����״̬���� 
		{
			cout<<Cur.id<<"."<<running<<"|";
			Cur=Process_ready{0,-1,-1};
			running=0;
		}
		
		while(!waitQ.empty())			//�ȴ�����ȡ��������������� 
		{
			if(waitQ.top().start<=i)
			{
				Process x=waitQ.top();
				waitQ.pop();
				readyQ.push(Process_ready{x.id,x.priority,x.time});
			}
			else break;
		}
		if(!readyQ.empty() && readyQ.top().priority>Cur.priority)		//�������зǿգ������ȼ���ת��Ϊ����״̬ 
		{
			if(running>0)
			cout<<Cur.id<<"."<<running<<"|";
			running=0;
			readyQ.push(Cur);
			Cur=readyQ.top();
			readyQ.pop();
		} 		
	} 
	cout<<Cur.id<<"."<<running;	
}
