#include<bits/stdc++.h>
const int N=1e3+1;
int n,k,s[N],a[N][N],sum,tot,team[N],name[N];
float ave;
struct student
{
    int score,num;
}stu[N];
bool cmp(student x,student y)
{
    if(x.score!=y.score)return x.score>y.score;
    return x.num<y.num;
}
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
    n=read();
    k=read();
    for(int i=1;i<=n;i++)
    {
        s[i]=read();
        name[i]=getchar()-'A'+1;
    }
    for(int i=1;i<=k;i++)for(int j=1;j<=k;j++)a[i][j]=read();
    for(int i=1;i<=k;i++)
    {
        sum=tot=0;
        for(int j=1;j<=k;j++)sum+=a[j][i];
        ave=1.0*sum/k;
        sum=0;
        for(int j=1;j<=k;j++)
        {
            if(fabs(ave-a[j][i])<=15)
            {
                tot++;
                sum+=a[j][i];
            }
        }
        team[i]=int(round(1.0*sum/tot));
    }
    for(int i=1;i<=n;i++)
    {
        stu[i].num=name[i];
        stu[i].score=int(round(0.6*s[i]+0.4*team[name[i]]));
    }
    std::sort(stu+1,stu+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        printf("%d",stu[i].score);
        putchar(' ');
        putchar(stu[i].num+'A'-1);
        putchar('\n');
    }
}