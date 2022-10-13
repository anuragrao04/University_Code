l = [10, 20, 25, 35, 40]
l_out = []

for i in range(len(l)-1):
    l_out.append(l[i+1] - l[i])

print(l_out)