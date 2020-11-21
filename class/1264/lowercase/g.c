/*
User: shenyouran
Problem: 2838
Algorithm: Binary Tree, DFS
Language: C/C++
Record ID: 75253
Submit Time: 2020-10-31 15:29:56
*/
#include<stdio.h>
#include<stdbool.h>
int n,ans;
struct node
{
	int l,r,val,cnt;
}a[1000001];
int dfs(int k)
{
	if(k==-1)return 0;
	return a[k].cnt=dfs(a[k].l)+dfs(a[k].r)+1;
}
bool check(int l,int r)
{
	if(a[l].cnt!=a[r].cnt||a[l].val!=a[r].val)return false;
	if(l==-1&&r==-1)return true;
	return check(a[l].l,a[r].r)&check(a[l].r,a[r].l);
}
void DFS(int k)
{
	if(k==-1)return;
	if(ans<a[k].cnt&&check(a[k].l,a[k].r))ans=a[k].cnt;
	DFS(a[k].l);
	DFS(a[k].r);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].val);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].l,&a[i].r);
	dfs(1);
	DFS(1);
	printf("%d",ans);
	return 0;
}