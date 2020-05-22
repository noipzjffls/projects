#include<bits/stdc++.h>
using namespace std;
string str;
string rep(string s)
{
	int t=0;
	for(int i=0;s[i];i++)
	{
		if(isdigit(s[i]))t=(t<<3)+(t<<1)+(s[i]^48);
		else break;
	}
	string x="",y="";
	for(int i=s.size()-1;i>=0;i--)
	{
		if(isalpha(s[i]))x+=s[i];
		else break;
	}
	reverse(x.begin(),x.end());
	while(t--)y+=x;
	return y;
}
int main()
{
	cin>>str;
	while(true)
	{
		int l=-1,r=-1;
		for(int i=str.size()-1;i>=0;i--)
		{
			if(str[i]=='[')
			{
				l=i;
				break;
			}
		}
		if(l==-1)break;
		for(int i=l;str[i];i++)
		{
			if(str[i]==']')
			{
				r=i;
				break;
			}
		}
		string ns="";
		for(int i=l+1;i<r;i++)ns+=str[i];
		str=str.replace(l,r-l+1,rep(ns));
	}
	cout<<str;
	return 0;
}
