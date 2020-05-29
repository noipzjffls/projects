#include<bits/stdc++.h>
using namespace std;
int n,f[2]={1,1},g[2]={0,1},m=1e4; 
int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		int t1=(f[1]+f[0])%m+(g[0]<<1)%m;
		int t2=g[1]+f[1];
		f[0]=f[1];
		g[0]=g[1];
		f[1]=t1%m;
		g[1]=t2%m;
	}
	printf("%d",f[1]);
	return 0;
}
