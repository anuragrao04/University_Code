l = ["pes", "pesit", "pesu"]

print(list(map(str.upper, filter(lambda x: len(x)>3, l))))


