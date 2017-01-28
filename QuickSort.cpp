void Qsort(int a[], int low, int high)
{
    if(low >= high)
    {
        return;
    }
    int i = low,j = high,key = a[low];  /*用字表的第一个记录作为枢轴*/

    while(i < j)
    {
        while(i < j && a[j] >= key)
        {
            --j;
        }
        a[i] = a[j];                 /*将比枢纽小的移到低端*/
        while(i < j && a[i] <= key)
        {
            ++i;
        }
        a[j] = a[i];                                /*将比枢纽大的移到高端*/
    }
    a[i] = key;             /*枢轴记录到位*/
    Qsort(a, low, i-1);
    Qsort(a, i+1, high);
}

/*  1．先从数列中取出一个数作为基准数。
    2．分区过程，将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边。
    3．再对左右区间重复第二步，直到各区间只有一个数。

    http://blog.csdn.net/liuchen1206/article/details/6954074
*/



//一种更直接的分治办法，将小的元素放到前缀，大的元素放到后缀
int Partition(int A[],int low,int high)         //分治法，作用就是将数组分为A[low..q-1] 和A[q+1..high]  
{                                                   //然后调整元素使得A[p..q-1]小于等于q，也小于等于A[q+1..r]  
    int x,i,j;  
  
    x = A[high];                   //将最后一个值保存在x中,作为枢纽  
    i = low-1;                       //开始的时候将i 移动到数组的外面  
    for( j=low; j<high; j++)  
    {  
        if(A[j]<x)                     //j作为扫描因子，循环不断将比枢纽小的值放到前缀
        {  
            i +=1;  
            swap(&A[i],&A[j]);
        }  
    }  
    
    i++;
    swap(&A[i],&A[high]);

    return i;  //返回q值  
}


//求第k大的数  
int GetNumber(int *arrNum, int n, int k){  
    //输出-1表示不合法   
    if(arrNum == NULL || n <= 0 || k <= 0 || k > n){  
        return -1;  
    }  
    //第k大的数等价于找第n-k+1小的数  
    k = n-k+1;  
    int l = 0;  
    int r = n-1;  
    while(l <= r){  
        int index = Partition(arrNum, l, r);  
        if(index+1 == k){ //找到   
            return arrNum[index];  
        }  
        else if(index+1 < k){ //在右边序列找  
            l = index+1;   
        }  
        else{ //在左边序列找   
            r = index-1;  
        }  
    }  
}   