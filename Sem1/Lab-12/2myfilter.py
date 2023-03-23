def myfilter(callable, iterable):
	retList = []
	for i in iterable:
		if callable(i): retList.append(i)
	return retList


#a
l = ["hello", "1hello", "2hellooo", "hi"]
print(myfilter(lambda x: not x[0].isdigit(), l))

#b
print(myfilter(lambda x: len(x)>6, l))

#c
print(myfilter(lambda x: x[-3:] == "llo", l))
