l = eval(input("List: "))
counter = 0

for i in range(len(l)):
	for j in range(len(l[0])):
		if i==j: counter += l[i][j]

print(counter)
