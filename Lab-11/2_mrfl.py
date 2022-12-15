#a
st = ["hello", "1hello", "2hello", "hi"]
print(list(filter(lambda x: not x[0].isdigit(), st)))

#b
import functools
lon = [1,2,4,3,1,8,5,6]
print(functools.reduce(lambda x,y: x if x>y else y, lon))

#c
lot = [(1,1), (4, 2), (10, 5), (5, 2), (3, 2)]
print(list(filter(lambda x: x[0] % x[1] == 0, lot)))
