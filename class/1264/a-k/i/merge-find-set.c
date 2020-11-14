/*
User: shenyouran
Problem: 2197
Algorithm: Graph Theory, Merge Find Set
Language: C/C++
Record ID: 75873
Submit Time: 2020-11-14 14:29:13
*/
#include<stdio.h>
#include<stdbool.h>
int n,m,f[251];
bool flag;
int find(int x)
{
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)f[i]=i;
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		f[find(y)]=find(x);
	}
	for(int i=2;i<=n;i++)
	{
		if(find(i)!=find(1))
		{
			printf("%d\n",i);
			flag=true;
		}
	}
	if(!flag)puts("0");
	return 0;
}