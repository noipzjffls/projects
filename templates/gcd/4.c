int gcd(int a,int b)
{
    if(!a||!b)return a>b?a:b;
    int t;
    for(;t=a%b;a=b,b=t);
    return b;
}