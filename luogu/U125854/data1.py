from cyaron import *
cards = ['', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'joker', 'JOKER']
test_data = IO(file_prefix="poker", data_id=0)
test_data.input_writeln(cards[randint(1, 15)])
test_data.input_writeln(cards[randint(1, 15)])
test_data.output_gen("./std")