n = int(input())
s = ['' for i in range(1, 55)]
def check(a, idx):
    for i in range(1, n + 1):
        if i == idx:
            continue
        if s[i][0: len(a)] == a:
            return False
    return True
for i in range(1, n + 1):
    s[i] = str(input())
for i in range(1, n + 1):
    for j in range(1, len(s[i]) + 1):
        sub = s[i][0: j]
        if check(sub, i):
            print(sub)
            break