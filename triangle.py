a,b,c = int(input("a: ")), int(input("b: ")), int(input("c: "))
s = (a+b+c)/2
area = (s*(s-a)*(s-b)*(s-c))**0.5
print("area: ", area)