#include<bits/stdc++.h>
#define C(n,m)n>0&&m>0&&n<9&&m<9
int n,i,a[64][2],X[]={-2,-2,-1,-1,1,1,2,2},Y[]={-1,1,-2,2,-2,2,-1,1};
bool b[9][9];
bool check(int x,int y,bool f)
{
    if(f)b[x][y]=0;
    for(int j=0;j<8;j++)
    {
        int n=x+X[j],m=y+Y[j];
        if(n<1||n>8||m<1||m>8)continue;
        if(b[n][m])
        {
            if(f)b[x][y]=1;
            return 0;
        }
    }
    return 1;
}
void dfs(int x,int y)
{
    if(y==8)
    {
        printf("7");
        exit(0);
    }
    if(C(x,y+1))if(!b[x][y+1]&&check(x,y+1,0))dfs(x,y+1);
    if(C(x+1,y+1))if(b[x+1][y+1]&&check(x+1,y+1,1))dfs(x+1,y+1);
    if(C(x-1,y+1))if(b[x-1][y+1]&&check(x-1,y+1,1))dfs(x-1,y+1);
}
int main()
{
    scanf("%d",&n);
    for(;i<n;i++)
    {
        char X;
        int x,y;
        scanf("\n%c%d",&X,&y);
        x=X-'A'+1;
        b[x][y]=1;
    }
    dfs(1,1);
    printf("-1");
}