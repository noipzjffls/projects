#include<bits/stdc++.h>
using namespace std;
int n,x_1,y_1,x_2,y_2,pr,pb,pq,pn,ans[101][101],dx[]={-2,-2,-1,-1,1,1,2,2},dy[]={-1,1,-2,2,-2,2,-1,1};
bool vis[101][101];
void search(int x,int y,int cost)
{
    if(cost>=ans[x][y])return;
    ans[x][y]=cost;
    for(int i=x+1;i<=n;i++)
    {
        if(!vis[i][y])
        {
            vis[i][y]=true;
            search(i,y,cost+(i-x)*pr);
            vis[i][y]=false;
        }
    }
    for(int i=x-1;i;i--)
    {
        if(!vis[i][y])
        {
            vis[i][y]=true;
            search(i,y,cost+(x-i)*pr);
            vis[i][y]=false;
        }
    }
    for(int i=y+1;i<=n;i++)
    {
        if(!vis[x][i])
        {
            vis[x][i]=true;
            search(x,i,cost+(i-y)*pr);
            vis[x][i]=false;
        }
    }
    for(int i=y-1;i;i--)
    {
        if(!vis[x][i])
        {
            vis[x][i]=true;
            search(x,i,cost+(y-i)*pr);
            vis[x][i]=false;
        }
    }
    for(int i=x+1,j=y+1,k=0;i<=n&&j<=n;i++,j++,k+=2)
    {
        if(!vis[i][j])
        {
            vis[i][j]=true;
            search(i,j,cost+k*pb);
            vis[i][j]=false;
        }
    }
    for(int i=x+1,j=y-1,k=0;i<=n&&j;i++,j--,k+=2)
    {
        if(!vis[i][j])
        {
            vis[i][j]=true;
            search(i,j,cost+k*pb);
            vis[i][j]=false;
        }
    }
    for(int i=x-1,j=y+1,k=0;i&&j<=n;i--,j++,k+=2)
    {
        if(!vis[i][j])
        {
            vis[i][j]=true;
            search(i,j,cost+k*pb);
            vis[i][j]=false;
        }
    }
    for(int i=x-1,j=y-1,k=0;i&&j;i--,j--,k+=2)
    {
        if(!vis[i][j])
        {
            vis[i][j]=true;
            search(i,j,cost+k*pb);
            vis[i][j]=false;
        }
    }
    for(int i=0;i<8;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<1||ny<1||nx>n||ny>n||vis[nx][ny])continue;
        vis[nx][ny]=true;
        search(nx,ny,cost+1);
        vis[nx][ny]=false;
    }
}
int main()
{
    memset(ans,0x7f,sizeof(ans));
    cin>>n>>x_1>>y_1>>x_2>>y_2>>pr>>pb>>pq>>pn;
    if(pq<pr)pr=pq;
    if(pq<pb)pb=pq;
    search(x_1,y_1,0);
    cout<<ans[x_2][y_2];
    return 0;
}