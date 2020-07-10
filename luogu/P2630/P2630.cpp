#include<bits/stdc++.h>
using namespace std;
struct maps
{
    int a[4][4];
}first,goal;
struct node
{
    maps m;
    int step;
    string seq;
};
queue<node>q;
queue<maps>visited;
maps change(maps x,char opt)
{
    maps y;
    switch(opt)
    {
        case 'A':
        {
            for(int i=1;i<4;i++)
            {
                for(int j=1;j<4;j++)
                {
                    y.a[i][j]=x.a[4-j][i];
                }
            }
            break;
        }
        case 'B':
        {
            for(int i=1;i<4;i++)
            {
                for(int j=1;j<4;j++)
                {
                    y.a[i][j]=x.a[j][4-i];
                }
            }
            break;
        }
        case 'C':
        {
            for(int i=1;i<4;i++)
            {
                for(int j=1;j<4;j++)
                {
                    y.a[i][j]=x.a[i][4-j];
                }
            }
            break;
        }
        case 'D':
        {
            for(int i=1;i<4;i++)
            {
                for(int j=1;j<4;j++)
                {
                    y.a[i][j]=x.a[4-i][j];
                }
            }
            break;
        }
    }
    return y;
}
bool check(maps x,maps y)
{
    for(int i=1;i<4;i++)
    {
        for(int j=1;j<4;j++)
        {
            if(x.a[i][j]!=y.a[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
int transfer(maps x)
{
    int s=0;
    for(int i=1;i<4;i++)
    {
        for(int j=1;j<4;j++)
        {
            s=(s<<3)+(s<<1)+x.a[i][j];
        }
    }
    return s;
}
bool rep(maps x)
{
    while(visited.size())
    {
        if(check(visited.back(),x))return true;
        visited.pop();
    }
    return false;
}
int main()
{
    for(int i=1;i<4;i++)
    {
        for(int j=1;j<4;j++)
        {
            scanf("%d",&first.a[i][j]);
        }
    }
    for(int i=1;i<4;i++)
    {
        for(int j=1;j<4;j++)
        {
            scanf("%d",&goal.a[i][j]);
        }
    }
    q.push((node){first,0,""});
    visited.push(first);
    while(q.size())
    {
        node f=q.front();
        q.pop();
        for(char c='A';c<='D';c++)
        {
            node cur=(node){change(f.m,c),f.step+1,f.seq+c};
            if(rep(cur.m))continue;
            if(cur.step<5)q.push(cur);
            if(check(cur.m,goal))
            {
                cout<<cur.seq;
                return 0;
            }
        }
    }
    puts("Poland cannot into space!!!");
    return 0;
}