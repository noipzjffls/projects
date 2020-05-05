#include<bits/stdc++.h>
using namespace std;
int n,a[101],sum,s;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i;i--)
    {
        s+=a[i];
        if(s>sum/2)
        {
            printf("%d",n-i+1);
            break;
        }
    }
    return 0;
}