#include<bits/stdc++.h>
using namespace std;
string program_name;
int num;
double score;
string to_str(int x)
{
    string s="";
    while(x)
    {
        s+=x%10+'0';
        x/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}
int main()
{
    cin>>program_name>>num;
    for(int i=1;i<=num;++i)
    {
        string idx=to_str(i),file_str="./"+program_name+"<"+program_name+idx+".in>"+program_name+idx+".out",diff_str="diff "+program_name+idx+".out "+program_name+idx+".ans";
        clock_t st=clock();
        printf("Test Data #%d\n",i);
        system(file_str.c_str());
        double t=1.0*(clock()-st)/CLOCKS_PER_SEC;
        if(t>1)puts("Time Limit Exceeded.");
        else if(!system(diff_str.c_str()))
        {
            printf("Accepted. Executed in %f ms.\n",t*1000);
            score+=100.0/num;
        }
        else puts("Wrong Answer.");
    }
    printf("Result for program ");
    cout<<"\""+program_name+"\":\n";
    if(score==100)puts("Accepted.");
    else puts("Wrong Answer.");
    printf("Score: %.1lf\n",score);
    return 0;
}