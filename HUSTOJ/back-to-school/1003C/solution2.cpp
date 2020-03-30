#include<bits/stdc++.h>
using namespace std;
int cnt[270],loc[270];
int main()
{
	memset(loc,0x3f,sizeof(loc));
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<0) s[i]+=256;
		cnt[s[i]]++;
		loc[s[i]]=min(loc[s[i]],i);
	}
	int ans=0,lo=1000001,cn=0;
	for(int i=0;i<=260;i++)
	{
		if(cnt[i]>cn){
			ans=i;
			lo=loc[i];
			cn=cnt[i];
		}
		if(cnt[i]==cn&&lo>loc[i]){
			ans=i;
			lo=loc[i];
		}
	}
	if(ans>=128) ans-=256;
	printf("%c",ans);
}