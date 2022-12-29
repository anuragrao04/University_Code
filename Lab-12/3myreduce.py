def myreduce(callable, iterable):
	ret = iterable[0]
	for i in range(1, len(iterable)):
		ret = callable(ret, iterable[i])
	return ret

#a
name = "Anurag Rao Hello Something"
print(myreduce(lambda x,y: x+y[0], [name[0]] + name.split()[1:]))

#b
n = int(input("n: "))
print(myreduce(int.__add__, range(1, n+1)))

#c
print(myreduce(lambda x,y:x*y, range(1, n+1)))
