l = eval(input("Enter List: "))
r = eval(input("Enter element to remove: "))

for i in range(l.count(r)): l.remove(r)
print(l)