import math
import operator
def is_square(x): return math.sqrt(x) % 1 == 0
def is_even(x): return x % 2 == 0

#a 
n = int(input('n: '))
print("perfect sqare") if is_square(n) else print("not perfect square")


#b
se = []
ens = []

for i in range(1, n+1):
    if is_even(i):
        if is_square(i): se.append(i)
        else: ens.append(i)

print("square and even: ", se)
print("even and not square: ", ens)

