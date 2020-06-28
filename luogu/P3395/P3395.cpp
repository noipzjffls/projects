#include<bits/stdc++.h>
int t,land[1001][1001],dx[]={-1,0,0,1},dy[]={0,-1,1,0}; 
bool vis[1001][1001];
struct node
{
	int x,y,t;
}q[1000001];
int main()
{
	scanf("%d",&t);
	for(int i=0,n,front=1,rear=1,ok=0;i<t;++i,front=1,rear=1,ok=0)
	{
		memset(vis,false,sizeof(vis));
		memset(land,0x3f,sizeof(land));
		scanf("%d",&n);
		if(n==1)
		{
			puts("Yes");
			continue;
		}
		for(int j=1,x,y;j<=(n-1)<<1;++j)
		{
			scanf("%d%d",&x,&y);
			land[x][y]=j;
		}
		q[1]=(node){1,1,0};
		while(front<=rear)
		{
			node f=q[front];
			for(int i=0;i<4;i++)
			{
				int nx=f.x+dx[i],ny=f.y+dy[i];
				if(nx<1||ny<1||nx>n||ny>n||vis[nx][ny]||f.t+1>land[nx][ny])continue;
				vis[nx][ny]=true;
				q[++rear]=(node){nx,ny,f.t+1};
				if(nx==n&&ny==n)
				{
					puts("Yes");
					ok=1;
					break;
				}
			}
			if(ok)break;
			front++;
		}
		if(!ok)puts("No");
	}
	return 0;
}
