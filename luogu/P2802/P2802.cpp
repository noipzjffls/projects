#include<bits/stdc++.h>
int n,m,ex,ey,front=1,rear=1,maps[10][10],vis[10][10],dx[]={-1,0,0,1},dy[]={0,-1,1,0};
struct node
{
	int x,y,t,hp;
}q[4051];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			scanf("%d",&maps[i][j]);
			switch(maps[i][j])
			{
				case 2:
				{
					q[1]=(node){i,j,0,6};
					break;
				}
				case 3:
				{
					ex=i;
					ey=j;
					break;
				}
			}
		}
	}
	while(front<=rear)
	{
		node f=q[front];
		for(int i=0;i<4;i++)
		{
			int nx=f.x+dx[i],ny=f.y+dy[i];
			if(nx<1||ny<1||nx>n||ny>m||!maps[nx][ny]||f.hp<2||vis[nx][ny]>50)continue;
			vis[nx][ny]++;
			q[++rear]=(node){nx,ny,f.t+1,f.hp-1};
			if(maps[nx][ny]==4)q[rear].hp=6;
			if(nx==ex&&ny==ey)
			{
				printf("%d",q[rear].t);
				return 0;
			}
		}
		front++;
	}
	puts("-1");
	return 0;
}
