import sys
k, l = int(input()), int(input())
n = 1
while True:
    s = k ** n
    if s > l:
        break
    if s == l:
        print('YES')
        print(n - 1)
        sys.exit()
    n += 1
print('NO')