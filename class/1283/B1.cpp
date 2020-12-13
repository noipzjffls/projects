/*
User: shenyouran
Problem: 1019
Algorithm: Dijkstra
Time Complexity: O(s^2 + s log s + s)
Storage Complexity: O(s^2 + s)
*/
#include<bits/stdc++.h>
using namespace std;
int s,t,A,B,T,cnt,city[101][5][2],head[401];
double dis[401],ans;
const double inf=1e10;
bool vis[401];
struct edge
{
    int nxt,to;
    double w;
}e[319201];
struct node
{
    int pos;
    double dis;
    bool operator<(const node &x)const
    {
        return dis>x.dis;
    }
};
int getid(int a,int b){return b+((a-1)<<2);}
double dist(double a,double b,double c,double d){return sqrt((c-a)*(c-a)+(d-b)*(d-b));}
void getpoint(int a)
{
    int x[5],y[5];
    for(int i=1;i<=4;i++)
    {
        x[i]=city[a][i][0];
        y[i]=city[a][i][1];
    }
    if((x[2]-x[1])*(x[1]-x[3])==(y[2]-y[1])*(y[3]-y[1]))
    {
        x[4]=x[3]+x[2]-x[1];
        y[4]=y[3]+y[2]-y[1];
    }
    else if((y[2]-y[1])*(y[3]-y[2])==(x[2]-x[1])*(x[2]-x[3]))
    {
        x[4]=x[3]+x[1]-x[2];
        y[4]=y[3]+y[1]-y[2];
    }
    else if((y[3]-y[1])*(y[3]-y[2])==(x[1]-x[3])*(x[3]-x[2]))
    {
        x[4]=x[2]+x[1]-x[3];
        y[4]=y[2]+y[1]-y[3];
    }
    for(int i=1;i<=4;i++)
    {
        city[a][i][0]=x[i];
        city[a][i][1]=y[i];
    }
}
void add(int u,int v,double w)
{
    e[++cnt].nxt=head[u];
    e[cnt].to=v;
    e[cnt].w=w;
    head[u]=cnt;
}
void dijkstra(int s)
{
    memset(dis,0x5f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    dis[s]=0;
    priority_queue<node>Q;
    Q.push((node){s,0});
    while(Q.size())
    {
        int x=Q.top().pos;
        Q.pop();
        if(vis[x])continue;
        vis[x]=true;
        for(int i=head[x];i;i=e[i].nxt)
        {
            int y=e[i].to;
            if(dis[y]>dis[x]+e[i].w)
            {
                dis[y]=dis[x]+e[i].w;
                if(!vis[y])Q.push((node){y,dis[y]}); 
            }
        }
    }
}
int main()
{
    scanf("%d%d%d%d",&s,&t,&A,&B);
    for(int i=1;i<=s;i++)
    {
        for(int j=1;j<=3;j++)scanf("%d%d",&city[i][j][0],&city[i][j][1]);
        getpoint(i);
        scanf("%d",&T);
        for(int j=1;j<4;j++)
        {
            for(int k=j+1;k<=4;k++)
            {
                double w=T*dist(city[i][k][0],city[i][k][1],city[i][j][0],city[i][j][1]);
                int u=getid(i,j),v=getid(i,k);
                add(u,v,w);
                add(v,u,w);
            }
        }
    }
    for(int i=1;i<s;i++)
    {
        for(int j=i+1;j<=s;j++)
        {
            for(int k=1;k<=4;k++)
            {
                for(int l=1;l<=4;l++)
                {
                    double w=t*dist(city[i][k][0],city[i][k][1],city[j][l][0],city[j][l][1]);
                    int u=getid(i,k),v=getid(j,l);
                    add(u,v,w);
                    add(v,u,w);
                }
            }
        }
    }
    ans=inf;
    for(int i=1;i<=4;i++)
    {
        dijkstra(getid(A,i));
        for(int j=1;j<=4;j++)ans=min(ans,dis[getid(B,j)]);
    }
    printf("%.1lf",ans);
    return 0;
}