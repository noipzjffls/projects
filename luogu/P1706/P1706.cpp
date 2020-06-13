#include<bits/stdc++.h>
using namespace std;
int n,a[10];
bool flag[10];
void dfs(int k)
{
    if(k>n)
    {
        for(int i=1;i<=n;i++)printf("%5d",a[i]);
        putchar('\n');
    }
    for(int i=1;i<=n;i++)
    {
        if(!flag[i])
        {
            a[k]=i;
            flag[i]=true;
            dfs(k+1);
            flag[i]=false;
        }
    }
}
int main()
{
    scanf("%d",&n);
    dfs(1);
    return 0;
}