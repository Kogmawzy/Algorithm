#include <iostream>
using namespace std;
int N;

int preorder[8]={1,2,3,4,5,6};
int inorder[8]={3,2,4,1,6,5};

void getpostOrder(int in,int pre,int length)
{
	if(length==0) return;
	int root=preorder[pre];
	int rootindex=0;
	for(;rootindex<length;rootindex++)
	{
		if(inorder[rootindex+in]==root) break;
	}
	getpostOrder(in,pre+1,rootindex);
	getpostOrder(in+rootindex+1,pre+rootindex+1,length-(rootindex+1));
	cout<<root<<" ";
} 

int main()
{
	getpostOrder(0,0,6);
}
