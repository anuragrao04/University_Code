string = "how much wood would a wood chuck chuck if a wood chuck could chuck wood"
string = string.split()

freqDic = {}

for i in string:
    if i in freqDic: freqDic[i] += 1
    else: freqDic[i] = 1

print(freqDic)