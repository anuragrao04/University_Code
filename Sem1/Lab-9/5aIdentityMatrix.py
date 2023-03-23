#a
o = int(input("order: "))

for i in range(o):
    for j in range(o):
        if i == j: print('1', end = ' ')
        else: print('0', end = ' ')
    print()


#b
gMatrix = eval(input("Enter matrix as nested list: "))

# upper matrix
for i in range(len(gMatrix)):
    for j in range(len(gMatrix[i])):
        if i <= j: print(gMatrix[i][j], end = ' ')
        else: print('0', end = ' ')
    print()

print('\n\n')

# lower matrix
for i in range(len(gMatrix)):
    for j in range(len(gMatrix[i])):
        if i >= j: print(gMatrix[i][j], end = ' ')
        else: print('0', end = ' ')
    print()
