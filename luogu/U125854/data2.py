from cyaron import *
cards = ['', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'joker', 'JOKER']
test_data = IO(file_prefix="poker", data_id=1)
la = randint(1, 15)
lb = 15 - la
vis = [False for i in range(16)]
s = ''
for j in range(la):
    x = randint(1, 15)
    while vis[x]: x = randint(1, 15)
    vis[x] = True
    s += cards[x]
    if j != la - 1: s += ' '
test_data.input_writeln(s)
s = ''
for j in range(lb):
    x = randint(1, 15)
    while vis[x]: x = randint(1, 15)
    vis[x] = True
    s += cards[x]
    if j != lb - 1: s += ' '
test_data.input_writeln(s)
test_data.output_gen("./std")