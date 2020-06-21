#include<bits/stdc++.h>
using namespace std;
int n;
double p[10001][2],ans=1<<30;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lf%lf",&p[i][0],&p[i][1]);
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            double dis=sqrt((p[i][0]-p[j][0])*(p[i][0]-p[j][0])+(p[i][1]-p[j][1])*(p[i][1]-p[j][1]));
            if(dis<ans)ans=dis;
        }
    }
    printf("%.4lf",ans);
    return 0;
}