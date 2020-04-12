#include<cstdio>
int n,x,y;
int main()
{
    scanf("%d%d%d",&n,&x,&y);
    puts((x==(n>>1)||x==(n>>1)+1)&&((y==(n>>1))||(y==(n>>1)+1))?"NO":"YES");
}