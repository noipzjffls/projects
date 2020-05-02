#include<cstdio>
#include<algorithm>
const int MAXN=1100005,MAXM=105;
int a[MAXN],b[MAXM],front=1,rear,idx,cnt=1,n,k,p,i;
int main()
{
    scanf("%d%d%d",&n,&k,&p);
    rear=k+1;
    for(i=1;i<=k;i++)a[i]=i;
    while(idx<=k/n)
    {
        if(cnt%n==0)b[++idx]=a[front];
        front++;
        for(i=1;i<=p;i++)a[rear++]=a[front++];
        cnt++;
    }
    std::sort(b+1,b+1+k/n);
    for(i=1;i<=k/n;i++)printf("%d\n",b[i]);
}
