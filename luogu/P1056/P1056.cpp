#include<bits/stdc++.h>
using namespace std;
int m,n,k,l,d;
struct node
{
    int val,id;
}a[1001],b[1001];
bool cmp1(node x,node y)
{
    return x.val>y.val;
}
bool cmp2(node x,node y)
{
    return x.id<y.id;
}
int main()
{
    scanf("%d%d%d%d%d",&m,&n,&k,&l,&d);
    for(int i=1;i<=m;i++)a[i].id=i;
    for(int i=1;i<=n;i++)b[i].id=i;
    for(int i=0,x,y,p,q;i<d;i++)
    {
        scanf("%d%d%d%d",&x,&y,&p,&q);
        if(x>p)swap(x,p);
        if(y>q)swap(y,q);
        if(x==p)b[y].val++;
        else a[x].val++;
    }
    sort(a+1,a+m+1,cmp1);
    sort(b+1,b+n+1,cmp1);
    sort(a+1,a+k+1,cmp2);
    sort(b+1,b+l+1,cmp2);
    for(int i=1;i<=k;i++)printf("%d ",a[i].id);
    putchar('\n');
    for(int i=1;i<=l;i++)printf("%d ",b[i].id);
    return 0;
}