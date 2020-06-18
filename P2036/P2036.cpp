#include<bits/stdc++.h>
using namespace std;
int n,ans=1<<30;
bool use[11];
struct node
{
	int sweet,sour;
}food[11];
void dfs(node cur,int k,int limit)
{
	if(k==limit)
	{
		ans=min(abs(cur.sweet-cur.sour),ans);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(use[i])continue;
		use[i]=true;
		dfs((node){cur.sweet+food[i].sweet,cur.sour*food[i].sour},k+1,limit);
		use[i]=false;
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>food[i].sour>>food[i].sweet;
	for(int i=1;i<=n;i++)dfs((node){0,1},0,i);
	cout<<ans;
    return 0;
}
