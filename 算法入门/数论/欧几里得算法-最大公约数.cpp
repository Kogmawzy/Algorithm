// 辗转相除法求解最大公约数
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

// 利用 最大公约数*最小公倍数=a*b   求解最小公倍数
int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}
