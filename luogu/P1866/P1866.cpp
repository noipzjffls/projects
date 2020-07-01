#include<bits/stdc++.h>
using namespace std;
int n,a[51];
long long s=1;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        s*=a[i]-i+1;
        s%=1000000007;
    }
    printf("%lld",s);
    return 0;
}