#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,t,ans,f[1001];
struct node
{
	int u,v,w;
}e[1000001];
bool cmp(node a,node b)
{
	return a.w>b.w;
}
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int a,int b)
{
	int fa=find(a),fb=find(b);
	if(fa!=fb)f[fa]=fb;
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
	m=read();
	for(int i=1;i<=n;i++)f[i]=i;
	while(m--)
	{
		int a=read(),b=read(),c=read();
		e[++cnt]=(node){a,b,c};
	}
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		if(find(e[i].u)!=find(e[i].v))
		{
			t++;
			ans+=e[i].w;
			merge(e[i].u,e[i].v);
		}
	}
	if(t!=n-1)printf("-1");
	else printf("%d",ans);
	return 0;
}
