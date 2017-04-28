#include <iostream>  
struct Node{
	int left;
	int right;
	int val;
}node[500];
int father[500];                            
void BuildTree(int i,int left,int right)
{
	node[i].left=left;
	node[i].right=right;
	node[i].val=0;
	if(left==right){
		father[left]=i;			//ÿ�����������е�λ�� 
		return; 
	} 
	BuildTree(i<<1,left,(right+left)>>1);
	BuildTree((i<<1)+1,((right+left)>>1)+1,right);
}
void UpdataTree(int ri)
{
	if(ri==1) return;
	int fi=ri/2;				//���ڵ� 
	int a=node[fi<<1].val;		//�ø��ڵ���������� 
	int b=node[(fi<<1)+1].val;
	node[fi].val=max(a,b);		//����������ѡ���ģ����������ֵ 
	UpdataTree(ri/2);
 } 
 int Max=-1<<20;
 void Query(int i,int l,int r)
 {
 	if(node[i].left==l && node[i].right==r)
 	{
 		Max=max(Max,node[i].val);
 		return;
	 }
	 i=i<<1;						//������� 
	 if(l<=node[i].right){			//���������漰 
	 	if(r<=node[i].right)		//ȫ������������
		 	Query(i,l,r);
		else						//������������� 
			Query(i,l,node[i].right); 
	 }
	 i+=1;							//����Һ���
	 if(r>=node[i].left){
	 	if(l>=node[i].left)
	 		Query(i,l,r);
	 	else
	 		Query(i,node[i].left,r);
	 } 
 } 
 
 
