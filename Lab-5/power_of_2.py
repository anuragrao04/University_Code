import math

n = int(input())

if n == 0: print("Not a power of 2")

else:
    n = math.log2(n)
    if n%1 == 0: print("Power of 2")
    else: print("Not a power of 2")