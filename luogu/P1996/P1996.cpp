#include<bits/stdc++.h>
using namespace std;
deque<int>q;
int n,m;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)q.push_back(i);
    while(q.size())
    {
        for(int i=0;i<m-1;i++)
        {
            q.push_back(q.front());
            q.pop_front();
        }
        cout<<q.front()<<" ";
        q.pop_front();
    }
    return 0;
}