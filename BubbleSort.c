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

//每经过一轮扫描，必然会有一个元素会就位，放到末尾