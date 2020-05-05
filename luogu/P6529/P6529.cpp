#include<bits/stdc++.h>
using namespace std;
string temp;
map<char,int>type;
bool card[4][15];
int id;
int main()
{
    type['P']=0;
    type['K']=1;
    type['H']=2;
    type['T']=3;
    while(1)
    {
        char ch=getchar();
        if(ch=='\n')break;
        id++;
        temp+=ch;
        if(id==3)
        {
            int x=type[temp[0]],y=((temp[1]^'0')<<3)+((temp[1]^'0')<<1)+(temp[2]^'0');
            if(card[x][y])
            {
                cout<<"GRESKA";
                return 0;
            }
            card[x][y]=true;
            temp="";
            id=0;
        }
    }
    for(int i=0;i<4;i++)
    {
        int cnt=0;
        for(int j=1;j<=13;j++)cnt+=card[i][j];
        cout<<13-cnt<<" ";
    }
}