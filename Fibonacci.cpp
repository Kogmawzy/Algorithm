/*  斐波那契数二分递归版，效率极低
*/
int fib(int n)
{
    return (n<2)?n:fib(n-1)+fib(n-2);
}


/*  斐波那契数迭代版
*   采用动态规划，每次保留上一次计算的数，消除重复
*/
int  fib(int n)
{
    int f=0,g=1;    //定义两级台阶
    while(n-->0)
    {
        g=g+f;
        f=g-f;
    }
    return g;
}