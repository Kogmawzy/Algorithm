//普通快速幂    计算  (a^b)%c
typedef long long ll;

ll quick_mod(ll a,ll b,ll c){
    ll ans=1;
    while(b){
        if(b&1) ans=(ans*a)%c;
        a=(a*a)%c;
        b>>=1;
    }
    return ans;
}

//利用快速乘法优化

ll quick_mul(ll a,ll b,ll c){
    ll ans=0;
    while(b){
        if(b&1) ans=(ans+a)%c;
        a=(a+a)%c;
        b>>=1;
    }
    return ans;
}



ll quick_mod(ll a,ll b,ll c){
    ll ans=1;
    while(b){
        if(b&1) ans=quick_mul(ans,a,c);
        a=quick_mul(a,a,c);
        b>>=1;
    }
    return ans;
}