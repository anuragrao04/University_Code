def stringFunction(st1, st2):
    if len(st1) > len(st2):
        return st1
    elif len(st1) < len(st2):
        return st2
    else:
        return st1 + " " + st2

st1 = "abcd"
st2 = "ABCD"

print(stringFunction(st1, st2))
