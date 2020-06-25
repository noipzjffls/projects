#include<bits/stdc++.h>
using namespace std;
int s[5],a[5][21],X,Y,cur=1<<30,ans;
void dfs(int x,int y)
{
    if(y>s[x])
    {
        cur=min(cur,max(X,Y));
        return;
    }
    X+=a[x][y];
    dfs(x,y+1);
    X-=a[x][y];
    Y+=a[x][y];
    dfs(x,y+1);
    Y-=a[x][y];
}
int main()
{
    for(int i=1;i<5;i++)scanf("%d",&s[i]);
    for(int i=1;i<5;i++,cur=1<<30)
    {
        for(int j=1;j<=s[i];j++)scanf("%d",&a[i][j]);
        dfs(i,1);
        ans+=cur;
    }
    printf("%d",ans);
    return 0;
}