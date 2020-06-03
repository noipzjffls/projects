#include<bits/stdc++.h>
using namespace std;
int n,last,temp;
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
    scanf("%d%d",&n,&temp);
    ans=temp;
    n--;
    while(n--)
    {
        last=temp;
        temp=read();
        if(temp>last)ans+=temp-last;
    }
    printf("%lld",ans);
    return 0;
}