import random
a = ['karnataka', 'tamilnad', 'karnataka', 'karnataka', 'karnataka', 'tamilnad', 'kerala']
b = ['mysore', 'chennai', 'hassan', 'shimoga', 'madurai']

def weirdDictionary(a, b):
    retDict = {}
    for i in a:
        if i in retDict:
            retDict[i].append(random.choice(b))

        else:
            retDict[i] = [random.choice(b)]

    return retDict


print(weirdDictionary(a, b))
