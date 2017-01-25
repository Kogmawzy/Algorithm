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
 
        a[i] = a[j];         /*将比枢纽小的移到低端*/
 
        while(i < j && a[i] <= key)
        {
            ++i;
        }
         
        a[j] = a[i];    
                            /*将比枢纽大的移到高端*/
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