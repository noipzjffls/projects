#include<bits/stdc++.h>
using namespace std;
int n,maxn;
struct node
{
    string name,text;
    int cnt;
}person[101];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>person[i].name>>person[i].text;
        for(int j=0;j<int(person[i].text.size()-2);j++)
        {
            if(person[i].text[j]!='s'||person[i].text[j+1]!='o'||person[i].text[j+2]!='s')continue;
            person[i].cnt++;
        }
        maxn=max(maxn,person[i].cnt);
    }
    for(int i=1;i<=n;i++)if(person[i].cnt==maxn)cout<<person[i].name<<" ";
    cout<<endl<<maxn; 
    return 0;
}
