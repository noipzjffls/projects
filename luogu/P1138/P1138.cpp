#include<bits/stdc++.h>
using namespace std;
int n,k,l;
struct node
{
    int num;
    bool flag;
}a[30000];
bool cmp(node a,node b)
{
    if(a.flag!=b.flag)return a.flag>b.flag;
    return a.num<b.num;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1,x;i<=n;i++)
    {
        scanf("%d",&x);
        if(a[x].flag)continue;
        a[x]=(node){x,true};
        l++;
    }
    sort(a+1,a+30000,cmp);
    if(k<=l)printf("%d",a[k].num);
    else puts("NO RESULT");
    return 0;
}