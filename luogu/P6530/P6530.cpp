#include<bits/stdc++.h>
using namespace std;
int n,price[100001],ans;
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
bool compare(int a,int b)
{
    return a>b;
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++)price[i]=read();
    sort(price+1,price+n+1,compare);
    for(int i=1;i<=n/3*3;i++)if(i%3)ans+=price[i];
    for(int i=n/3*3+1;i<=n;i++)ans+=price[i];
    printf("%d",ans);
    return 0;
}