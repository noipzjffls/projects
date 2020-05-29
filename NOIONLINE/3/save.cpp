#include<bits/stdc++.h>
using namespace std;
int n;
struct node
{
    string name,text;
    int ans;
}a[101];
bool cmp(node a,node b)
{
    return a.ans>b.ans;
}
int main()
{
    freopen("save.in","r",stdin);
    freopen("save.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].name>>a[i].text;
        int len=int(a[i].text.size());
        for(int j=0;j<len-2;j++)
        {
            if(a[i].text[j]!='s'||a[i].text[j+1]!='o'||a[i].text[j+2]!='s')continue;
            a[i].ans++;
        }
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)if(a[i].ans==a[1].ans)cout<<a[i].name<<" ";
    cout<<endl<<a[1].ans;
    return 0;
}