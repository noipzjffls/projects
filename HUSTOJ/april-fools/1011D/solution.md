# 定位
一道附加题，考察英语的基本常识，也涵盖了部分信息学术语。算法实现难度容易。
# 算法
将所有的单词排列成正确顺序（~~打个小表即可~~），然后判断$n$与单词总数大小关系。每一个$n$都是一个测试点，所以一个是`2`分，总共`100`分。
# 代码
```cpp
#include<iostream>
using namespace std;
int n;
string s[]={"","Today","is","April","Fools","Day!","Here","is","the","contest","of","the","festival!","Let's","play","an","interesting","game!","It","is","very","easy","for","you","to","AK","this","contest!","This","is","only","an","added","problem.","Good","luck!"};//将所有的单词保存，注意第一个是下标0，要置空
int main()
{
    cin>>n;//输入
    if(n<36)cout<<s[n];//判断小于36则输出单词
    else cout<<"Happy April Fools!";//否则输出一段文字
}
```