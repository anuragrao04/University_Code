def myreduce(func, iterable):
    returnNum = iterable[0]
    for i in range(1, len(iterable)):
        returnNum = func(returnNum, iterable[i])
    return returnNum

#a
lon = [1,2,4,3,1,8,5,6]
print(myreduce(lambda x,y: x if x>y else y, lon))

#b
loi = [1,2,3,4,5,6]
print(myreduce(int.__add__, loi))

