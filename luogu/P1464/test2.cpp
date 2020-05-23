#include<bits/stdc++.h>
clock_t start,finish,s1,f1;
double duration,dur;
int i=0;
long long a,b,c;
bool flag;
long long read()
{
    long long x=0,f=1;
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
int f(long long a,long long b,long long c)
{
    if(1.0*(clock()-start)/CLOCKS_PER_SEC>10&&!flag)
    {
        flag=true;
        puts("Time > 10s!");
    }
    if(flag)return -1;
    if(a<=0||b<=0||c<=0)return 1;
    if(a>20||b>20||c>20)return f(20,20,20);
    if(a<b&&b<c)return f(a,b,c-1)+f(a,b-1,c-1)-f(a,b-1,c);
    return f(a-1,b,c)+f(a-1,b-1,c)+f(a-1,b,c-1)-f(a-1,b-1,c-1);
}
int main()
{
    freopen("input.txt","r",stdin);
    s1=clock();
    while(true)
    {
        a=read(),b=read(),c=read();
        if(a==-1&&b==-1&&c==-1)break;
        flag=false;
        start=clock();
        int ans=f(a,b,c);
        if(ans==-1)continue;
        printf("w(%lld, %lld, %lld) = %d\n",a,b,c,f(a,b,c));
        finish=clock();
        duration=1.0*(finish-start)/CLOCKS_PER_SEC;
        i++;
        printf("Time used for data %d: %f sec\n",i,duration);
    }
    f1=clock();
    dur=1.0*(f1-s1)/CLOCKS_PER_SEC;
    printf("Time used for whole program: %f sec\n",dur);
    return 0;
}