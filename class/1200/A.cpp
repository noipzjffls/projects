#include<bits/stdc++.h>
using namespace std;
int n,cnt,ans,f[101];
struct node
{
	int u,v,w;
}e[10001];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int a,int b)
{
	f[find(a)]=find(b);
}
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
		for(int j=1;j<=n;j++)
		{
			int x=read();
			if(j>=i)continue;
			e[++cnt]=(node){i,j,x};
		}
	}
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		if(find(e[i].u)!=find(e[i].v))
		{
			ans+=e[i].w;
			merge(e[i].u,e[i].v);
		}
	}
	printf("%d",ans);
	return 0;
}
