#include<bits/stdc++.h>
using namespace std;
int n,dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
string s[100],t[100],text="yizhong";
void dfs(int x,int y,int dir,int p)
{
    if(p==6)
    {
        int nx=x,ny=y;
        for(int i=6;i>=0;i--)
        {
            t[nx][ny]=text[i];
            nx-=dx[dir];
            ny-=dy[dir];
        }
        return;
    }
    int nx=x+dx[dir],ny=y+dy[dir];
    if(nx<0||ny<0||nx>=n||ny>=n||s[nx][ny]!=text[p+1])return;
    dfs(nx,ny,dir,p+1);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        int m=n;
        while(m--)t[i]+='*';
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(s[i][j]!='y')continue;
            for(int k=0;k<8;k++)dfs(i,j,k,0);
        }
    }
    for(int i=0;i<n;i++)cout<<t[i]<<endl;
    return 0;
}