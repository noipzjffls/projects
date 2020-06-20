#include<bits/stdc++.h>
using namespace std;
int n,maxn=-1<<30,temp;
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        int m;
        scanf("%d",&m);
        temp=max(temp,0);
        temp+=m;
        maxn=max(maxn,temp);
    }
    cout<<maxn;
    return 0;
}