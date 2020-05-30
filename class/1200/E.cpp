#include<bits/stdc++.h>
using namespace std;
int n,m,f[40001];
int point(int a,int b)
{
	return n*(a-1)+b;
}
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*n;i++)f[i]=i;
	for(int step=1;step<=m;step++)
	{
		int u,v,p,P;
		char ch;
		scanf("%d%d %c",&u,&v,&ch);
		p=point(u,v);
		if(ch=='D')P=p+n;
		else P=p+1;
		int x=find(p),y=find(P);
		if(x==y)
		{
			cout<<step;
			return 0;
		}
		f[x]=y;
	}
	cout<<"draw";
	return 0;
}
