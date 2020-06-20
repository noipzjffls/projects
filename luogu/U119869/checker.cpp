#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
int N,lx,ly;
bool vis[21][21],maps[21][21];
string Ans,Out;
int transfer(string x)
{
    int s=0;
    for(int i=0;x[i];i++)s=(s<<3)+(s<<1)+(x[i]^48);
    return s;
}
bool outmap(int x,int y)
{
    return x<1||y<1||x>N||y>N;
}
bool check(int X,int Y,int xx,int yy)
{
    int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
    for(int i=0;i<4;i++)
    {
        int nx=X+dx[i],ny=Y+dy[i];
        if(nx==xx&&ny==yy)return true;
    }
    return false;
}
int main(int argc,char* argv[])
{
    registerTestlibCmd(argc,argv);
    Ans=ans.readString();
    Out=ouf.readString();
    if(Ans==Out)quitf(_ok, "The answer is correct.");
    N=inf.readInt();
    for(int i=1;i<=N;i++)
    {
        string s=inf.readToken();
        for(int j=1;j<=N;j++)
        {
            maps[i][j]=s[j-1]^48;
        }
    }
    bool flag=false,last=false; 
    for(int x,y,p;;)
    {
        p=Out.find("->");
        if(p!=string::npos)
        {
            string s=Out.substr(1,p-2);
            Out.erase(0,p+2);
            p=s.find(',');
            x=transfer(s.substr(0,p));
            y=transfer(s.substr(p+1));
        }
        else
        {
            p=Out.find(',');
            x=transfer(Out.substr(1,p-1));
            y=transfer(Out.substr(p+1,Out.size()-p-2));
            last=true;
        }
        if(outmap(x,y))quitf(_wa,"Illegal point! Error at point (%d,%d).",x,y);
        if(flag&&!check(x,y,lx,ly))quitf(_wa,"Illegal transmittion! Error at point (%d,%d).",x,y);
        if(!flag&&(x!=1||y!=1))quitf(_wa,"Wrong starting point! Error at point (%d,%d).",x,y);
        if(last&&(x!=N||y!=N))quitf(_wa,"Wrong ending point! Error at point (%d,%d).",x,y);
        if(vis[x][y])quitf(_wa,"This point has been visited! Error at point (%d,%d).",x,y);
        if(maps[x][y])quitf(_wa,"You could not enter this point! Error at point (%d,%d).",x,y);
        vis[x][y]=flag=true;
        lx=x;
        ly=y;
        if(last)break;
    }
    quitf(_ok, "The answer is correct.");
}