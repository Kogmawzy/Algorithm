//链表中起始于p的连续n个元素做选择排序
void insertionSort(Posi(T) p,int n)
{
    for(int r=0;r<n;r++){
        insertAfter(search(p->data, r, p),p->data); //查找+插入
        p=p->succ;  remove(p->pred);        //转向下一节点
    }   //n次迭代，仅适用O(1)辅助空间
}
