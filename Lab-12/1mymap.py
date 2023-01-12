def mymap(callable, iterable):
	retList = []
	for i in iterable: retList.append(callable(i))
	return retList


#a
n = int(input())
print(mymap(lambda x: x**2, range(1,n+1,2)))

#b
l = ["do", "eat", "go"]
print(mymap(lambda x: x+'ing', l))

#c
print(mymap(lambda x: (x, len(x)), l))

