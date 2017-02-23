#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<char> > map(10,vector<char>(10));

struct pos{
	int x;
	int y;
	int level;
};

void bfs()
{
	vector<vector<bool> > visit(10,vector<bool>(10,false));
	const int road[4][2]={{-1,0},{0,-1},{1,0},{0,1}}; 
	queue<pos> q;
	pos start{0,1,0},end{9,8,0};
	q.push(start);
	while(!q.empty())
	{
		pos cur=q.front(),next;
		q.pop();
		for(int i=0;i<4;i++)
		{
			next.x=cur.x+road[i][0];
			next.y=cur.y+road[i][1];
			next.level=cur.level+1;
			if(next.x==end.x && next.y==end.y) {
				cout<<next.level<<endl;
				return;
			}
			if(next.x>=0 &&next.x<10 && next.y>=0 &&next.y<10 &&
				visit[next.x][next.y]==false && map[next.x][next.y]=='.')
				{
					visit[next.x][next.y]=true;
					q.push(next);
				}
		}
	}
	return;
}
int main()
{
	while(cin >> map[0][0])
	{
		for(int i=0;i<10;i++)
		  for(int j=0;j<10;j++)
		  {
		  	if(i==0 && j==0) continue;
		  	cin >>map[i][j];
		  }
		bfs();
	}
} 
