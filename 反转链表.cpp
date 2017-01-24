LinkedList ReverseSinglyLinkedList(LinkedList list)
{
    LNode   *tmp = NULL;
    LNode   *p = NULL;
 
    if (list == NULL)
    {
        return NULL;
    }
    tmp = list->next;
    while (tmp->next != NULL)
    {
        p = tmp->next;
        tmp->next = p->next;
        p->next = list->next;
        list->next = p;
    }
    return list;
}

/*    每次都将原第一个结点之后的那个结点放在list后面
    为了反转这个单链表，我们先让头结点的next域指向结点2，再让结点1的next域指向结点3，最后将结点2的next域指向结点1，就完成了第一次交换，
    顺序就变成了Header-结点2-结点1-结点3-结点4-NULL，然后进行相同的交换将结点3移动到结点2的前面，然后再将结点4移动到结点3的前面就完成了反转
*
*
*
*/