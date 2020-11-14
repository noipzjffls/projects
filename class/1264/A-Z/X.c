/*
User: shenyouran
Problem: 2858
Algorithm: DFS
Language: C/C++
Record ID: 74617
Submit Time: 2020-10-18 10:19:24
*/
#include<stdio.h>
#include<stdbool.h>
int a[10];
bool b[10];
void dfs(int k)
{
    if(k>9)
    {
        int x=100*a[1]+10*a[2]+a[3],y=100*a[4]+10*a[5]+a[6],z=100*a[7]+10*a[8]+a[9];
        if(y==x<<1&&z==x*3)printf("%d %d %d\n",x,y,z);
        return;
    }
    for(int i=1;i<10;i++)
    {
        if(b[i])continue;
        a[k]=i;
        b[i]=true;
        dfs(k+1);
        b[i]=false;
    }
}
int main()
{
    dfs(1);
}