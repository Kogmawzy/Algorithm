#include <iostream>  
#include <string>  
using namespace std;  
void extgcd(int a,int b,int &d,int &x,int &y)
{
	if(!b){	d=a; x=1; y=0;	}
	else { extgcd(b,a%b,d,y,x); y-=a/b*x;}
} 

int main(){  
	 int x,y,d;
     extgcd(4,11,d,x,y);
     cout<<d<<" "<<x<<" "<<y;
} 
