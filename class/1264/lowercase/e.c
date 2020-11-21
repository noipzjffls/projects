/*
User: shenyouran
Problem: 1307
Algorithm: DFS
Language: C/C++
Record ID: 74943
Submit Time: 2020-10-24 15:47:32
*/
#include<stdio.h>
#include<stdbool.h>
int n,m,sx,sy,ex,ey,r[290][2];
bool maps[18][18],vis[18][18],flag;
const int dx[]={-1,0,0,1},dy[]={0,-1,1,0};
void dfs(int x,int y,int k)
{
	if(x==ex&&y==ey)
	{
		flag=true;
		printf("(1,1)");
		for(int i=1;i<k;i++)printf("->(%d,%d)",r[i][0],r[i][1]);
		putchar('\n');
		return;
	}
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<1||ny<1||nx>n||ny>m||!maps[nx][ny]||vis[nx][ny])continue;
		r[k][0]=nx,r[k][1]=ny;
		vis[nx][ny]=true;
		dfs(nx,ny,k+1);
		vis[nx][ny]=false;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&maps[i][j]);
		}
	}
	scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
	vis[sx][sy]=true;
	dfs(sx,sy,1);
	if(!flag)puts("-1");
	return 0;
}