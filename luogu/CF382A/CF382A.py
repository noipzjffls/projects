import sys
def find(x, y):
    for i in range(len(x)):
        if x[i] == y[0]:
            return i
def substr(x, y, z):
    a = ''
    for i in range(y, z):
        a += x[i]
    return a
def erase(x):
    a = ''
    for i in range(1, len(x)):
        a += x[i]
    return a
s = str(input())
t = str(input())
line = find(s, '|')
sa = substr(s, 0, line)
sb = substr(s, line + 1, len(s))
flag = False
if len(sa) < len(sb):
    sa, sb = sb, sa
    flag = True
if len(sb) + len(t) < len(sa):
    print('Impossible')
    sys.exit()
while len(t) > 0 and len(sa) != len(sb):
    sb += t[0]
    t = erase(t)
if len(t) & 1:
    print('Impossible')
    sys.exit()
for i in range(len(t)):
    if i & 1:
        sa += t[i]
    else:
        sb += t[i]
if flag:
    sa, sb = sb, sa
print(sa, end = '|')
print(sb)