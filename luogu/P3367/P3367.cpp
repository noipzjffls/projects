#include<bits/stdc++.h>
using namespace std;
int n,m,f[10001];
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
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=n;i++)f[i]=i;
    while(m--)
    {
        if(read()==1)f[find(read())]=f[find(read())];
        else puts(find(read())==find(read())?"Y":"N");
    }
}