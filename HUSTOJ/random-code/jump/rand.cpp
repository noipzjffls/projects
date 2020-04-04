#include<bits/stdc++.h>
using namespace std;
int type[]={0,0,0,1,1,1,2,2,2,3,3},id,datanum,rangen[][2]={{1,10},{1,500},{1,5e5},{1,5e5}},ranged[][2]={{1,2e3},{1,2e3},{1,1},{1,2e3}};
int random(int a,int b)
{
    return (rand()%(b-a+1))+a;
}
struct node
{
    int x,y;
};
bool cmp(node a,node b)
{
    return a.x<b.x;
}
char filename[][10]={"","1.in","2.in","3.in","4.in","5.in","6.in","7.in","8.in","9.in","10.in"};
int main()
{
    srand(time(NULL));
    for(datanum=1;datanum<=10;datanum++)
    {
        freopen(filename[datanum],"w",stdout);
        int typenum=type[datanum],n=random(rangen[typenum][0],rangen[typenum][1]),d=random(ranged[typenum][0],rangen[typenum][1]),i=1,k=random(1,1e9);
        node a[500001];
        printf("%d %d %d",n,d,k);
        for(;i<=n;i++)
        {
            a[i].x=random(1,1e9);
            a[i].y=random(1-1e5,1e5-1);
        }
        sort(a+1,a+n+1,cmp);
        for(i=1;i<=n;i++)printf("\n%d %d",a[i].x,a[i].y);
    }
}