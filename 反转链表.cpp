ListNode* ReverseList(ListNode* pHead) {
        ListNode* pNode=pHead;
        ListNode* pReverseHead=NULL;
        ListNode* pPrev=NULL;
        while(pNode)
        {
            ListNode* pNext=pNode->next;
            if(pNext==NULL)
                pReverseHead=pNode;
            pNode->next=pPrev;
            pPrev=pNode;
            pNode=pNext;
        }
        return pReverseHead;
    }
