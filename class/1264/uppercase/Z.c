/*
User: shenyouran
Problem: 3190
Algorithm: DFS
Language: C/C++
Record ID: 74850
Submit Time: 2020-10-24 13:47:46
*/
#include<stdio.h>
int n,r,a[21];
void dfs(int k)
{
    if(k>r)
    {
        for(int i=1;i<=r;i++)printf("%3d",a[i]);
        putchar('\n');
        return;
    }
    for(int i=a[k-1]+1;i<=n;i++)
    {
        a[k]=i;
        dfs(k+1);
    }
}
int main()
{
    scanf("%d%d",&n,&r);
    dfs(1);
    return 0;
}