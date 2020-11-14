/*
User: shenyouran
Problem: 2140
Algorithm: Binary Tree, DFS
Language: C/C++
Record ID: 75220
Submit Time: 2020-10-31 13:54:27
*/
#include<stdio.h>
int n;
struct node
{
	int ls,rs,fa;
	char id;
}a[27];
void pre(int x)
{
	putchar(a[x].id);
	if(a[x].ls)pre(a[x].ls);
	if(a[x].rs)pre(a[x].rs);
}
void ord(int x)
{
	if(a[x].ls)ord(a[x].ls);
	putchar(a[x].id);
	if(a[x].rs)ord(a[x].rs);
}
void suf(int x)
{
	if(a[x].ls)suf(a[x].ls);
	if(a[x].rs)suf(a[x].rs);
	putchar(a[x].id);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)a[i].fa=i;
	for(int i=1,l,r,id;i<=n;i++)
	{
		char s[3];
		scanf("%s%d%d",s,&a[i].ls,&a[i].rs);
		a[i].id=s[0];
		a[a[i].ls].fa=a[a[i].rs].fa=i;
	}
	pre(1);
	putchar('\n');
	ord(1);
	putchar('\n');
	suf(1);
	return 0;
}