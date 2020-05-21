#include<bits/stdc++.h>
using namespace std;
int n,m,q,f[20001];
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
void Merge(int a,int b)
{
    int fa=find(a),fb=find(b);
    if(fa!=fb)f[fa]=fb;
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)f[i]=i;
    while(m--)Merge(read(),read());
    while(q--)
    {
        int x=find(read()),y=find(read());
        if(x==y)puts("Y");
        else puts("N");
    }
    return 0;
}