void reverse(int *A,int low,int high)
{
    while(low<high)
        swap(A[low++],A[high--]);
}


void reverse(int *A,int low,int high)
{
    if(low<high)
    {
        swap(A[low],A[high]);
        reverse(A,low+1,high-1);
    }
}

/*  互换数组A中区间low到high的元素  */