#include<bits/stdc++.h>
using namespace std;
int t,n,m,kx[]={-1,-1,-1,0,0,1,1,1},ky[]={-1,0,1,-1,1,-1,0,1},nx[]={-2,-2,-1,-1,1,1,2,2},ny[]={-1,1,-2,2,-2,2,-1,1},front,rear;
bool b[11][11];
char c;
struct node
{
    int cnt,dx,dy;
}q[100005];
bool king(int x,int y)
{
    for(int i=0;i<8;i++)
    {
        int Nx=x+kx[i],Ny=y+ky[i];
        if(Nx>0&&Ny>0&&Nx<=n&&Ny<=m&&b[Nx][Ny])return 0;
    }
    return 1;
}
bool rook(int x,int y)
{
    for(int i=x-1;i;i--)if(b[i][y])return 0;
    for(int i=x+1;i<=n;i++)if(b[i][y])return 0;
    for(int i=y-1;i;i--)if(b[x][i])return 0;
    for(int i=y+1;i<=m;i++)if(b[x][i])return 0;
    return 1;
}
bool knight(int x,int y)
{
    for(int i=0;i<8;i++)
    {
        int Nx=x+nx[i],Ny=y+ny[i];
        if(Nx>0&&Ny>0&&Nx<=n&&Ny<=m&&b[Nx][Ny])return 0;
    }
    return 1;
}
bool bishop(int x,int y)
{
    for(int i=x-1,j=y-1;i&&j;i--,j--)if(b[i][j])return 0;
    for(int i=x-1,j=y+1;i&&j<=m;i--,j++)if(b[i][j])return 0;
    for(int i=x+1,j=y-1;i<=n&&j;i++,j--)if(b[i][j])return 0;
    for(int i=x+1,j=y+1;i<=n&&j<=m;i++,j++)if(b[i][j])return 0;
    return 1;
}
bool queen(int x,int y)
{
    return rook(x,y)*bishop(x,y);
}
bool check(int x,int y,char c)
{
    switch(c)
    {
        case 'Q':return queen(x,y);
        case 'r':return rook(x,y);
        case 'k':return knight(x,y);
        default:return king(x,y);
    }
    return 0;
}
void init(int id)
{
    b[q[id].dx][q[id].dy]=1;
    if(id==1)return;
    for(int i=id-1;i;i--)
    {
        if(q[id].cnt-1==q[i].cnt)
        {
            init(i);
            break;
        }
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        getchar();
        c=getchar();
        scanf("%d%d",&n,&m);
        q[1].cnt=1;
        q[1].dx=1;
        q[1].dy=1;
        front=rear=1;
        while(front<=rear)
        {
            for(int i=q[front].dx+1;i<=n;i++)
            {
                for(int j=q[front].dy+1;j<=m;j++)
                {
                    memset(b,0,sizeof(b));
                    rear++;
                    q[rear].dx=i;
                    q[rear].dy=j;
                    init(rear);
                    if(check(i,j,c))q[rear].cnt=q[front].cnt+1;
                    else rear--;
                }
            }
            front++;
        }
        printf("%d\n",q[rear].cnt);
    }
}