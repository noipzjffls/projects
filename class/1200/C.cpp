#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,ans,f[2001];
struct node
{
	int u,v,w;
	bool flag;
}e[4000001];
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
bool cmp(node a,node b)
{
	if(a.flag!=b.flag)return a.flag<b.flag;
	return a.w<b.w;
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
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)f[i]=i;
	while(m--)
	{
		int p=read(),U=read(),V=read(),W=read();
		e[++cnt]=(node){U,V,W,false};
		if(p==1)
		{
			ans+=W;
			e[cnt].flag=true;
			merge(U,V);
		}
	}
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		if(e[i].flag)break;
		if(find(e[i].u)!=find(e[i].v))
		{
			ans+=e[i].w;
			merge(e[i].u,e[i].v);
		}
	}
	printf("%d",ans);
	return 0;
}
