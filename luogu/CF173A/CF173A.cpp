#include<cstdio>
int n,cycle,la,lb,pa,pb,sa,sb,win;
char a[1001],b[1001];
int gcd(int x,int y)
{
    return y?gcd(y,x%y):x;
}
int len(char s[])
{
    int i=0;
    for(;s[i];i++);
    return i;
}
int check(char a,char b)
{
    if(a==b)return 0;
    switch(a)
    {
        case 'R':
        {
            if(b=='P')return -1;
            return 1;
        }
        case 'P':
        {
            if(b=='R')return 1;
            return -1;
        }
        case 'S':
        {
            if(b=='R')return -1;
            return 1;
        }
    }
}
void simulate(int bound,int &A,int &B)
{
    while(bound--)
    {
        int win=check(a[A++],b[B++]);
        sa+=win==-1?1:0;
        sb+=win==1?1:0;
        if(A==la)A=0;
        if(B==lb)B=0;
    }
}
int main()
{
    scanf("%d\n%s\n%s",&n,a,b);
    la=len(a);
    lb=len(b);
    cycle=la*lb/gcd(la,lb);
    simulate(cycle,pa,pb);
    sa*=n/cycle;
    sb*=n/cycle;
    simulate(n%cycle,pa,pb);
    printf("%d %d",sa,sb);
}