d = int(input("Dimension: "))
l = []
for i in range(d):
    for j in range(d):
        if i == j: l.append('1')
        else: l.append('0')
    l.append('\n')

for i in l: 
    print(i, end = ' ') if i != '\n' else print(i, end = '')

