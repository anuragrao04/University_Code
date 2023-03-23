l1 = [1, 2, 3, 4, 5, 6]
l2 = [2, 3]


# finding l2 - l1
print(list(filter(lambda x: x not in l2, l1)))
