#include<iostream>
using namespace std;
const int maxn=101;
struct node
{
    int x,cnt;
}q[maxn*maxn];
int n,a,b,front=1,rear=1;
bool c[maxn][maxn];
int main()
{
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>c[i][j];
    q[1].x=a;
    while(front<=rear)
    {
        for(int i=1;i<=n;i++)
        {
            if(c[q[front].x][i])
            {
                q[++rear].x=i;
                q[rear].cnt=q[front].cnt+1;
                if(i==b)
                {
                    printf("%d",q[rear].cnt-1);
                    return 0;
                }
            }
        }
        front++;
    }
}
