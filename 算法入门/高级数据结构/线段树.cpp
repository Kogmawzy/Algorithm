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
		father[left]=i;			//每个单点在树中的位置 
		return; 
	} 
	BuildTree(i<<1,left,(right+left)>>1);
	BuildTree((i<<1)+1,((right+left)>>1)+1,right);
}
void UpdataTree(int ri)
{
	if(ri==1) return;
	int fi=ri/2;				//父节点 
	int a=node[fi<<1].val;		//该父节点的两个孩子 
	int b=node[(fi<<1)+1].val;
	node[fi].val=max(a,b);		//两个孩子中选择大的，求区间最大值 
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
	 i=i<<1;						//获得左孩子 
	 if(l<=node[i].right){			//左区间有涉及 
	 	if(r<=node[i].right)		//全包含于左区间
		 	Query(i,l,r);
		else						//半包含于左区间 
			Query(i,l,node[i].right); 
	 }
	 i+=1;							//获得右孩子
	 if(r>=node[i].left){
	 	if(l>=node[i].left)
	 		Query(i,l,r);
	 	else
	 		Query(i,node[i].left,r);
	 } 
 } 
 
 
