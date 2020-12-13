/*
User: shenyouran
Problem: 2440
Algorithm: Floyd
Time Complexity: O(n^3 + m + t)
Storage Complexity: O(n^2)
*/
#include<stdio.h>
#include<string.h>
int n,m,t,dis[301][301];
int max(int a,int b){return a>b?a:b;}
int main()
{
	memset(dis,0x3f,sizeof(dis));
	scanf("%d%d%d",&n,&m,&t);
	while(m--)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		dis[u][v]=w;
	}
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				int x=max(dis[i][k],dis[k][j]);
				if(dis[i][j]>x)dis[i][j]=x;
			}
		}
	}
	while(t--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(dis[a][b]!=0x3f3f3f3f)printf("%d\n",dis[a][b]);
		else puts("-1");
	}
	return 0;
}