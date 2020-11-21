/*
User: shenyouran
Problem: 3013
Algorithm: Knapsack, Binary
Language: C/C++
Record ID: 73306
Submit Time: 2020-09-19 14:53:56
*/
#include<stdio.h>
int n,m,p[2001],v[2001],dp[6000],cnt;
int max(int x,int y){return x>y?x:y;}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,a,b,c;i<=n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		for(int k=1;k<c;c-=k,k<<=1)
		{
			cnt++;
			p[cnt]=a*k;
			v[cnt]=b*k;
		}
		if(c)
		{
			cnt++;
			p[cnt]=a*c;
			v[cnt]=b*c;
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		for(int j=m;j>=p[i];j--)
		{
			dp[j]=max(dp[j],dp[j-p[i]]+v[i]);
		}
	}
	printf("%d",dp[m]);
	return 0;
}