#include<bits/stdc++.h>
using namespace std;
int range,n,pos[4],price[4],lim=1e3;
bool f;
int main()
{
    char text[10];
    scanf("%s",text);
    freopen(strcat(text,".in"),"w",stdout);
    srand(time(NULL));
    cin>>range;
    if(range==1)n=1;
    else n=rand()%range+1;
    cout<<n<<endl;
    if(n==1)
    {
        printf("1 1\n1 1\n");
        for(int i=0;i<4;i++)
        {
            price[i]=rand()%lim;
            bool f=rand()%2;
            if(f)price[i]=-price[i];
        }
        for(int i=0;i<4;i++)cout<<price[i]<<" ";
        return 0;
    }
    while(pos[0]==pos[2]&&pos[1]==pos[3])for(int i=0;i<4;i++)pos[i]=rand()%n+1;
    for(int i=0;i<4;i++)
    {
        price[i]=rand()%lim;
        bool f=rand()%2;
        if(f)price[i]=-price[i];
    }
    for(int i=0;i<4;i++)cout<<pos[i]<<" ";
    cout<<endl;
    for(int i=0;i<4;i++)cout<<price[i]<<" ";
    return 0;
}