#include<cstdio>
#include<queue>
std::queue<int>q1,q2;
int m,n,i,k,f1=1,f2=1,r1,r2;
int main()
{
    scanf("%d%d%d",&m,&n,&k);
    r1=m+1;
    r2=n+1;
    for(i=1;i<=m;i++)q1.push(i);
    for(i=1;i<=n;i++)q2.push(i);
    for(i=1;i<=k;i++)
    {
        printf("%d %d\n",q1.front(),q2.front());
        q1.push(q1.front());
        q2.push(q2.front());
        q1.pop();
        q2.pop();
    }
}
