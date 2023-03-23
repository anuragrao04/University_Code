def oddAndPalindromic(x, y):
    retList = []
    for i in range(x, y+1):
        if i%11 == 0: retList.append(i)
    return retList