#include<bits/stdc++.h>
using namespace std;
int n,t,ans;
int main()
{
    scanf("%d",&n);
    while(--n)
    {
        scanf("%d%d%d",&t,&t,&t);
        ans+=t;
    }
    printf("%d",ans&1);
    return 0;
}