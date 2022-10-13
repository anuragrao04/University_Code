a = int(input("a: "))
b = int(input("b: "))
c = int(input("c: "))


d = (b**2) - (4*a*c)

if d < 0:
    print("No Solutions")
else: 
    sol1 = (-b-((d)**0.5))/(2*a)
    sol2 = (-b+((d)**0.5))/(2*a)

    print("Solutions: ", sol1, "&", sol2)