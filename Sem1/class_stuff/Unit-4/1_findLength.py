givenStringList = ["hello", "he", "abcde", "oooooooo"]

# TRADITIONAL APPROACH
# def getLengthList(l):
#     returnList=  []
#     for i in l:
#         returnList.append(len(i))
#     return returnList

# print(getLengthList(givenStringList))


# MAP FUNCTION
print(list(map(len, givenStringList)))
