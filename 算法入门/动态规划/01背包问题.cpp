#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define N 6
#define W 21
int B[N][W]={0};			
int w[6]={0,2,3,4,5,9};		//��Ʒ����
int v[6]={0,3,4,5,8,10};	//��Ʒ��ֵ 
                            //������ö�ά����B����ֵ  B[k][c]��ʾ͵ǰk����Ʒʱ��������ʱ������c
void knapsack()
{
	for(int k=1;k<N;k++)
	  for(int c=1;c<W;c++)
	  {
	  	if(w[k]>c){
	  		B[k][c]=B[k-1][c];
		  }
		else{
			B[k][c]=max(B[k-1][c],B[k-1][c-w[k]]+v[k]);
		}
	  }
}
int main()
{
	knapsack();
	printf("%d",B[5][20]);
	return 0;
} 
