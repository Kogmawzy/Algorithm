//链表中起始于p的连续n个元素做选择排序
void selectionSort(Posi(T) p,int n)
{
    Posi(T) head = p->pred;
    Posi(T) tail = p;
    for(int i=0;i<n;i++) tail=tail->succ;
    while(n>1)              //从无序区间取出最大者，移动到有序区间前端
    {
        insertBefore(tail,remove(selectMax(head->succ,n)));
        tail = tail->pred;
        n--;
    }
}



//与冒泡排序类似，每趟扫描都选出一个最大的放到最后
//不同的是，不需要每次交换，而只需要比较，每趟选出最大的即可
//选择排序基于链表，冒泡排序基于向量