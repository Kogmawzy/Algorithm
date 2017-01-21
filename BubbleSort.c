void bubblesort(int A[],int n)
{
    for(bool sorted=false;sorted = !sorted;n--)
    for(int i =0;i<n-1;i++)        
        if(A[i]>A[i-1])
        {
            swap(A[i-1],A[i]);
            sorted=false;
        }
}

//不变性：每经过一轮扫描，必然会有一个元素会就位，放到末尾
//单调性：每经过一轮扫描。问题规模缩减1
//正确性：经至多n趟扫描后，算法必然终止