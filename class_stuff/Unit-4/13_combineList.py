l1 = [1,2,3]
l2= [1,3,2]

print([(i,j) for i in l1 for j in l2 if i != j])
# This is a nested for loop, the 'j' loop is inside the 'i' loop
