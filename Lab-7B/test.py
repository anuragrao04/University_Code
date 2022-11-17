lst = [9, 2, 3, 1, 6, 6]
freq = {}
for i in lst:
    if i not in freq and freq == {}:
        freq[i] = 1
    else:
        try:
            freq.pop(i)
        except: pass
print(list(freq.keys())[0])
    


    
