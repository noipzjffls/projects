#include<cstdio>
const int maxn=2e5+1;
struct node
{
    int x,times;
}q[maxn];
int n,k,front=1,rear=1;
bool visit[maxn];
int main()
{
    scanf("%d%d",&n,&k);
    q[1].x=n;
    while(front<=rear)
    {
        for(int i=0;i<3;i++)
        {
            int t=q[rear].x;
            switch(i)
            {
                case 0:
                {
                    if(!visit[t-1]&&t>0)
                    {
                        rear++;
                        q[rear].x=t-1;
                        q[rear].times=q[front].times+1;
                        if(q[rear].x==k)
                        {
                            printf("%d",q[rear].times);
                            return 0;
                        }
                        visit[q[rear].x]=1;
                    }
                    break;
                }
                case 1:
                {
                    if(!visit[t+1]&&t<1e5)
                    {
                        rear++;
                        q[rear].x=t+1;
                        q[rear].times=q[front].times+1;
                        if(q[rear].x==k)
                        {
                            printf("%d",q[rear].times);
                            return 0;
                        }
                        visit[q[rear].x]=1;
                    }
                    break;
                }
                default:
                {
                    if(!visit[t*2]&&t<=1e5)
                    {
                        rear++;
                        q[rear].x=q[front].x*2;
                        q[rear].times=q[front].times+1;
                        if(q[rear].x==k)
                        {
                            printf("%d",q[rear].times);
                            return 0;
                        }
                        visit[q[rear].x]=1;
                    }
                }
            }
        }
        front++;
    }
    printf("0");
}
