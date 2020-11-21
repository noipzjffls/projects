/*
User: shenyouran
Problem: 2885
Algorithm: DFS
Language: C/C++
Record ID: 74547
Submit Time: 2020-10-17 15:12:48
*/
#include<stdio.h>
#include<stdbool.h>
int p,s,a[10];
bool b[10];
void dfs(int k)
{
	if(k>9)
	{
		if(a[1]<a[6]&&a[6]<a[9]&&a[2]<a[4]&&a[7]<a[8]&&a[3]<a[5]&&a[1]+a[2]+a[4]+a[6]==a[6]+a[7]+a[8]+a[9]&&a[6]+a[7]+a[8]+a[9]==p&&a[6]+a[7]+a[8]+a[9]==a[9]+a[5]+a[3]+a[1])s++;
		return;
	}
	for(int i=1;i<=9;i++)
	{
		if(b[i])continue;
		a[k]=i;
		b[i]=true;
		dfs(k+1);
		b[i]=false;
	}
}
int main()
{
	scanf("%d",&p);
	if(p<10||p>30)return puts("Not exist"),0;
	dfs(1);
	if(s)printf("%d",s);
	else puts("Not exist");
	return 0;
}