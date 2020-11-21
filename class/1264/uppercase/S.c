/*
User: shenyouran
Problem: 1331
Algorithm: DFS/BFS
Language: C/C++
Record ID: 74501
Submit Time: 2020-10-17 13:42:48
*/
#include<stdio.h>
#include<stdbool.h>
const int t[]={2,3,5,7};
int n,m=1,front,rear=3,a[10001]={2,3,5,7};
bool check(int x)
{
	if(x<2)return false;
	for(int i=2;i*i<=x;i++)if(x%i==0)return false;
	return true;
}
int main()
{
	scanf("%d",&n);
	if(n==1)return puts("2\n3\n5\n7"),0;
	while(n--)m*=10;
	while(front<=rear)
	{
		int x=a[front++]*10;
		for(int i=1;i<10;i+=2)
		{
			int y=x+i;
			if(y>=m||!check(y))continue;
			if(y>=m/10&&y<m)printf("%d\n",y);
			a[++rear]=y;
		}
	}
	return 0;
}