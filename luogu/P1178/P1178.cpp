#include<bits/stdc++.h>
using namespace std;
int days[]={0,31,29,31,30,31,30,31,31,30,31,30,31},t[13][32],n,a[367],ans,cur=1;
void init()
{
    for(int tot=1,m=1,d=1;tot<=366;tot++,d++)
    {
        if(d>days[m])
        {
            d=1;
            m++;
        }
        t[m][d]=tot;
    }
}
int main()
{
    init();
    scanf("%d",&n);
    for(int i=1,x,y;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        a[i]=t[x][y];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,a[i]-cur-1);
        cur=a[i];
    }
    printf("%.0f",max(ans,366-a[n])*86400/366.0);
    return 0;
}