//   前序遍历
void preorder(bintree t){  
    if(t){  
        printf("%c ",t->data);  
        preorder(t->lchild);  
        preorder(t->rchild);  
    }  
}

