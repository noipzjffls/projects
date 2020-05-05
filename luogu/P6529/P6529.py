import sys
s = str(input())
a = {'P': 0, 'K': 1, 'H': 2, 'T': 3}
card = [[False for i in range(14)] for j in range(4)]
for i in range(len(s)):
    if i % 3 == 2:
        x = a[s[i - 2]]
        y = int(s[i - 1], base = 0) * 10 + int(s[i], base = 0)
        if card[x][y] == True:
            print('GRESKA')
            sys.exit()
        else:
            card[x][y] = True
for i in range(4):
    cnt = 0
    for j in range(14):
        cnt+=int(card[i][j])
    print(13 - cnt, end=' ')