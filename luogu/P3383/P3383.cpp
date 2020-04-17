#include<bits/stdc++.h>
const int maxn=1e8+1;
int n,q,x,prime[maxn];
bool vis[maxn];
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
void write(int x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9)write((x>>1)/5);
    putchar(x%10+'0');
}
void f()
{
    for(int i=2;i<=maxn;i++)
    {
        if(!vis[i])prime[++prime[0]]=i;
        for(int j=1;i*prime[j]<=maxn&&j<=prime[0];j++)
        {
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
int main()
{
    f();
    n=read();
    q=read();
    while(q--)
    {
        x=read();
        write(prime[x]);
        putchar('\n');
    }
}