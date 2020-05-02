#include<cstdio>
const int MAXN=1e5;
int q[MAXN]={0,2,3,5,7},a[MAXN],f=1,r=4,x,y,m[]={1,3,7,9},i;
bool p(int n)
{
    if(n<2)return 0;
    for(int i=2;i*i<=n;i++)if(n%i==0)return 0;
    return 1;
}
int main()
{
    scanf("%d",&x);
    while(f<r)
    {
        if(q[f]>x)break;
        a[++y]=q[f];
        for(i=0;i<4;i++)if(p(q[f]*10+m[i]))q[++r]=q[f]*10+m[i];
        f++;
    }
    printf("%d\n",y);
    for(i=1;i<=y;i++)printf("%d\n",a[i]);
}
