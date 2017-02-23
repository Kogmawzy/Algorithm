链接：https://www.nowcoder.com/profile/106301/codeBookDetail?submissionId=279702
来源：牛客网                      求有向图的最长路径

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#pragma warning(disable:4996)
using namespace std;
map<string, int> mark;
char str1[33], str2[33];
vector<int> g[20000 + 10];
int dp[20000 + 10];
bool vis[20000 + 10];
int dfs(int u)
{
    if (dp[u] != -1)
        return dp[u];
    dp[u] = 1;
    for (int i = 0; i < g[u].size(); ++i)
    {
        int v = g[u][i];
        dp[u] = max(dp[u],dfs(v)+1);
    }
    vis[u] = true;
    return dp[u];
}
int main()
{
    int n, cnt, a, b;
    while (scanf("%d", &n) != EOF)
    {
          
        mark.clear();
        memset(dp, -1, sizeof(dp));
        memset(vis, 0, sizeof(vis));
          
        cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%s%s", str1, str2);
            if (mark[str1] == 0)
            {
                mark[str1] = a = ++cnt;
            }
            else
                a = mark[str1];
            if (mark[str2] == 0)
            {
                mark[str2] = b = ++cnt;
            }
            else
                b = mark[str2];
            g[a].push_back(b);
        }
        int ans = 0;
        for (int i = 1; i <= cnt; ++i)
        {
              
            ans = max(ans,dfs(i));
      
        }
        printf("%d\n", ans);
        for (int i = 0; i <= cnt; ++i)
            g[i].clear();
    }
  
    return 0;
}