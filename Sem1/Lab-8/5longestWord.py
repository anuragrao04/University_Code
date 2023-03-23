with open("1.txt", 'r') as f:
    words = f.read().split()
print(max(words, key=len))