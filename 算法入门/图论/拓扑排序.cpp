/*                              拓扑序列一定是有向无环图
*       首先选择一个入度为0的节点，作为第一个节点。将该点从图中删除，并删除该节点的所有边，得到新图。
*   在新图中删除下一个入度为0的节点，同理删除节点的所有边，直到所有节点和边从原图中删除。
*   
*   （若所有节点尚未被删除但找不到入度为0的节点，说明剩余的节点形成一个环路，即不存在拓扑排序）
*
*
*
*
*
*
*/

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int N,M;
vector<int> v[505];
priority_queue<int> Q;
int in[505];
int main()
{
    cin>>N>>M;
    for(int i=0;i<M;i++)
    {
        int x,y;    cin>>x>>y;
        v[x].push_back(y);
        in[y]++;
    }
    for(int i=1;i<=N;i++) 
    {
        if(in[i]==0) Q.push(-i);
    }
    int ans=0;
    while(!Q.empty())
    {
        int x=-Q.top();
        Q.pop();
        ans++;
        if(ans==N) cout<<x<<endl;
        else    cout<<x<<" "; 
        for(int i=0;i<v[x].size();i++)
        {
            int u=v[x][i];
            in[u]--;
            if(in[u]==0)
                Q.push(-u);
        }
    }
} 
