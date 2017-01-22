/*  有序序列的二分查找
    每次向左查找比较次数为1，向右查找比较次数为2，但递归深度却相同
    因此该算法是不平衡的，还可以优化
*/

static Rank binSearch(T *A,const & e,Rank lo,Rank hi)
{
    while(lo<hi)
    {
        Rank mi=(lo+hi)>>1;
        if (e<A[mi]) hi=mi;
        else if(e>A[mi]) lo=mi+1;
        else    return mi;          //命中
    }
    return -1;
}

/*  有序序列的斐波那契查找
    通过递归深度的不平衡来弥补左右比较的不平衡
    每次的中点按黄金比例切分
*/

static Rank binSearch(T *A,const & e,Rank lo,Rank hi)
{
    while(lo<hi)
    {
        while(hi-lo<fib.get()) fib.prev();
        Rank mi=lo+ fib.get() -1;                   //按黄金比例切分
        if (e<A[mi]) hi=mi;
        else if(e>A[mi]) lo=mi+1;
        else    return mi;          //命中
    }
    return -1;
}