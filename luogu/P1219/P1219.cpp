#include<bits/stdc++.h>
using namespace std;
int a[101],b[101],c[101],d[101],tot,n;
void print()
{
    if(tot<=2)
    {
        for(int k=1;k<=n;k++)cout<<a[k]<<" ";
        cout<<endl;
    }
    tot++;
}
void dfs(int i)
{
    if(i>n)
    {
        print();
        return;
    }
    else
    {
        for(int j=1;j<=n;j++)
        {
            if((!b[j])&&(!c[i+j])&&(!d[i-j+n]))
            {
                a[i]=j;
                b[j]=c[i+j]=d[i-j+n]=1;
                dfs(i+1);
                b[j]=c[i+j]=d[i-j+n]=0;
            }
        }
    }
}
int main()
{
    cin>>n;
    dfs(1);
    cout<<tot;
    return 0;
}