//    有N堆石子，现要将石子有序的合并成一堆，规定如下：每次只能移动相邻的2堆石子合并，
//    合并花费为新合成的一堆石子的数量。求将这N堆石子合并成一堆的总花费最小（或最大）

#include <iostream>  
#include <string.h>  
#include <stdio.h>  
  
using namespace std;  
const int INF = 1 << 30;  
const int N = 1005;  
  
int dp[N][N];  
int sum[N];  
int a[N];  
  
int getMinval(int a[],int n)  
{  
    for(int i=0;i<n;i++)  
        dp[i][i] = 0;  
    for(int v=1;v<n;v++)  
    {  
        for(int i=0;i<n-v;i++)  
        {  
            int j = i + v;  
            dp[i][j] = INF;  
            int tmp = sum[j] - (i > 0 ? sum[i-1]:0);  
            for(int k=i;k<j;k++)  
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j] + tmp);  
        }  
    }  
    return dp[0][n-1];  
}  
  
int main()  
{  
    int n;  
    while(scanf("%d",&n)!=EOF)  
    {  
        for(int i=0;i<n;i++)  
            scanf("%d",&a[i]);  
        sum[0] = a[0];  
        for(int i=1;i<n;i++)  
            sum[i] = sum[i-1] + a[i];  
        printf("%d\n",getMinval(a,n));  

    }  
    return 0;  
}


//      平行四边形优化，将O(n3) 优化到O(n2)

#include<cstring>  
#include<iostream>  
#include<algorithm>  
#include<string>  
#include<queue>  
#define ll long long  
using namespace std;  
const int inf=0x08080808;  
int mmin(int a,int b){  
    return a<b?a:b;  
}  
int num[1010],dp[1010][1010],sum[1010];  
int p[1010][1010];  
int main(){  
    int n;  
    //while(scanf("%d",&n)){  
    scanf("%d",&n);  
    for(int i=1;i<=n;++i)  
        scanf("%d",&num[i]);  
    sum[0]=0;  
    memset(dp,inf,sizeof(dp));  
    for(int i=1;i<=n;++i){  
        sum[i]=sum[i-1]+num[i];  
        dp[i][i]=0;  
        p[i][i]=i;  
    }  
    for(int len=2;len<=n;++len)  
    for(int i=1;i+len-1<=n;++i){  
        int j=i+len-1;  
        for(int k=p[i][j-1];k<=p[i+1][j];++k){  
            int val=dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1];  
            if(dp[i][j]>val) {  
                dp[i][j]=val;  
                p[i][j]=k;  
            }  
        }  
        //cout<<i<<"  "<<j<<"  "<<dp[i][j]<<endl;  
    }  
    printf("%d\n",dp[1][n]);  
   // }  
    return 0;  
}  
