#include<bits/stdc++.h>
using namespace std;
map<string,int>stu;
int n,m,k,f[20001];
int find(int x)
{
    if(f[x]==x)return x;
    return f[x]=find(f[x]);
}
void merge(int a,int b)
{
    int fa=find(a),fb=find(b);
    if(fa!=fb)f[fa]=fb;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        f[i]=stu[s]=i;
    }
    while(m--)
    {
        string u,v;
        cin>>u>>v;
        int p1=stu[u],p2=stu[v];
        if(find(p1)!=find(p2))merge(p1,p2);
    }
    cin>>k;
    while(k--)
    {
        string u,v;
        cin>>u>>v;
        int p1=stu[u],p2=stu[v];
        if(find(p1)==find(p2))puts("Yes.");
        else puts("No.");
    }
    return 0;
}