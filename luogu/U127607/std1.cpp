#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p1;
typedef pair<p1,p1> p2;
const p1 error={0,0};
const p2 ERROR={error,error};
string s;
int cnt[18][4],tot[18],x;
p1 y;
p2 z;
bool f;
map<string,int>card={{"A", 14},{"2", 15},{"3", 3},{"4", 4},{"5", 5},{"6", 6},{"7", 7},{"8", 8},{"9", 9},{"10", 10},{"J", 11},{"Q", 12},{"K", 13},{"joker", 16},{"JOKER", 17}};
map<char,int>type={{'D', 0},{'C', 1},{'H', 2},{'S', 3}};
const char types[]={'D','C','H','S'},*cards[]={"","","","3","4","5","6","7","8","9","10","J","Q","K","A","2","joker","JOKER"};
int single()
{
    for(int i=17;i>2;i--)
    {
        if(tot[i])
        {
            return i;
        }
    }
    return 0;
}
int _pair_()
{
    for(int i=15;i>2;i--)
    {
        if(tot[i]>1)
        {
            return i;
        }
    }
    return 0;
}
int triple()
{
    for(int i=15;i>2;i--)
    {
        if(tot[i]>2)
        {
            return i;
        }
    }
    return 0;
}
p1 triple_with_single()
{
    int x=triple();
    if(!x)return error;
    for(int i=17;i>2;i--)
    {
        if(tot[i]&&i!=x)
        {
            return {x,i};
        }
    }
    return error;
}
p1 triple_with_pair()
{
    int x=triple();
    if(!x)return error;
    for(int i=15;i>2;i--)
    {
        if(tot[i]>1&&i!=x)
        {
            return {x,i};
        }
    }
    return error;
}
int straight()
{
    for(int i=14;i>6;i--)
    {
        if(tot[i]&&tot[i-1]&&tot[i-2]&&tot[i-3]&&tot[i-4])
        {
            return i;
        }
    }
    return 0;
}
int double_straight()
{
    for(int i=14;i>4;i--)
    {
        if(tot[i]>1&&tot[i-1]>1&&tot[i-2]>1)
        {
            return i;
        }
    }
    return 0;
}
int triple_straight()
{
    for(int i=14;i>3;i--)
    {
        if(tot[i]>2&&tot[i-1]>2)
        {
            return i;
        }
    }
    return 0;
}
p2 airplane()
{
    int x=triple_straight();
    if(!x)return ERROR;
    int c1=0,c2=0;
    for(int i=17;i>2;i--)
    {
        if(tot[i]&&i!=x&&i!=x-1)
        {
            if(c1)
            {
                c2=i;
                break;
            }
            c1=i;
        }
    }
    if(!c1||!c2)return ERROR;
    return {{x-1,x},{c2,c1}};
}
p1 flush()
{
    for(int i=3;i;i--)
    {
        for(int j=3;j<11;j++)
        {
            bool f=true;
            for(int k=j;k<j+5;k++)f&=cnt[k][i];
            if(f)return {j,i};
        }
    }
    return error;
}
int royal_flush()
{
    for(int i=3;i;i--)
    {
        bool f=true;
        for(int j=10;j<15;j++)f&=cnt[j][i];
        if(f)return i;
    }
    return -1;
}
int bomb()
{
    for(int i=15;i>2;i--)
    {
        if(tot[i]==4)
        {
            return i;
        }
    }
    return 0;
}
bool rocket()
{
    return tot[16]==1&&tot[17]==1;
}
bool read(string &s)
{
    s="";
    char ch;
    while(true)
    {
        ch=getchar();
        if(ch==' ')return true;
        else if(ch=='\n')return false;
        else s+=ch;
    }
}
int main()
{
    do
    {
        f=read(s);
        if(s[0]=='j')tot[16]++;
        else if(s[0]=='J')tot[17]++;
        else cnt[card[s.substr(1)]][type[s[0]]]++;
    }while(f);
    for(int i=3;i<18;i++)
    {
        for(int j=0;j<4;j++)
        {
            tot[i]+=cnt[i][j];
        }
    }
    if(rocket())
    {
        printf("ROCKET");
        return 0;
    }
    x=bomb();
    if(x)
    {
        printf("BOMB\n%s %s %s %s",cards[x],cards[x],cards[x],cards[x]);
        return 0;
    }
    x=royal_flush();
    if(x!=-1)
    {
        puts("ROYAL FLUSH");
        putchar(types[x]);
        return 0;
    }
    y=flush();
    if(y!=error)
    {
        x=y.first;
        printf("FLUSH\n%s %s %s %s %s\n%c",cards[x],cards[x+1],cards[x+2],cards[x+3],cards[x+4],types[y.second]);
        return 0;
    }
    z=airplane();
    if(z!=ERROR)
    {
        printf("AIRPLANE\n%s",cards[z.first.first]);
        for(int i=0;i<2;i++)printf(",%s",cards[z.first.first]);
        printf(",%s;%s",cards[z.second.first],cards[z.first.second]);
        for(int i=0;i<2;i++)printf(",%s",cards[z.first.second]);
        printf(",%s",cards[z.second.second]);
        return 0;
    }
    x=triple_straight();
    if(x)
    {
        printf("TRIPLE STRAIGHT\n%s,%s,%s;%s,%s,%s",cards[x-1],cards[x-1],cards[x-1],cards[x],cards[x],cards[x]);
        return 0;
    }
    x=double_straight();
    if(x)
    {
        printf("DOUBLE STRAIGHT\n%s,%s;%s,%s;%s,%s",cards[x-2],cards[x-2],cards[x-1],cards[x-1],cards[x],cards[x]);
        return 0;
    }
    x=straight();
    if(x)
    {
        printf("STRAIGHT\n%s,%s,%s,%s,%s",cards[x-4],cards[x-3],cards[x-2],cards[x-1],cards[x]);
        return 0;
    }
    y=triple_with_pair();
    if(y.first&&y.second)
    {
        printf("TRIPLE WITH PAIR\n%s,%s,%s;%s,%s",cards[y.first],cards[y.first],cards[y.first],cards[y.second],cards[y.second]);
        return 0;
    }
    y=triple_with_single();
    if(y.first&&y.second)
    {
        printf("TRIPLE WITH SINGLE\n%s,%s,%s;%s",cards[y.first],cards[y.first],cards[y.first],cards[y.second]);
        return 0;
    }
    x=triple();
    if(x)
    {
        printf("TRIPLE\n%s,%s,%s",cards[x],cards[x],cards[x]);
        return 0;
    }
    x=_pair_();
    if(x)
    {
        printf("PAIR\n%s,%s",cards[x],cards[x]);
        return 0;
    }
    printf("SINGLE\n%s",cards[single()]);
    return 0;
}