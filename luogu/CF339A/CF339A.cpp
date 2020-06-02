#include<bits/stdc++.h>
using namespace std;
priority_queue<long long,vector<long long>,greater<long long>>pq;
long long x;
char ch;
int main()
{
    while(scanf("%lld",&x)!=EOF)
    {
        ch=getchar();
        pq.push(x);
        if(ch=='\n')break;
    }
    printf("%lld",pq.top());
    pq.pop();
    while(pq.size())
    {
        printf("+%lld",pq.top());
        pq.pop();
    }
    return 0;
}