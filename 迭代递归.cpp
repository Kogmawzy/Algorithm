/*  递归求解一个数组中元素和
*/
int sum(int A[],int n)
{
    return (n<1)?0:sum(A,n-1)+A[n-1];
}



/*  二分递归求解一个数组中元素和
*/
int sum(int A[],int low,int high)
{
    if(low==high) return A[low];
    int mi=(low+high)>>1;
    return sum(A,low,mi)+sum(A,mi+1,high);
}

