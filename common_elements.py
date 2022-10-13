l1 = [1,1,3,4,6,7]

l2 = [1,4,6,3,8,10,1,3,6]

res = set()

for i in l1:
    if i in l2: res.add(i)

print(res)