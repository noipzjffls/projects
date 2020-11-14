#include<bits/stdc++.h>
int main()
{
    int tests;
    scanf("%d",&tests);
    for(int i=1;i<=tests;i++)
    {
        printf("\nTest Data #%d\n",i);
        clock_t a=clock();
        system("./data");
        printf("Data generated in %f seconds.\n",1.0*(clock()-a)/CLOCKS_PER_SEC);
        a=clock();
        system("./std");
        printf("Std executed in %f seconds.\n",1.0*(clock()-a)/CLOCKS_PER_SEC);
        a=clock();
        system("./baoli");
        freopen("baoli.out","r",stdin);
        double t=1.0*(clock()-a)/CLOCKS_PER_SEC,tt=1;
        if(t>tt)
        {
            printf("Time Limit Exceeded. You spent %f seconds. Expected %g seconds.",t,tt);
            return 0;
        }
        if(system("diff std.out baoli.out"))
        {
            puts("Wrong Answer.");
            return 0;
        }
        printf("Accepted. Executed in %f seconds.\n",t);
    }
    return 0;
}