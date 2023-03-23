def remDuplicates(lst):
    lst = set(lst)
    lst = list(lst)
    return lst

lst = [1, 2, 3, 4, 4, 5, 6, 6, 7]

print(remDuplicates(lst))