#include<bits/stdc++.h>
using namespace std;
clock_t start,finish,s1,f1;
double duration,dur;
int i=0;
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
long long ans[21][21][21],x,y,z;
long long w(long long a,long long b,long long c)
{
    if(a<=0||b<=0||c<=0)return 1;
    if(a>20||b>20||c>20)return w(20,20,20);
    if(ans[a][b][c]>0)return ans[a][b][c];
    if(a<b&&b<c)return ans[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    return ans[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}
int main()
{
    freopen("input.txt","r",stdin);
    s1=clock();
    while(true)
    {
        x=read();
        y=read();
        z=read();
        if(x==-1&&y==-1&&z==-1)break;
        start=clock();
        printf("w(%lld, %lld, %lld) = %lld\n",x,y,z,w(x,y,z));
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