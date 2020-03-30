a = 0
b = int(input())
for i in range(0, b):
    x = str(input())
    c = int(input())
    if x == 'gift':
        a = a + c
    else:
        a = a - c
print(a)