#include<cstdio>
int hh[2],mm[2],ss[2],t[2],dif,i,ans[3];
bool first;
int main()
{
    for(i=0;i<2;i++)
    {
        scanf("%d:%d:%d",&hh[i],&mm[i],&ss[i]);
        t[i]=3600*hh[i]+60*mm[i]+ss[i];
    }
    if(t[0]==t[1])
    {
        printf("24:00:00");
        return 0;
    }
    dif=t[1]-t[0];
    if(dif<0)dif+=86400;
    ans[0]=dif/3600;
    ans[1]=dif/60%60;
    ans[2]=dif%60;
    for(i=0;i<3;i++)
    {
        if(first)putchar(':');
        if(ans[i]<10)putchar('0');
        printf("%d",ans[i]);
        first=1;
    }
}