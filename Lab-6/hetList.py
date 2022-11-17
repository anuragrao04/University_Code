l = eval(input("Enter heteregenous list: "))
lfloat=  []
lint = []
lstring = []
lbool = []

for i in l:
    if type(i) is bool: lbool.append(i)
    elif type(i) is str: lstring.append(i)
    elif type(i) is int: lint.append(i)
    elif type(i) is float: lfloat.append(i)
    else: print("AAAAAAAAAAHHHHHHH")


print("float: ", lfloat)
print("int: ", lint)
print("string: ", lstring)
print("Boolean: ", lbool)