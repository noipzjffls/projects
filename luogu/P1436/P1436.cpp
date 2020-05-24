#include<bits/stdc++.h>
using namespace std;
int f[1001],n,m,ans;
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
int find(int x)
{
    if(f[x]==x)return x;
    return f[x]=find(f[x]);
}
void merge(int a,int b)
{
    int fa=find(a),fb=find(b);
    if(fa!=fb)f[fa]=fb;
}
int main()
{
    while(cin>>n>>m)
    {
        ans=0;
        for(int i=1;i<=n;i++)f[i]=i;
        while(m--)
        {
            int u=read(),v=read();
            if(find(u)!=find(v))merge(u,v);
        }
        for(int i=1;i<=n;i++)ans+=i==find(i);
        printf("%d\n",ans-1);
    }
    return 0;
}