n = int(input())
tot = i = 0
num = list(map(int, input().split()))
for i in range(len(num)):
    tot += num[i]
print(float(tot / n))