import math
n,x,y = map(int,input().split(' '))
a = int(math.ceil(float(n * y * 0.01)))
if x >= a:
    print(0)
else:
    print(a - x)