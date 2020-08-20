#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[18][4],tot[18],x;
bool f;
map<string,int>card={{"A", 14},{"2", 15},{"3", 3},{"4", 4},{"5", 5},{"6", 6},{"7", 7},{"8", 8},{"9", 9},{"10", 10},{"J", 11},{"Q", 12},{"K", 13},{"joker", 16},{"JOKER", 17}};
map<char,int>type={{'D', 0},{'C', 1},{'H', 2},{'S', 3}};
const char types[]={'D','C','H','S'},*cards[]={"","","","3","4","5","6","7","8","9","10","J","Q","K","A","2","joker","JOKER"};
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
    if(tot[16]==1&&tot[17]==1)
    {
        printf("ROCKET");
        return 0;
    }
    for(int i=15;i>2;i--)
    {
        if(tot[i]==4)
        {
            printf("BOMB\n%s %s %s %s",cards[i],cards[i],cards[i],cards[i]);
            return 0;
        }
    }
    for(int i=3;i;i--)
    {
        bool f=true;
        for(int j=10;j<15;j++)f&=cnt[j][i];
        if(f)
        {
            printf("ROYAL FLUSH\n%c",types[i]);
            return 0;
        }
    }
    for(int i=3;i;i--)
    {
        for(int j=3;j<11;j++)
        {
            bool f=true;
            for(int k=j;k<j+5;k++)f&=cnt[k][i];
            if(f)
            {
                printf("FLUSH\n%s %s %s %s %s\n%c",cards[j],cards[j+1],cards[j+2],cards[j+3],cards[j+4],types[i]);
                return 0;
            }
        }
    }
    for(int i=14;i>3;i--)
    {
        if(tot[i]>2&&tot[i-1]>2)
        {
            x=i;
            break;
        }
    }
    if(x)
    {
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
        if(c1&&c2)
        {
            printf("AIRPLANE\n%s",cards[x-1]);
            for(int i=0;i<2;i++)printf(",%s",cards[x-1]);
            printf(",%s;%s",cards[c2],cards[x]);
            for(int i=0;i<2;i++)printf(",%s",cards[x]);
            printf(",%s",cards[c1]);
        }
        else printf("TRIPLE STRAIGHT\n%s,%s,%s;%s,%s,%s",cards[x-1],cards[x-1],cards[x-1],cards[x],cards[x],cards[x]);
        return 0;
    }
    x=0;
    for(int i=14;i>4;i--)
    {
        if(tot[i]>1&&tot[i-1]>1&&tot[i-2]>1)
        {
            x=i;
            break;
        }
    }
    if(x)
    {
        printf("DOUBLE STRAIGHT\n%s,%s;%s,%s;%s,%s",cards[x-2],cards[x-2],cards[x-1],cards[x-1],cards[x],cards[x]);
        return 0;
    }
    x=0;
    for(int i=14;i>6;i--)
    {
        if(tot[i]&&tot[i-1]&&tot[i-2]&&tot[i-3]&&tot[i-4])
        {
            x=i;
            break;
        }
    }
    if(x)
    {
        printf("STRAIGHT\n%s,%s,%s,%s,%s",cards[x-4],cards[x-3],cards[x-2],cards[x-1],cards[x]);
        return 0;
    }
    x=0;
    for(int i=15;i>2;i--)
    {
        if(tot[i]>2)
        {
            x=i;
            break;
        }
    }
    if(x)
    {
        int a=0,b=0,c=0;
        for(int i=15;i>2;i--)
        {
            if(tot[i]>1&&i!=x)
            {
                a=i;
                break;
            }
        }
        for(int i=17;i>2;i--)
        {
            if(tot[i]&&i!=x)
            {
                b=i;
                break;
            }
        }
        if(a)printf("TRIPLE WITH PAIR\n%s,%s,%s;%s,%s",cards[x],cards[x],cards[x],cards[a],cards[a]);
        else if(b)printf("TRIPLE WITH SINGLE\n%s,%s,%s;%s",cards[x],cards[x],cards[x],cards[b]);
        else printf("TRIPLE\n%s,%s,%s",cards[x],cards[x],cards[x]);
        return 0;
    }
    x=0;
    for(int i=15;i>2;i--)
    {
        if(tot[i]>1)
        {
            x=i;
            break;
        }
    }
    if(x)printf("PAIR\n%s,%s",cards[x],cards[x]);
    else
    {
        for(int i=17;i>2;i--)
        {
            if(tot[i])
            {
                printf("SINGLE\n%s",cards[i]);
                break;
            }
        }
    }
    return 0;
}