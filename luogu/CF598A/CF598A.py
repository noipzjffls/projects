n = int(input())
for times in range(n):
    a = int(input())
    s = int((1 + a) * a / 2)
    i = 0
    while True:
        if 2 ** i <= a:
            s -= 2 ** i * 2
            i += 1
        else:
            break
    print(s)