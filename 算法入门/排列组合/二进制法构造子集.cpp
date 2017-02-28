
#include <iostream>
#include <limits.h>
#include <string.h>
using namespace std;


void print_subset(int n,int s)
{
	for(int i=0;i<n;i++)
		if(s&(1<<i)) cout<<i;
	cout<<endl;
}
int main()
{
	for(int i=0;i<(1<<8);i++)
	  print_subset(8,i); 
	return 0;
} 
