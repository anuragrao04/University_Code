a = [1, 2, 3, 4, 5]
b = [3, 4, 5, 6, 7]

diff = filter(lambda x: x not in b, a)
print(list(diff))
