def filterPositive(numbers):
    return filter(lambda x: x > 0, numbers)


numbers = [-1, 2, -3, 4, -5, 6]
print(list(filterPositive(numbers)))
