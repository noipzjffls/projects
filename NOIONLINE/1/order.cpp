#include<bits/stdc++.h>
using namespace std;
int n,i,j,k,y;
struct f
{
    int a,b,c;
}x[100001];
bool cmp(f l,f m)
{
    int A=min(min(l.a,l.b),l.c),B=min(min(m.a,m.b),m.c);
    if(A!=B)return A>B;
    return l.a+l.b+l.c>m.a+m.b+m.c;
}
int main()
{
    freopen("order.in","r",stdin);
    freopen("order.out","w",stdout);
    scanf("%d",&n);
    if(n<3)
    {
        printf("-1");
        return 0;
    }
    for(i=0;i<=n/7;i++)
    {
        for(j=0;j<=n/4;j++)
        {
            if((n-i*7-j*4)%3)continue;
            k=(n-i*7-j*4)/3;
            if(k<0)continue;
            x[++y].a=i;
            x[y].b=j;
            x[y].c=k;
        }
    }
    if(!y)
    {
        printf("-1");
        return 0;
    }
    sort(x+1,x+y+1,cmp);
    printf("%d %d %d",x[1].a,x[1].b,x[1].c);
    return 0;
}
