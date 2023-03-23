a = int(input("a: "))
b = int(input("b: "))
c = int(input("c: "))


d = (b**2) - (4*a*c)
if d < 0:
    print("The solutions are imaginary")
elif d>0: 
    sol1 = (-b-((d)**0.5))/(2*a)
    sol2 = (-b+((d)**0.5))/(2*a)
    print("The roots for the equation are:",sol1,"and",sol2)
else:
    print("The roots are equal and the roots are:",-b/(2*a))
