#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <string.h>
using namespace std;
int n;


void print(vector<int> a,set<int> m)
{
	if(m.empty())
	{
		for(int i=0;i<a.size();i++)
			cout<<a[i];
		cout<<endl;
	}
        
    else{
    	set<int>::iterator it;                             
		for(it=m.begin();it != m.end();it++)
		{    
			vector<int> b(a);
			set<int> m_temp(m);
			m_temp.erase(m_temp.find(*it));
			b.push_back(*it);
		    print(b,m_temp);
		}

        }
} 
int main()
{
	vector<int> a;
	vector<int> b;

	int arr[]={1,2,3,4,3,2,1};   
    set<int> s(arr,arr+sizeof(arr)/sizeof(*arr));


	print(a,s);
	
	return 0;
} 
