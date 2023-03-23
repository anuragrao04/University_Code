l = [1,3,4,5,6,8,10]
i = 0
while i < len(l):
    if l[i] %2 == 0:
        print("Even found at index", i)
        break
    i += 1
else: print("No even element")
