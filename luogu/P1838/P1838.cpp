#include<bits/stdc++.h>
using namespace std;
int grid[3][3],dx[]={-1,-1,-1,0,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
char ch,text[2][12]={"uim wins.","xiaoa wins."};
void dfs(int x,int y,int k,int dir)
{
    if(x<0||y<0||x>2||y>2)return;
    if(k==3)
    {
        puts(text[grid[x][y]]);
        exit(0);
    }
    int nx=x+dx[dir],ny=y+dy[dir];
    if(grid[nx][ny]==grid[x][y])dfs(nx,ny,k+1,dir);
}
int main()
{
    memset(grid,-1,sizeof(grid));
    for(int t=0,x,y;;t=!t,ch=getchar())
    {
        if(ch=='\n')break;
        grid[((ch^48)-1)/3][((ch^48)-1)%3]=t;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(grid[i][j]==-1)continue;
            for(int k=0;k<8;k++)dfs(i,j,1,k);
        }
    }
    puts("drew.");
    return 0;
}