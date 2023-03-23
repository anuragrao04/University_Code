import random
with open("2.txt", "r") as f:
    st = f.readlines()

print(random.choices(st))




