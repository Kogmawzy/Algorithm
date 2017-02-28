class LCS {
public:
    int findLCS(string A, int n, string B, int m) {
        // write code here
        vector<vector<int> > dp(n+1,vector<int>(m+1,0));
        int maxlen=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                if(A[i-1]==B[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    
                }
                maxlen=max(maxlen,dp[i][j]);
            }
        return maxlen;
    }
};