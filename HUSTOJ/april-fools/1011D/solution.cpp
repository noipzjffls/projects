#include<iostream>
using namespace std;
int n;
string s[]={"","Today","is","April","Fools","Day!","Here","is","the","contest","of","the","festival!","Let's","play","an","interesting","game!","It","is","very","easy","for","you","to","AK","this","contest!","This","is","only","an","added","problem.","Good","luck!"};
int main()
{
    cin>>n;
    if(n<36)cout<<s[n];
    else cout<<"Happy April Fools!";
}