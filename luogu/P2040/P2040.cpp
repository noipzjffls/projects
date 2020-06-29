#include<bits/stdc++.h>
using namespace std;
int maps[4][4],dx[]={0,-1,0,0,1},dy[]={0,0,-1,1,0};
bool click[4][4];
bool check()
{
    for(int i=1;i<4;i++)
    {
        for(int j=1;j<4;j++)
        {
            if(!maps[i][j])return false;
        }
    }
    return true;
}
void change(int x,int y)
{
    for(int i=0;i<5;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<1||ny<1||nx>3||ny>3)continue;
        maps[nx][ny]^=1;
    }
}
void dfs(int step)
{
    if(check())
    {
        printf("%d",step);
        exit(0);
    }
    for(int i=1;i<4;i++)
    {
        for(int j=1;j<4;j++)
        {
            if(click[i][j])continue;
            click[i][j]=true;
            change(i,j);
            dfs(step+1);
            change(i,j);
            click[i][j]=false;
        }
    }
}
int main()
{
    for(int i=1;i<4;i++)
    {
        for(int j=1,x;j<4;j++)
        {
            scanf("%d",&maps[i][j]);
        }
    }
    for(int i=1;i<4;i++)
    {
        for(int j=1,x;j<4;j++)
        {
            dfs(0);
        }
    }
    return 0;
}