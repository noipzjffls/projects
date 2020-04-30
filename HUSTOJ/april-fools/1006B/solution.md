# 定位
题目的本质——一元二次方程求解。懂得了一元二次方程，这道题就迎刃而解了。
# 一元二次方程
对于以下内容，会一元二次方程的大佬可以忽略（~~九年级内容~~）。

【一般形式】
```math
ax^2+bx+c=0(a\neq0)
```
【求解过程】
我们可以将两边同时除以a，然后用配方法进行求解。具体过程如下：
$$\frac{ax^2+bx+c}{a}=\frac{0}{a}$$

$$x^2+\frac{b}{a}x+\frac{c}{a}=0$$

$$x^2+\frac{b}{a}x+(\frac{b}{2a})^2-(\frac{b}{2a})^2+\frac{c}{a}=0$$

$$x^2+\frac{b}{a}x+\frac{b^2}{4a^2}=\frac{b^2}{4a^2}-\frac{c}{a}$$

$$(x+\frac{b}{2a})^2=\frac{b^2}{4a^2}-\frac{c·4a}{a·4a}$$

$$(x+\frac{b}{2a})^2=\frac{b^2-4ac}{4a^2}$$

$$x+\frac{b}{2a}=±\frac{\sqrt{b^2-4ac}}{2a}$$

$$x=±\frac{\sqrt{b^2-4ac}}{2a}-\frac{b}{2a}$$

$$x=±\frac{\sqrt{b^2-4ac}-b}{2a}$$

$$x=\frac{-b±\sqrt{b^2-4ac}}{2a}$$
其中我们令
```math
\Delta=b^2-4ac
```
当$△<0$时，方程有两个共轭复根。

当$△=0$时，方程有一个实数解，为：

$$x=-\frac{b}{2a}$$

当$△>0$时，方程有两个不相等的实数解，为：

$$x_1=\frac{-b+\sqrt{b^2-4ac}}{2a}$$

$$x_2=\frac{-b-\sqrt{b^2-4ac}}{2a}$$

对于上面的情况，我们进行分类讨论并正确设计程序即可。

# 提示
注意！虽然本题的解法与一元二次方程相似，但是题面中并没有给出任何与一元二次方程相关的字眼。而并没有强调$a≠0$，因此这很有可能转为一元一次方程（$a=0$时，转变为$bx+c=0$）。
在这种情况下：
$$bx+c=0$$

$$bx=-c$$

$$x=-\frac{c}{b}$$

这个时候只需要输出$-\frac{c}{b}$即可。

# 代码
代码实现起来较为简单：
```cpp
#include<bits/stdc++.h>
#define check(d)(bool)(d<1&&d>0?1:0)//检查一个数表示的概率是否为随机事件（即在(0,1)之间）
long long a,b,c;
double delta,x,y;
int main()
{
    scanf("%lld%lld%lld",&a,&b,&c);//输入
    if(!a)//特判一元一次方程
    {
        x=-1.0*c/b;//赋值
        if(check(x))printf("%.6f",x);
        else printf("Error");
    }
    else
    {
        delta=b*b-4*a*c;//判别式赋值
        if(delta<0)//△<0则有两个共轭复根
        {
            printf("Error");
            return 0;
        }
        if(!delta)//△=0则只有一种情况
        {
            x=-1.0*b/2/a;
            if(check(x))printf("%.6f",x);
            else printf("Error");
            return 0;
        }
        //否则有两个不相等的实数根
        x=(-b-sqrt(delta))/2/a;
        y=(sqrt(delta)-b)/2/a;
        if(x>y)std::swap(x,y);
        if(check(x))printf("%.6f ",x);
        if(check(y))printf("%.6f",y);
        if(!check(x)&&!check(y))printf("Error");
    }
}
```
# 总结
这道题可以说是一道纯数学题，不需要太多算法技巧。