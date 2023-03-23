from functools import reduce

num = [8,1,2,3,4,5,6,7]

print(reduce(lambda x,y: x if x>y else y, num))

