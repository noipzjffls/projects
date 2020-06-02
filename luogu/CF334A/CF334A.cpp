#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
    scanf("%d",&n);
    m=n*n;
    for(int i=1;i<=m>>1;i++)printf("%d %d\n",i,m-i+1);
    return 0;
}