for i in range(2, 11):
    for j in range(1, 11):
        print(i, "x", j, "=" , str(i*j))
    print("\n\n")


# while 
i = 2
while (i<11):
    j = 1
    while (j<11):
        print(i, "x", j, "=" , i*j)
        j += 1
    i+=1
    print("\n")    