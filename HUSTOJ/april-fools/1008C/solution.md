# 定位
判断语句即可解决本题，因此我们在测试点上下了功夫，确保使用`unsigned long long`可以过。这次没有高精度。
# 算法
先判断要不要输出`0`或`-1`，再输出结果。
# 代码
```cpp
#include<cstdio>
unsigned long long n,p,m,q;//要开unsigned long long
int main()
{
    scanf("%llu%llu%llu%llu",&n,&p,&m,&q);//输入
    if(m*p-q||m>n)//特判0
    {
        printf("0");
        return 0;
    }
    if(m==n)//特判1
    {
        printf("-1");
        return 0;
    }
    printf("%llu",n-m);//输出正解
}
```