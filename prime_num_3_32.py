p=[]
for i in range(3,32):
    for j in range(2,i//2 + 1):
        if i%j==0:
            break
    else:
        p.append(i)
print(p)

