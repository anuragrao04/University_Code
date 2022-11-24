with open("6.txt") as f:
    words = f.read().split()
with open("7.txt", "w") as f:
    for i in words: f.write(i+'\n')
