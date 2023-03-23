a = int(input("a: "))
b = int(input("b: "))
c = int(input("c: "))
d = int(input("d: "))

di1 = int(input("diag1: "))
di2 = int(input("diag2: "))

if di1 == di2:
    if a == b == c == d:
        print("Square")
    else: print("Rectangle")

else: 
    if a == b == c == d:
        print("Rhombus")
    else: print("Parallelogram")