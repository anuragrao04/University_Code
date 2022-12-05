def stringFunction(st):

    lowercase = 0
    uppercase = 0
    for i in st:
        if i.isupper():
            uppercase += 1 
        elif i.islower(): 
            lowercase += 1
    return {"uppercase": uppercase, "lowercase": lowercase}

st = "abcd ABCD"

print(stringFunction(st))
