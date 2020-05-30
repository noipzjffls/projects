#include<bits/stdc++.h>
using namespace std;
int n,m,ans,f[1000001],X1,X2,Y1,Y2,p1,p2,dx[]={1,0},dy[]={0,1};
int point(int a,int b)
{
	return n*(a-1)+b;
}
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int a,int b)
{
	f[find(a)]=f[find(b)];
}
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n*m;i++)f[i]=i;
	while(scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2)!=EOF)
	{
		p1=point(X1,Y1);
		p2=point(X2,Y2);
		merge(p1,p2);
	}
	for(int i=1;i<=n*m;i++)
	{
		int j=i+n;
		if(j<=n*m&&find(i)!=find(j))
		{
			merge(i,j);
			ans++;
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		int j=i+1;
		if(j<=n*m&&j%n!=1&&find(i)!=find(j))
		{
			merge(i,j);
			ans+=2;
		}
	}
	cout<<ans;
	return 0;
}
