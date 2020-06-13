#include<bits/stdc++.h>
using namespace std;
int n,m,range;
int main()
{
    srand(time(NULL));
    while(cin>>range)
    {
        n=rand()%range+1;
        m=rand()%range+1;
        cout<<n<<" "<<m<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(rand()%2)cout<<". ";
                else cout<<"# ";
            }
            cout<<endl;
        }
    }
    return 0;
}