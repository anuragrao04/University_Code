a = int(input("a: "))
b = int(input("b: "))
c = int(input("c: ")) 

if (a + b <= c) or (a + c <= b) or (b + c <= a):
    print("Invalid")
else: 
    s = (a+b+c)/2
    a = (s*(s-a)*(s-b)*(s-c))**0.5
    print("Area:", a)
    


