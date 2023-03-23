n = int(input())
l = []

i = 1

while i<= n:
    if n%i == 0: l.append(i)
    i += 1

print("factors are: ", l)

if len(l) == 2: print("Prime Number")
else: print("Not Prime Number")