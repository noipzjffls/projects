/*
User: shenyouran
Problem: 2541
Algorithm: DFS
Language: C/C++
Record ID: 74864
Submit Time: 2020-10-24 14:06:41
*/
#include<stdio.h>
#include<stdbool.h>
int a[6][6],s;
const int dx[]={-1,0,0,1},dy[]={0,-1,1,0};
bool vis[1000001];
void dfs(int x,int y,int step,int val)
{
    if(step>5)
    {
        if(!vis[val])
        {
            vis[val]=true;
            s++;
        }
        return;
    }
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<1||ny<1||nx>5||ny>5)continue;
        dfs(nx,ny,step+1,val*10+a[nx][ny]); 
    }
}
int main()
{
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            dfs(i,j,1,a[i][j]);
        }
    }
    printf("%d",s);
    return 0;
}