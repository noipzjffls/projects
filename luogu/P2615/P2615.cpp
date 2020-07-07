#include<bits/stdc++.h>
using namespace std;
int n,a[40][40],lx,ly;
int main()
{
    scanf("%d",&n);
    lx=1;
    ly=(n+1)>>1;
    a[1][(n+1)>>1]=1;
    for(int k=2;k<=n*n;k++)
    {
        if(lx==1&&ly!=n)
        {
            a[n][++ly]=k;
            lx=n;
        }
        else if(ly==n&&lx!=1)
        {
            a[--lx][1]=k;
            ly=1;
        }
        else if(lx==1&&ly==n)a[++lx][ly]=k;
        else
        {
            if(!a[lx-1][ly+1])a[--lx][++ly]=k;
            else a[++lx][ly]=k;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)printf("%d ",a[i][j]);
        putchar('\n');
    }
    return 0;
}