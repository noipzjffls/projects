/*
User: shenyouran
Problem: 2120
Algorithm: Graph Theory, Shortest Path
Language: C/C++
Record ID: 76216
Submit Time: 2020-11-21 15:28:28
*/
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int n,m,g[101][101],dis[101],pre[101],a[101],cnt,mdis,ans;
int max(int a,int b){return a>b?a:b;}
bool vis[101];
void fprint(int k)
{
	if(pre[k])fprint(pre[k]);
	a[++cnt]=k;
}
void dijkstra1(int s)
{
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	for(int i=1;i<=n;i++)
	{
		int k=0;
		for(int j=1;j<=n;j++)
		{
			if(!vis[j]&&dis[j]<dis[k])
			{
				k=j;
			}
		}
		if(!k)break;
		vis[k]=true;
		for(int j=1;j<=n;j++)
		{
			if(!vis[j]&&dis[k]+g[k][j]<dis[j])
			{
				dis[j]=dis[k]+g[k][j];
				pre[j]=k;
			}
		}
	}
}
int dijkstra2(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	dis[s]=0;
	for(int i=1;i<=n;i++)
	{
		int k=0;
		for(int j=1;j<=n;j++)
		{
			if(!vis[j]&&dis[j]<dis[k])
			{
				k=j;
			}
		}
		if(!k)break;
		vis[k]=true;
		for(int j=1;j<=n;j++)
		{
			if(!vis[j]&&dis[k]+g[k][j]<dis[j])
			{
				dis[j]=dis[k]+g[k][j];
			}
		}
	}
	return dis[n];
}
int read()
{
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x;
}
int main()
{
	memset(g,0x3f,sizeof(g));
	n=read(),m=read();
	while(m--)
	{
		int u=read(),v=read(),w=read();
		g[u][v]=g[v][u]=w;
	}
	dijkstra1(1);
	mdis=dis[n];
	fprint(n);
	for(int i=1;i<cnt;i++)
	{
		g[a[i]][a[i+1]]<<=1;
		g[a[i+1]][a[i]]<<=1;
		ans=max(ans,dijkstra2(1));
		g[a[i]][a[i+1]]>>=1;
		g[a[i+1]][a[i]]>>=1;
	}
	printf("%d",ans-mdis);
	return 0;
}