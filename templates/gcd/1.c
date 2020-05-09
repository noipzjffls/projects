int gcd(int a,int b)
{
    if(!a)return b;
    if(!b)return a;
    if(!(a&1)&&!(b&1))return gcd(a>>1,b>>1)<<1;
    if(!(b&1))return gcd(a,b>>1);
    if(!(a&1))return gcd(a>>1,b);
    return gcd(abs(a-b),min(a,b));
}