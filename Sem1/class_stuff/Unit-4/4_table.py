n = int(input("Number: "))


for line in map(lambda i: f"{n} x {i} = {n*i}", range(1, 11)):
    print(line)



