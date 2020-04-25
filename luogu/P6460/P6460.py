s = ['', '']
hh = [0, 0]
mm = [0, 0]
ss = [0, 0]
t = [0, 0]
ans = [0, 0, 0]
first = False
for i in range(len(s)):
    s[i] = str(input())
    hh[i] = int(s[i][0], base = 0) * 10 + int(s[i][1], base = 0)
    mm[i] = int(s[i][3], base = 0) * 10 + int(s[i][4], base = 0)
    ss[i] = int(s[i][6], base = 0) * 10 + int(s[i][7], base = 0)
    t[i] = 3600 * hh[i] + 60 * mm[i] + ss[i]
if s[0] == s[1]:
    print('24:00:00')
else:
    if t[1] < t[0]:
        t[1] += 86400
    dif = t[1] - t[0]
    ans[0] = dif // 3600
    ans[1] = dif // 60 % 60
    ans[2] = dif % 60
    for i in ans:
        if first == True:
            print(':', end='')
        if i < 10:
            print('0', end='')
        print(i, end='')
        first = True