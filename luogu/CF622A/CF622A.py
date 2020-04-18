n = int(input())
s = i = last = 0
while True:
    i += 1
    last = s
    s += i
    if s >= n:
        break
print(n - last)