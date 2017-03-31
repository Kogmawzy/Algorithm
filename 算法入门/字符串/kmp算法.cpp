#include <bits/stdc++.h> 
using namespace std;
int f[15000];
void init(string s)
{
	memset(f,0,sizeof(f));
	for(int i=1;i<s.size();i++)
	{
		int j=f[i];
		while(j && s[i]!=s[j])
			j=f[j];
		f[i+1]=(s[i]==s[j])?j+1:0;
	}
}
int find(string a,string s)
{
	init(s);int j=0;
	for(int i=0;i<a.size();i++)
	{
		while(j && a[i]!=s[j])
			j=f[j];
		if(a[i]==s[j])
			j++;
		if(j==s.size())
			return i-s.size()+1;
	}
}
int main()
{
   cout<< find("asdasdasdasd","dasd");
    return 0;
}
