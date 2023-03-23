numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

odd_numbers = filter(lambda x: x % 2 == 1, numbers)

print(list(odd_numbers))
