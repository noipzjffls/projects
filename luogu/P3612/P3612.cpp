#include<bits/stdc++.h>
using namespace std;
string s;
long long n,len,temp; 
int main()
{
	cin>>s>>n;
	temp=len=s.size();
	while(len<n)len<<=1;
	len>>=1;
	while(n>temp)
	{
		if(n-len>1)n-=len+1;
		else if(n-len==1)n=len;
		len>>=1; 
	}
	cout<<s[n-1];
	return 0;
}
