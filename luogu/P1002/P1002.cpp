#include<bits/stdc++.h>
using namespace std;
int m,n,kx,ky,dx[]={-2,-2,-1,-1,1,1,2,2},dy[]={-1,1,-2,2,-2,2,-1,1};
long long f[21][21];
bool flag[21][21];
int read()
{
	char ch=getchar();
	int x=0,f=1;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int main()
{
	n=read(), m=read(), kx=read(), ky=read();
	f[0][0]=1;
	flag[kx][ky]=true;
	for(int i=0;i<8;i++)
	{
		int nx=kx+dx[i],ny=ky+dy[i];
		if(nx<0||ny<0||nx>n||ny>m)continue;
		flag[nx][ny]=true;
	}
	for(int i=1;i<=n;i++)if(!flag[i][0])f[i][0]+=f[i-1][0];
	for(int i=1;i<=m;i++)if(!flag[0][i])f[0][i]+=f[0][i-1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(flag[i][j])continue;
			f[i][j]+=max(f[i][j],f[i-1][j]+f[i][j-1]);
		}
	}
	printf("%lld",f[n][m]);
	return 0;
}
