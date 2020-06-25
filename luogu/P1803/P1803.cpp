#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool vis[1000001];
struct node
{
    int l,r;
}p[1000001];
bool cmp(node a,node b)
{
    if(a.r!=b.r)return a.r<b.r;
    return a.l<b.l;
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
        p[i].l=read();
        p[i].r=read();
    }
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        vis[i]=true;
        ans++;
        for(int j=i+1;j<=n;j++)
        {
            if(p[j].l<p[i].r)vis[j]=true;
            else break;
        }
    }
    printf("%d",ans);
    return 0;
}