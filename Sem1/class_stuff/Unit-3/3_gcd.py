def findGCD(a, b):
    if a == b: 
        return a
    elif a < b:
        return findGCD(b, a)
    else:
        return findGCD(b, a - b)

print("GCD:", findGCD(7, 10))



