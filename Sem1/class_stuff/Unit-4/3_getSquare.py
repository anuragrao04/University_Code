givenList = [1, 2, 3, 4, 5]

# TRADITIONAL APPROACH
# def getSquare(l):
#     returnList=  []
#     for i in l:
#         returnList.append(i**2)
#     return returnList

# print(getSquare(givenList))

# MAP FUNCTION:

print(list(map(lambda x: x**2, givenList)))
