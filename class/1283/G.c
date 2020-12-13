/*
User: shenyouran
Problem: 2392
Algorithm: Floyd
Time Complexity: O(n^3 + n^2 + m)
Storage Complexity: O(n^2)
*/
#include<stdio.h>
#include<stdbool.h>
int n,m,ans;
bool f[101][101];
int main()
{
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        f[u][v]=true;
    }
    for(int k=1;k<=n;++k)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                f[i][j]|=f[i][k]&f[k][j];
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        bool flag=true;
        for(int j=1;j<=n;++j)
        {
            if(i==j)continue;
            if(!f[i][j]&&!f[j][i])
            {
                flag=false;
                break;
            }
        }
        ans+=flag;
    }
    printf("%d",ans);
    return 0;
}