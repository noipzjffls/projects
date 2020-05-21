#include<bits/stdc++.h>
using namespace std;
int n,m,p,f[5001];
int find(int x)
{
    return f[x]==x?x:(f[x]=find(f[x]));
}
void merge(int a,int b)
{
    int fa=find(a),fb=find(b);
    if(fa!=fb)f[fa]=fb;
}
int main()
{
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<=n;i++)f[i]=i;
    while(m--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        merge(u,v);
    }
    while(p--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(find(u)==find(v))puts("Yes");
        else puts("No");
    }
    return 0;
}