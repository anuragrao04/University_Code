from functools import reduce
nums = range(int(input()), 1, -1)
print(reduce(lambda x,y: x*y, nums))