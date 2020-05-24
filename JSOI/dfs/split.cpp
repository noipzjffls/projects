#include<bits/stdc++.h>
using namespace std;
int a[15]={15},n;
void print(int t)
{
    for(int i=1;i<t;i++)printf("%3d",a[i]);
    printf("%3d\n",a[t]);
}
void dfs(int s,int t)
{
    for(int i=s;i;i--)
    {
        if(i<=a[t-1])
        {
            a[t]=i;
            s-=i;
            if(!s)print(t);
            else dfs(s,t+1);
            s+=i;
        }
    }
}
int main()
{
    scanf("%d",&n);
    dfs(n,1);
}