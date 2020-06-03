#include<bits/stdc++.h>
using namespace std;
int n,x,temp,last;
long long ans;
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
    scanf("%d%d%d",&n,&x,&temp);
    if(temp>x)
    {
        ans=temp-x;
        temp=x;
    }
    n--;
    while(n--)
    {
        last=temp;
        temp=read();
        if(last+temp>x)
        {
            ans+=last+temp-x;
            temp=x-last;
        }
    }
    printf("%lld",ans);
    return 0;
}