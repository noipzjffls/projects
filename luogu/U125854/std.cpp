#include<bits/stdc++.h>
using namespace std;
string s,a[55],b[55];
int la,lb,l1,l2;
map<string,int>card={{"A", 14},{"2", 15},{"3", 3},{"4", 4},{"5", 5},{"6", 6},{"7", 7},{"8", 8},{"9", 9},{"10", 10},{"J", 11},{"Q", 12},{"K", 13},{"joker", 16},{"JOKER", 17}};
struct card_set
{
    string a,b;
    bool operator < (const card_set &x)
    {
        if(a!=x.a)return card[a]<card[x.a];
        return card[b]<card[x.b];
    }
}c1[1486],c2[1486];
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
    while(read(a[++la]));
    while(read(b[++lb]));
    printf("%d %d\n",la,lb);
    for(int i=1;i<=la;i++)
    {
        for(int j=i,x,y;j<=lb;j++)
        {
            if(a[i]==b[j])continue;
            card_set t=(card_set){a[i],b[j]};
            if(card[a[i]]>card[b[j]])c1[++l1]=t;
            else c2[++l2]=t;
        }
    }
    if(l1&&l2)
    {
        puts("Tie\n");
        sort(c1+1,c1+l1+1);
        card_set t=(card_set){"",""};
        for(int i=1;i<=l1;i++)
        {
            if(c1[i].a!=t.a||c1[i].b!=t.b)
            {
                cout<<c1[i].a<<" "<<c1[i].b<<endl;
                t=c1[i];
            }
        }
        putchar('\n');
        sort(c2+1,c2+l2+1);
        t=(card_set){"",""};
        for(int i=1;i<=l2;i++)
        {
            if(c2[i].a!=t.a||c2[i].b!=t.b)
            {
                cout<<c2[i].a<<" "<<c2[i].b<<endl;
                t=c2[i];
            }
        }
    }
    else if(l1&&!l2)puts("A");
    else if(l2&&!l1)puts("B");
    else puts("AB");
    return 0;
}