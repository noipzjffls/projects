#include<cstdio>
#include<queue>
#include<algorithm>
std::queue<int>q;
int n,k,p,idx,cnt=1,i,b[1000001];
int main()
{
    scanf("%d%d%d",&n,&k,&p);
    for(i=1;i<=k;i++)q.push(i);
    while(idx<=k/n)
    {
        if(cnt%n==0)
        {
            idx++;
            b[idx]=q.front();
        }
        q.pop();
        for(i=1;i<=p;i++)
        {
            q.push(q.front());
            q.pop();
        }
        cnt++;
    }
    std::sort(b+1,b+k/n+1);
    for(i=1;i<=k/n;i++)printf("%d\n",b[i]);
}
