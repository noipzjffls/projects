#include<bits/stdc++.h>
using namespace std;
int n,f[1000001]={1,1},g[1000001]={0,1},m=1e4; 
int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		f[i]=((f[i-1]+f[i-2])%m+(g[i-2]<<1)%m)%m;
		g[i]=(g[i-1]+f[i-1])%m;
	}
	cout<<f[n];
	return 0;
}
