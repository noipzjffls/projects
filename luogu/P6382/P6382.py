c=str(input())# str（字符串）类型输入
i=7# 初始指针为7（原因：长度为8，而下标从0开始，因此初始为7）
while(c[i] < '0' or c[i] > '9'):# 如果当前指向字符不为数字，指针就左移，具体实现是i-=1
    i -= 1
if(c[0] != 'M' or c[1] != 'D' or c[2] != 'A'):# 特判开头为MDA的情况
    print('1 1 1 1 1')# 可以直接以字符串形式输出
else:
    print(int(c[i] == '1' or c[i] == '9'),end=' ')# 这里可以直接将bool值转换为int值输出，但是要注意空格问题——必须在尾部添加end=' '才能加空格，否则默认换行
    print(int(c[i] == '2' or c[i] == '8'),end=' ')
    print(int(c[i] == '3' or c[i] == '7'),end=' ')
    print(int(c[i] == '4' or c[i] == '6'),end=' ')
    print(int(c[i] == '5' or c[i] == '0'))# 最后可以不用空格