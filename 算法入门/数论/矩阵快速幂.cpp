#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int maxn=110;
#define mod(x) ((x)%MOD) 
int n,x;
struct mat{
    int m[maxn][maxn];
}unit;                      //单位矩阵 
mat operator *(mat a,mat b)
{
    mat ret;
    ll x;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        x=0;
        for(int k=0;k<n;k++)
         x += mod((ll)a.m[i][k]*b.m[k][j]);
        ret.m[i][j]=mod(x);
    }
    return ret;
}
void init_unit()            //初始化单位矩阵 
{
    for(int i=0;i<maxn;i++)
        unit.m[i][i]=1;
    return;
}
mat pow_mat(mat a,ll n)
{
    mat ret = unit;
    while(n)
    {
        if(n&1) ret=ret*a;
        a = a*a;
        n>>=1;
    }
    return ret;
}
int main()
{
    init_unit();
    while(cin>>n>>x)
    {
        mat a;
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a.m[i][j];
        a=pow_mat(a,x);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            cout<<a.m[i][j]<<" ";
            cout<<endl;
        }
    }
}