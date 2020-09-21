from random import sample

sorteados = sample(range(0, 100000), 100000)

with open("arquivo.txt", "w" ) as f:
    for each in sorteados:

        f.write(str(each) + "\n")
