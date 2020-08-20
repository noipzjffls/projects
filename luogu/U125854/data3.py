from cyaron import *
cards = ['', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'joker', 'JOKER']
test_data = IO(file_prefix="poker", data_id=2)
maxn1, maxn2 = [4 for j in range(16)], [4 for j in range(16)]
maxn1[14], maxn1[15], maxn2[14], maxn2[15] = 1, 1, 1, 1
la = randint(1, 54)
lb = randint(1, 54)
s = ''
for j in range(la):
    x = randint(1, 15)
    while maxn1[x] == 0: x = randint(1, 15)
    maxn1[x] -= 1
    s += cards[x]
    if j != la - 1: s += ' '
test_data.input_writeln(s)
s = ''
for j in range(lb):
    x = randint(1, 15)
    while maxn2[x] == 0: x = randint(1, 15)
    maxn2[x] -= 1
    s += cards[x]
    if j != lb - 1: s += ' '
test_data.input_writeln(s)
test_data.output_gen("./std")