#include<bits/stdc++.h>
using namespace std;
map<string,bool>vis;
string s[21][2];
int n,front=1,rear=1;
struct node
{
    string cur;
    int step;
}q[2250001];
int main()
{
    while(cin>>s[n][0]>>s[n][1])n++;
    q[1].cur=s[0][0];
    vis[s[0][0]]=true;
    while(front<=rear)
    {
        node f=q[front++];
        for(int i=0;f.cur[i];i++)
        {
            for(int j=1;j<n;j++)
            {
                if(i+s[j][0].size()>f.cur.size())continue;
                string s1=f.cur.substr(i,s[j][0].size()),s2;
                if(s1!=s[j][0])continue;
                s2=f.cur;
                s2.replace(i,s[j][0].size(),s[j][1]);
                if(vis[s2])continue;
                vis[s2]=true;
                if(f.step<11)q[++rear]=(node){s2,f.step+1};
                if(s2==s[0][1])
                {
                    printf("%d",q[rear].step);
                    return 0;
                }
            }
        }
    }
    puts("NO ANSWER!");
    return 0;
}