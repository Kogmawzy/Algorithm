// 归并排序算法

void mergeSort(Rank lo,Rank hi)
{
    if(hi-lo<2) return;
    int mi=(lo+hi)>>1;
    mergeSort(lo,mi);
    mergeSort(mi,hi);
    merge(lo,mi,hi);        //归并
}

// 二路归并

void merge(Rank lo,Rank mi,Rank hi)
{
    T* A =_elem+lo;
    int lb=mi-lo;   T* B=new T[lb];
    for(Rank i=0;i<lb;B[i]=A[i++]);     //复制前子向量B
    int lc=hi-mi;   T* C=_elem+mi;
    for(Rank i=0,j=0,k=0;(j<lb)||(k<lc))
    {
        if((j<lb)&&(lc<=k || (B[j]<=C[k]))) A[i++]=B[j++];
        if((k<lc)&&(lv<=j || (C[k]< B[j]))) A[i++]=C[k++];
    }

}