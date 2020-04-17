#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001];
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
    getchar();
    for(int i=1;i<=n;i++)
    {
        char c=getchar();
        a[i]=(c=='I')?0:(c=='O')?1:-1;
    }
    while(m--)
    {
        int t;
        t=read();
        if(t==1)
        {
            int x;
            char c;
            x=read();
            c=getchar();
            a[x-1]=(c=='I')?0:1;
        }
        else
        {
            int l,r,cnt=0;
            l=read();
            r=read();
            for(int i=l;i<=r;i++)
            {
                for(int j=i+1;j<=r;j++)
                {
                    for(int k=j+1;k<=r;k++)
                    {
                        if(!a[i-1]&&a[j-1]==1&&!a[k-1])
                        {
                            cnt++;
                        }
                    }
                }
            }
            printf("%d\n",cnt);
        }
    }
}