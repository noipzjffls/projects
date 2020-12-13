/*
User: shenyouran
Problem: 1019
Algorithm: Floyd
Time Complexity: O(s^3 + s^2 + s)
Storage Complexity: O(s^2 + s)
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
int n,s,t,A,B,T,city[101][5][2];
double dis[401][401],ans=1e10;
int getid(int a,int b){return b+((a-1)<<2);}
double min(double a,double b){return a<b?a:b;}
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
int main()
{
    scanf("%d%d%d%d",&s,&t,&A,&B);
    for(int i=1;i<=s<<2;i++)dis[i][i]=0;
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
                dis[u][v]=dis[v][u]=w;
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
                    dis[u][v]=dis[v][u]=w;
                }
            }
        }
    }
    for(int k=1;k<=s<<2;k++)
    {
        for(int i=1;i<=s<<2;i++)
        {
            for(int j=1;j<=s<<2;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            ans=min(ans,dis[getid(A,i)][getid(B,j)]);
        }
    }
    printf("%.1lf\n",ans);
    return 0;
}