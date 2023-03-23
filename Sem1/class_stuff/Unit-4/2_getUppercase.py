givenStringList = ["hello", "he", "abcde", "oooooooo"]

# TRADITIONAL APPROACH
# def getUppercase(l):
#     returnList=  []
#     for i in l:
#         returnList.append(i.upper())
#     return returnList

# print(getUppercase(givenStringList))


# MAP FUNCTION:
print(list(map(str.upper, givenStringList)))
