#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val,idx;
}w[200010];
bool cmp(node x,node y)
{
    return x.val<y.val;
}
char a[400010];
stack<node>s;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&w[i].val),w[i].idx=i;
    sort(w+1,w+n+1,cmp);
    node l;
    scanf("%s",a);
    for(int i=0,j=1;i<n<<1;i++)
    {
        if(getchar()^'0')
        {
            l=s.top();
            printf("%d ",l.idx);
            s.pop();
        }
        else
        {
            s.push(w[j++]);
            printf("%d ",w[j-1].idx);
        }
    }
    return 0;
}