#include<cstdio>
int n,s,t;
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
    scanf("%d",&n);
    for(int i=0;i<n;i++)s|=read();
    for(int i=0;i<n;i++)t|=read();
    printf("%d",s+t);
}