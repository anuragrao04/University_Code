t = eval(input())
s = set()

for i in t:
	if t.count(i) > 1: s.add(i)
print(s)

