def firstLastChar(l):
    return [i[0] + i[-1] for i in l if len(i) >= 3]
