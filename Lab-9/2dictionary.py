gDict =  {'apple':'fruit', 'cat':'mammal', 'beans':'veg', 'dog':'mammal', 'mango':'fruit'} 
cDict = {}
for i in gDict:
    if gDict[i] in cDict: cDict[gDict[i]].append(i)
    else: cDict[gDict[i]] = [i]
print(cDict)
