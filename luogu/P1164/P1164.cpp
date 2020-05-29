#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,a[101],f[101],ans;
void dfs(int num,int money)
{
	if(money==m)
	{
		ans++;
		return;
	}
	if(money>m)return;
	for(int i=num+1;i<=n;i++)dfs(i,money+a[i]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int t;
		scanf("%d",&t);
		if(t>m)continue;
		a[++cnt]=t;
	}
	n=cnt;
	for(int i=1;i<=n;i++)f[i]=f[i-1]+a[i];
	for(int i=1;i<=n;i++)dfs(i,a[i]);
	cout<<ans;
	return 0;
}
