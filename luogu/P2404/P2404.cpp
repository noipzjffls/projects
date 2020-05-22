#include<cstdio>
int a[105],n;
void print(int t)
{
    for(int i=1;i<=t;i++)
    {
        if(i!=1)printf("+");
        printf("%d",a[i]);
    }
    putchar('\n');
}
void dfs(int s,int t)
{
    for(int i=1;i<=s;i++)
    {
        if(i>=a[t-1]&&i<n)
        {
            a[t]=i;
            if(s==i)print(t);
            else dfs(s-i,t+1);
        }
    }
}
int main()
{
    scanf("%d",&n);
    dfs(n,1);
    return 0;
}