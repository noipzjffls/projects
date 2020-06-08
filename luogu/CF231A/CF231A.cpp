#include<bits/stdc++.h>
using namespace std;
int n,ans;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		ans+=a+b+c>1;
	}
	printf("%d",ans);
	return 0;
}
