
leven, lodd = list(), list()
for i in range(5):
    if i%2 == 0: leven.append(i)
    else: lodd.append(i)


print("Even: ", leven)
print("Odd: ", lodd)

lsum = leven+lodd

sum = 0

for element in lsum: sum+=element

print("Sum: ", sum)

